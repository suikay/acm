#include<stdio.h>
#define M 100010
#define MulIn 2147483647
#define __int64 long long
struct TNode{
    int left,right,in;
      __int64 sum;
};
TNode t[M*3];

int num[M];

int Construct(int pos,int l,int r)
{
    t[pos].left = l;
      t[pos].right = r;
        t[pos].in = 0;
          if(l == r){
                t[pos].sum = num[l];
                    return num[l];
                      }
            t[pos].sum = Construct(pos*2,l,(l+r)>>1) + Construct(pos*2+1,((l+r)>>1)+1,r);
              return t[pos].sum;
}

void Insert(int pos,int l,int r,int interal)
{
    t[pos].sum += (r-l+1)*interal;
      if(t[pos].left == l && r == t[pos].right && t[pos].in != MulIn){
            t[pos].in += interal;
                return ;
                  }
        int mid = (t[pos].left+t[pos].right)>>1;
          if(t[pos].in != MulIn){
                t[pos*2].in = t[pos].in;
                    t[pos*2+1].in = t[pos].in;
                        t[pos].in = MulIn;
                          }
            if(l > mid)   {
                  Insert(pos*2+1,l,r,interal);
                      return;
                        }
              if(r <= mid)  {
                    Insert(pos*2,l,r,interal);
                        return;
                          }
                Insert(pos*2,l,mid,interal);
                  Insert(pos*2+1,mid+1,r,interal);
                    return ;
}

__int64 Cal(int pos,int l,int r){
    __int64 res = 0;
      if(l == t[pos].left && r == t[pos].right )
            return t[pos].sum;
        if(t[pos].in != MulIn)
              res = t[pos].in*(r - l + 1);
          int mid = (t[pos].left+t[pos].right)>>1;
            if(l > mid)
                  return res+Cal(pos*2+1,l,r);
              if(r <= mid)
                    return res + Cal(pos*2,l,r);
                return res + Cal(pos*2,l,mid)+Cal(pos*2+1,mid+1,r);
}

int main()
{
    int n,q,a,b,c;
      char op;
        scanf("%d%d",&n,&q);
          for(int i = 1; i <= n; i++)
                scanf("%d",&num[i]);
            Construct(1,1,n);
              getchar();
                for(int i = 0; i < q; i++)    {
                      scanf("%c",&op);
                          if(op == 'Q'){
                                  scanf("%d%d",&a,&b);
                                        printf("%lld\n",Cal(1,a,b));
                                            }
                              else
                                    {
                                            scanf("%d%d%d",&a,&b,&c);
                                                  Insert(1,a,b,c);
                                                      }
                                  getchar();
                                    }
                  return 0;
}


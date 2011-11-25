#include<memory.h>
#include<stdio.h>
#define L 100010
#define C 35
#define NoCol 0
#define MulCol -1

struct TNode
{
	int left,right;
	int col;
};

TNode tree[L*10];

bool col[35];

void construct(int pos,int l,int r)
{
	tree[pos].left = l;
	tree[pos].right = r;
	tree[pos].col = NoCol;
	if(l == r)
		return;
	construct(2*pos,l,(l+r)>>1);
	construct(2*pos+1,((l+r)>>1)+1,r);
}

void insert(int pos,int l,int r,int c)
{
	if(tree[pos].col == c)
		return ;
	if(l==tree[pos].left && r==tree[pos].right)	{
		tree[pos].col = c;
		return ;
	}
	if(tree[pos].col != MulCol)	{
		tree[pos*2].col = tree[pos].col;
		tree[pos*2+1].col = tree[pos].col;
	}
	int mid = (tree[pos].left+tree[pos].right)/2;
	tree[pos].col = MulCol;
	if(r <= mid)	{
		insert(pos*2,l,r,c);
		return ;
	}
	if(l > mid)	{
		insert(pos*2+1,l,r,c);
		return;
	}
	insert(pos*2,l,mid,c);
	insert(pos*2+1,mid+1,r,c);
	return;
}

void calculate(int pos,int l,int r)
{
	if(tree[pos].col != MulCol)	{
		col[tree[pos].col] = true;
		return ;
	}
	int mid = (tree[pos].left + tree[pos].right)>>1;
	if(r <= mid)	{
		calculate(pos*2,l,r);
		return;
	}
	if( l > mid)	{
		calculate(pos*2+1,l,r);
		return ;
	}
	calculate(pos*2,l,mid);
	calculate(pos*2+1,mid+1,r);
	return;
}

int main()
{
	int l,t,o;
	int a,b,c;
	int tmp,res;
	char op;
	scanf("%d%d%d\n",&l,&t,&o);
	construct(1,1,L);
	for(int i = 0; i < o; i++)
	{
		scanf("%c%d%d",&op,&a,&b);
		if(a > b)	{
			tmp = b;
			b = a;
			a = tmp;
		}
		if(op == 'C')	{
			scanf("%d\n",&c);
			insert(1,a,b,c);
		}
		else	{
			getchar();
			memset(col,NoCol,sizeof(col));
			calculate(1,a,b);
			res = 0;
			for(int i = 0; i < 31; i++)
				if(col[i])
					res++;
			printf("%d\n",res);
		}
	}
	return 0;
}

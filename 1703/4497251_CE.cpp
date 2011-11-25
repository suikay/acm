#include<stdio.h>
#include<string.h>
#include<math.h>
int par[100001],pov[100001];

int find(int a)
{
    while(par[a]!=-1)
        a=par[a];
    return a;
}

int cal(int a)
{
    int t=0;
    while(par[a]!=-1)
    {
        t+=pov[a];
        a=par[a];
    }
    return t;
}

void unions(int a,int b)
{
    int p=find(a);
    int q=find(b);
    if(cal(a)<cal(b))
    {
        par[p]=q;
        pov[p]=(cal(a)-cal(b)+1)%2;
    }
    else
    {
        par[q]=p;
        pov[q]=(cal(a)-cal(b)+1)%2;
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    
    int cases;
    int n,m,a,b;
    char c;
    scanf("%d",&cases);
    while(cases--)
    {
        memset(par,-1,sizeof(par));
        memset(pov,0,sizeof(pov));
        scanf("%d%d",&n,&m);
        while(m--)
        {
            while(1)
            {
                c=getchar();
                if(c==''D''||c==''A'')
                    break;
            }
            scanf("%d%d",&a,&b);
            if(c==''D'')
            {
                
                if(find(a)!=find(b))
                    unions(a,b);
            }
            else if(c==''A'')
            {
                if(find(a)!=find(b))
                    printf("Not sure yet.\n");
                else if((cal(a)-cal(b))%2==0)
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }
        }
    }
    return 1;
}


文章出处：http://www.diybl.com/course/3_program/c++/cppsl/200855/113021.html
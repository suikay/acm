#include <stdio.h> 
#include <string.h> 
#include <algorithm> 
typedef struct 
{ 
    int u; 
    int v; 
    int w; 
}edge; 
edge e[5055]; 
int parent[105]; 
int Find(int e) 
{ 
    int eP=e; 
    while(parent[eP]>=0) 
        eP=parent[eP]; 
     return eP;
} 

void Union(int i,int j) 
{ 
    int p1=Find(i); 
    int p2=Find(j); 
    if(p1==p2) 
        return; 
    if(parent[p1]<parent[p2]) 
    { 
        parent[p1]+=parent[p2]; 
        parent[p2]=p1; 
    } 
    else 
    { 
        parent[p2]+=parent[p1]; 
        parent[p1]=p2; 
    } 
} 

int cmp(const void *p1,const void *p2) 
{ 
    return ((edge *)p1)->w - ((edge *)p2)->w; 
} 

void KruskalMinTree(int N,int M) 
{ 
    int sum=0; 
    int i; 
    qsort(e+1,M,sizeof(edge),cmp); 
    for(i=1;i<=M;i++) 
    { 
        int p1=Find(e[i].u); 
        int p2=Find(e[i].v); 
        if(p1!=p2) 
        { 
            Union(p1,p2); 
            sum+=e[i].w; 
        } 
    } 
    printf("%d\n",sum); 
} 

int main() 
{ 
    int N,Q; 
    int p1,p2; 
    int i,j,k=1; 
    int matrix[105][105]; 

    while(scanf("%d",&N)!=EOF) 
    { 
        memset(parent,-1,sizeof(int)*(N+1)); 
        for(i=1;i<=N;i++) 
            for(j=1;j<=N;j++) 
                scanf("%d",&matrix[i][j]); 
        for(i=1;i<=N;i++) 
            for(j=i+1;j<=N;j++) 
            { 
                e[k].u=i; 
                e[k].v=j; 
                e[k].w=matrix[i][j]; 
                k++; 
            } 
        scanf("%d",&Q); 
        for(i=1;i<=Q;i++) 
        { 
            scanf("%d%d",&p1,&p2); 
            Union(p1,p2); 
        } 
        KruskalMinTree(N,N*(N-1)/2); 
    } 
    return 0; 
} 

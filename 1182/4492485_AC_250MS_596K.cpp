#include <stdio.h> 
int parent[50005]; 
int relation[50005]; 
// 对路径进行压缩的同时把关系数找出 
int FindParent(int x,int &rx) 
{ 
    if( parent[x]) { 
        int xParent = FindParent(parent[x],relation[parent[x]]); 
        rx = ( relation[parent[x]] + rx) % 3; 
        return parent[x] = xParent; 
    } 
    return x; 
} 
// 注意两者对relation运算之间的差别 
void MergeSet(int r,int x,int y) 
{ 
    if( x > y) { 
        parent[y] = x; 
        relation[y] = (-r + 3)% 3; 
    } 
    else { 
        parent[x] = y; 
        relation[x] = (r + 3)% 3; 
    } 
} 
int main() 
{ 
    int n, d, k; 
    int x, y, t1, t2; 
    int lies = 0; 
    scanf("%d%d",&n,&k); 
    for( int i = 0; i < k; i++) { 
        scanf("%d%d%d",&d,&x,&y); 
        if( x > n || y > n) { 
            lies++; 
            continue; 
        } 
        t1 = FindParent(x,relation[x]); 
        t2 = FindParent(y,relation[y]); 
        // 两个都在同一子集里 
        if( t1 == t2) { 
            if( (relation[x] - relation[y] + 3) % 3 != ( d - 1 ) ) 
                lies++; 
            continue; 
        } 
        else 
            MergeSet(- relation[x] + relation[y] + d - 1,t1,t2); 
    } 
    printf("%d\n",lies); 
}

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct {
	int x;
	int y;
	int lenght;
} pipeType;
pipeType pipe[15005];
int parent[1005];
struct pt_cmp
{
bool operator () ( const pipeType &a, const pipeType &b ) const 
{
    return a.lenght < b.lenght;
}
};

int FindParent(int x)
{
	if( parent[x] != x) 
		parent[x] = FindParent(parent[x]);
	return parent[x];
}
void MergeSet(int x,int y)
{
	if( x > y)
		parent[y] = x;
	else
		parent[x] = y;
}
int main()
{
	int n,d,count = 0;
	int t1,t2, i;
	int max, sum = 0;
	scanf("%d%d",&n,&d);
	for( i = 1; i <= n; i++)
		parent[i] = i;
	for( i = 0; i < d; i++)
		scanf("%d%d%d",&(pipe[i].x), &(pipe[i].y), &(pipe[i].lenght));
	sort(pipe,pipe + d,pt_cmp());
	for( i = 0; i < d && count < (n - 1); i++) {
		t1 = FindParent(pipe[i].x);
		t2 = FindParent(pipe[i].y);
		if( t1 != t2)  {
			count++;
			MergeSet(t1,t2);
		}
		max = pipe[i].lenght;
	}
	printf("%d\n%d\n",max,i);
	for(int j = 0; j < i ; j++)
		if(pipe[j].x != pipe[j].y)
			printf("%d %d\n",pipe[j].x,pipe[j].y);
}
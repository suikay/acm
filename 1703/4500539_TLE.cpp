#include <stdio.h>
#include <memory.h>
unsigned int parent[100001];
char rela[100001];
int rank[100001];
/*
int FindParent(int x)
{
	if(parent[x]) {
		rela[x] = (rela[x] + rela[parent[x]] ) & 1;
		parent[x] = FindParent(parent[x]);
		return parent[x];
	}
	else
		return x;
}
*/
int FindParent(int x)
{
	int px = x,temp;
	while(parent[x])
		x = parent[x];
	while(px != x) {
		temp = parent[px];
		parent[px] = x;
		px = temp;
	}
	return x;
}
int cal(int x)
{
	int re = 0;
	while(parent[x]) {
		re = ( re != rela[x]);
		x = parent[x];
	}
	return re;
}
void MergeSet(int x,int y)
{
	int relation = (rela[x] == rela[y] );
	x = FindParent(x);
	y = FindParent(y);
	if( x == y)
		return ;
	if( parent[x] < parent[y]) {
		parent[y] = x;
		rela[y] = relation;
	}
	else 
		if(parent[x] == parent[y]){
			parent[x] = y;
			rela[x] = relation;
			parent[y] --;
		}
		else
		{
			parent[x] = y;
			rela[x] = relation;
		}
}
int main()
{
	int n,m,t;
	int x,y;
	char s[20];
	scanf("%d",&t);
	for( int i = 0; i < t; i++) {
		memset(parent,0,100001 * sizeof(int));
		memset(rela,0,100001 * sizeof(bool));
		scanf("%d%d\n",&n,&m);
		for( int j = 0; j < m; j++) {
			gets(s);
			if(s[0] == 'A') {
				sscanf(s,"A %d%d",&x,&y);				
				int re = 0;
				while(parent[x]) {
					re = ( re != rela[x]);
					x = parent[x];
				}
				int rf = 0;
				while(parent[y]) {
					rf = (rf != rela[y]);
					y = parent[y];
				}
				if(FindParent(x) == FindParent(y))
					if( re == rf)
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
			else {
				sscanf(s,"D %d%d",&x,&y);
				int relation = (rela[x] == rela[y] );
				x = FindParent(x);
				y = FindParent(y);
				if( rank[x] > rank[y]) {
					parent[y] = x;
					rela[y] = relation;
					rank[x]++;
				}
				else {
					parent[x] = y;
					rela[x] = relation;
					rank[y]++;
				}
			}
		}
	}
}
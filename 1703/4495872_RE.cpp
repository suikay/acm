#include <stdio.h>
#include <memory.h>
unsigned short parent[100001];
bool rela[100001];
int FindParent(int x)
{
	if(parent[x]) {
		rela[x] = (rela[x] + rela[parent[x]] ) % 2;
		parent[x] = FindParent(parent[x]);
		return parent[x];
	}
	else
		return x;
}
void MergeSet(int x,int y)
{
	int relation = rela[x] + rela[y];
	x = FindParent(x);
	y = FindParent(y);
	if( x > y) {
		parent[y] = x;
		rela[y] = (relation + 1) % 2;
	}
	else {
		parent[x] = y;
		rela[x] = (relation + 1) % 2;
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
				if(FindParent(x) == FindParent(y))
					if( rela[x] == rela[y] )
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
			else {
				sscanf(s,"D %d%d",&x,&y);
				MergeSet(x,y);
			}
		}
	}
}
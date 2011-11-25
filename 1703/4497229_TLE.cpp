#include <stdio.h>
#include <memory.h>
unsigned int parent[100001];
bool rela[100001];
/*
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
*/
int main()
{
	int n,m,t;
	int x,y;
	bool bx,by;
	char s[20];
	int t1,t2,yy,xx,xxx,yyy;
	scanf("%d",&t);
	for( int i = 0; i < t; i++) {
		memset(parent,0,100001 * sizeof(int));
		memset(rela,0,100001 * sizeof(bool));
		scanf("%d%d\n",&n,&m);
		for( int j = 0; j < m; j++) {
			gets(s);
			if(s[0] == 'A') {
				sscanf(s,"A %d%d",&x,&y);
				bx = 0;
				by = 0;
				t1 = xxx  =x;
				t2 = yyy = y;
				while(parent[t1]) {
					bx = (bx != rela[t1]);
					t1 = parent[t1];
				}
				while(parent[x]) {
					rela[x] = bx;
					bx = (rela[parent[x]] != bx);
					xx = parent[x];
					parent[x] = t1;
					x = xx;
				}
				while(parent[t2]) {
					by = ( by != rela[y]);
					t2 = parent[t2];
				}
				while(parent[y]) {
					rela[y] = by;
					by = (rela[parent[y]] != by);
					yy = parent[y];
					parent[y] = t2;
					y = yy;
				}
				if(t1 == t2)
					if( rela[xxx] == rela[yyy])
						printf("In the same gang.\n");
					else
						printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			}
			else {
				sscanf(s,"D %d%d",&x,&y);
				bx = rela[x];
				by = rela[y];
				while(parent[x]) {
					x = parent[x];
					bx = (bx != rela[x]);
				}
				while(parent[y]) {
					y = parent[y];
					by = ( by != rela[y]);
				}
				if( x > y) {
					parent[y] = x;
					rela[y] =( bx == by);
				}
				else{
					parent[x] = y;
					rela[x] =(bx == by);
				}
			}
		}
	}
}
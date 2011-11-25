#include <stdio.h>
#define CONNECT(x1,y1,x2,y2,max) (((x1 - x2) * (x1 - x2) +( y1 - y2)*(y1 - y2)) <= max * max)
typedef struct data{
	int x;
	int y;
}data;
int FindParent(int *parent,int a)
{
	while(parent[a] != a)
		a = parent[a];
	return a;
}
void MergeSet(int *parent,int a, int b)
{
	int t1 = FindParent(parent,a);
	int t2 = FindParent(parent,b);
	if( t1 > t2)
		parent[t2] = t1;
	else
		parent[t1] = t2;
}
int main()
{
	int parent[1005];
	data point[1005];
	int nicePoint[1005],nPcount = 0;
	int t1, t2;
	int n, d;
	char s[20];
	scanf("%d%d",&n,&d);
	for( int i = 1 ;i <= n; i++) {
		parent[i] = i;
		scanf("%d%d\n",&point[i].x, &point[i].y);
	}
	while( gets(s)) {
		if(s[0] == 'O') {
			sscanf(s,"O %d", &t1);
			for( int i = 0; i < nPcount ; i++)
				if(CONNECT(point[nicePoint[i]].x,point[nicePoint[i]].y,point[t1].x,point[t1].y,d))
					MergeSet(parent,nicePoint[i],t1);
			nicePoint[nPcount++] = t1;
		}
		else	{
			sscanf(s,"S %d%d",&t1, &t2);
			if(FindParent(parent,t1) == FindParent(parent,t2))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
}
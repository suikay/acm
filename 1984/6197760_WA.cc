#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int N = 41000;
int parent[N],disn[N],dise[N];
int q[N],top;
int father(int x)
{
	static int nd,ed;
	top = 0;
	while(parent[x] >= 0) 
	{
		q[top++] = x;
		x = parent[x];
	}
	nd = ed = 0;
	while(top--)
	{
		nd += disn[q[top]]; ed += dise[q[top]];
		disn[q[top]] = nd; dise[q[top]] = ed;
		parent[q[top]] = x;
	}
	return x;
}

void merge(int x,int y,int nd,int ed)
{
	int xx,yy;
	xx = father(x); yy = father(y);
	if(xx == yy)
		return;
	//cout << " M " << x << " " << y << endl;
	parent[yy] = xx;
	disn[yy] = disn[x] - disn[y] + nd;
	dise[yy] = dise[x] - dise[y] + ed;
}

void simple(int n)
{
	for(int i = 1; i <= n; i++)
		father(i);
}
char arr[N][20];
struct Query
{
	int a,b,c;
	bool operator<(const Query &y) const{
		return c < y.c;
	}
};
Query query[N];
int main()
{
	int n,m,x,qn;
	int a,b,c;
	char d;
	scanf("%d%d",&n,&m);
	gets(arr[0]);
	memset(parent,-1,sizeof(parent));
	for(int i = 0; i < m; i++)
		gets(arr[i]);
	scanf("%d",&x);
	for(int i = 0; i < x; i++)
		scanf("%d%d%d",&(query[i].a),&(query[i].b),&(query[i].c));
	sort(query,query+x);
	qn = 0;
	for(int i =	1;qn < x && i <= m; i++)
	{
		sscanf(arr[i-1],"%d%d%d %c",&a,&b,&c,&d);
		if(d == 'N')
			merge(a,b,c,0);
		else if(d == 'S')
			merge(a,b,-c,0);
		else if(d == 'E')
			merge(a,b,0,c);
		else
			merge(a,b,0,-c);
		while(query[qn].c == i)
		{
			a = query[qn].a; b = query[qn].b;
			if(father(a) != father(b))
				puts("-1");
			else
				printf("%d\n",abs(disn[a]-disn[b])+abs(dise[a]-dise[b]));
			qn++;
		}
	}

	return 0;
}
/*
7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
5
1 6 1
2 6 6
1 4 4
1 4 3
1 4 3

4 3
1 2 7 W
3 4 6 E
2 3 5 S
5
1 2 1
3 4 2
3 4 2
2 3 3
1 4 3
*/

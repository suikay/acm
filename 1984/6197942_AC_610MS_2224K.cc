/*
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
	parent[yy] = xx;
	disn[yy] = disn[x] - disn[y] + nd;
	dise[yy] = dise[x] - dise[y] + ed;
}
void simple(int n)
{
	for(int i = 1; i <= n; i++)
		father(i);
}
struct Query
{
	int a,b,c;
	bool operator<(const Query &y) const{
		return c < y.c;
	}
	Query(){c = -1;}
};
Query query[N];
int aa[N],bb[N],cc[N];
char dd[N];
int main()
{
	int n,m,x,qn;
	int a,b,c;
	char d;
	scanf("%d%d",&n,&m);
	memset(parent,-1,sizeof(parent));
	for(int i = 0; i < m; i++)
		cin >> aa[i] >> bb[i] >> cc[i] >> dd[i];
	scanf("%d",&x);
	for(int i = 0; i < x; i++)
		cin >> query[i].a >> query[i].b >> query[i].c;
	stable_sort(query,query+x);
	qn = 0;
	for(int i =	1;qn < x && i <= m; i++)
	{
		a = aa[i-1]; b = bb[i-1]; c = cc[i-1]; d = dd[i-1];
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
			else {
				printf("%d\n",abs(disn[a]-disn[b])+abs(dise[a]-dise[b]));
			}
			qn++;
		}
	}

	return 0;
}
/*
7   6
1   6   13 E  
6   3 9 E  
3   5 7 S
4   1 3 N  
2   4 20 W  
4  7 2 S
9
1 6 1
1 4 3
2 6 6
1 6 1
1 4 3
2 6 6
1 6 1
1 4 3
2 6 6

7 6
1 2 10 N
5 6 14 N
2 3 11 E
6 7 15  W
3 4  12 S
4 5 13 E
6
1 7 6
2 7 6
3 7 6
4 7 6
5 7 6
6 7 6

4 3
1 2 4 E
2 3 2 N
3 4 2 W
1
1 4 3

4 3
2 3 1000 E
1 2 1000 E
3 4 1000 E
1
1 4 3
*/
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
//char arr[N][20];
struct Query
{
	int a,b,c;
	bool operator<(const Query &y) const{
		return c < y.c;
	}
	Query(){c = -1;}
};
Query query[N];
int pa[N],pb[N];
int aa[N],bb[N],cc[N];
char dd[N];
int main()
{
	int n,m,x,qn;
	int a,b,c;
	char d;
	scanf("%d%d",&n,&m);
	memset(parent,-1,sizeof(parent));
	for(int i = 0; i < m; i++) {
		cin >> aa[i] >> bb[i] >> cc[i] >> dd[i];
		//gets(arr[i]);
	}
	scanf("%d",&x);
	for(int i = 0; i < x; i++)
		cin >> query[i].a >> query[i].b >> query[i].c;
//		scanf("%d%d%d",&(query[i].a),&(query[i].b),&(query[i].c));
	stable_sort(query,query+x);
	qn = 0;
	for(int i =	1;qn < x && i <= m; i++)
	{
		//sscanf(arr[i-1],"%d%d%d %c",&a,&b,&c,&d);
		a = aa[i-1]; b = bb[i-1]; c = cc[i-1]; d = dd[i-1];
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
			else {
				//cout << disn[a]-disn[b] << " " << dise[a]-dise[b] << endl;
				printf("%d\n",abs(disn[a]-disn[b])+abs(dise[a]-dise[b]));
			}
			qn++;
		}
	}

	return 0;
}

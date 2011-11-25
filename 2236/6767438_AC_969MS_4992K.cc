#include <iostream>
#include <string.h>
#include <stdio.h>
#define N 1100
using namespace std;

int con[N][N], cn[N];
int x[N], y[N];
int parent[N];
bool good[N];

int disSquare(int &x1,int &y1,int &x2,int &y2)
{
	return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void SetInitial()
{
	memset(parent,-1,sizeof(parent));
}

int getParent(int x)
{
	if(parent[x] >= 0)
		return parent[x] = getParent(parent[x]);
	else
		return x;
}

void SetMerge(int x, int y)
{
	static int xx, yy;
	xx = getParent(x);
	yy = getParent(y);
	//cout << x << " = " << y << " get " << xx << " " << yy << endl;
	if(xx != yy)
	{
		if(parent[xx] < parent[yy])
			parent[yy] = xx;
		else if(parent[xx] > parent[yy])
			parent[xx] = yy;
		else {
			parent[yy] = xx;
			parent[xx]--;
		}
	} else
		return;

}

int main(int argc, char *argv[])
{
	int n, d;
	int repairPoint, pa, pb;
	char input[5];

	SetInitial();
	memset(good,false,sizeof(good));

	scanf("%d%d",&n,&d);
	d *= d;
	for(int i = 1; i <= n; i++)
		scanf("%d%d",x+i,y+i);
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++) 
			if(disSquare(x[i],y[i],x[j],y[j]) <= d)
			{
				con[i][cn[i]++] = j;
				con[j][cn[j]++] = i;
			}
	while(scanf("%s",input) == 1)
	{
		if(input[0] == 'O') {
			scanf("%d",&repairPoint);
			good[repairPoint] = true;
			for(int i = cn[repairPoint]-1; i >= 0; i--)
				if(good[con[repairPoint][i]])
					SetMerge(repairPoint, con[repairPoint][i]);
		} else {
			scanf("%d%d",&pa, &pb);
			if(getParent(pa) == getParent(pb))
				puts("SUCCESS");
			else
				puts("FAIL");
		}
	}

	

	
	return 0;
}

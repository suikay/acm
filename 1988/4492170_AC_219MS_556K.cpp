#include <stdio.h>
int parent[30001];
int under[30001];
int height[30001];
void MergeSet(int x,int y)
{
	height[y] += under[x] + 1;
	under[x] += under[y] + 1;
	parent[y] = x;
}
int FindParent(int x,int &hx)
{
	int xParent;
	if(parent[x]) {
		xParent = FindParent(parent[x],height[parent[x]]);
		hx += height[parent[x]];
		return parent[x] = xParent;
	}
	return x;
}
int main()
{
	int n;
	int x, y, t1, t2;
	char s[20];
	scanf("%d\n",&n);
	for( int i = 0; i < n; i++) {
		gets(s);
		if(s[0] == 'M') {
			sscanf(s,"M %d%d",&x,&y);
			t1 = FindParent(x,height[x]);
			t2 = FindParent(y,height[y]);
			MergeSet(t1,t2);
		}
		else {
			sscanf(s,"C %d",&x);
			t1 = FindParent(x,height[x]);
			printf("%d\n",under[t1] - height[x]);
		}
	}
}

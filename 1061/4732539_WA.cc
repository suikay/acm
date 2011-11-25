/*这道题用了同余定理*/
#include<iostream>
using namespace std;
int main()
{
	int x,y,m,n,l;
	while(cin>>x>>y>>m>>n>>l)
	{
		if(m < n)	{
			swap(x,y);
			swap(m,n);
		}
		int dis = (y - x + l)%l;
		int rd = (m - n)%l;
		if(!rd || (dis%rd))
			printf("Impossible\n");
		else
			printf("%d\n",dis/rd);
	}
	return 0;
}
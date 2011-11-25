#include<iostream>
using namespace std;
int main()
{
	int n,left,right,x,y;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		left = right = 0;
		cin >> x >> y;
		while(x&&y)
		{
			while(x >= y){
				left+=x/y;
				x %= y;
			}
			if(!x){
				left--;
				continue;
			}
			while(y > x){
				right += y/x;
				y %= x;
			}
			if(!y){
				right--;
				continue;
			}
		}
		printf("Scenario #%d:\n%d %d\n\n",i,left,right);
	}
	return 0;
}

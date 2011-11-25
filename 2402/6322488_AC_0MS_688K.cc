#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int q[1000],top;
void out(int res)
{
	int t(res);
	top = 0;
	res = abs(res);
	while(res)
	{
		q[top++] = res % 10;
		res /= 10;
	}
	if(t > 0) {
		for(int i = top-1; i >= 0; i--)
			printf("%d",q[i]);
		for(int i = 1; i < top; i++)
			printf("%d",q[i]);
	} else {
		for(int i = top-1; i >= 0; i--)
			printf("%d",q[i]);
		for(int i = 0; i < top; i++)
			printf("%d",q[i]);
	}
	puts("");
}
int main()
{
	int n,ten,res,start;
	while(scanf("%d",&n) && n)
	{
		res = 0;
		start = 1;
		ten = 9;
		while(res == 0)
		{
			if(n <= ten) {
				res = start + n - 1;
				break;
			}
			n -= ten;
			if(n <= ten) {
				res = -(start+n-1);
				break;
			}
			n -= ten;
			start *= 10;
			ten *= 10;
		}
		//cout << res << endl;
		out(res);
	}

	return 0;
}

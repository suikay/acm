#include<stdio.h>
#include<algorithm>
using namespace std;
int v[20000],st[20000];
int main()
{
	int n,_max(0),num,tmp;
	scanf("%d",&n);
	v[0] = -1;
	for(int i = 0; i < n; i++) 
	{
		scanf("%d",&num);
		for(int j = _max; j >= 0; j--) {
			tmp = (num + j)% n;
			if(!tmp) {
				v[n] = num;
				break;
			}
			if(v[j] && !v[tmp]) {
				v[tmp] = num;
				if(tmp > _max)
					_max = tmp;
			}
		}
	}
	int top(0);
	if(v[n] == 0)
		printf("0\n");
	else {
		while(n != 0) {
			//printf("## %d\n",v[n]);
			st[top++] = v[n];
			if(v[n] > n)
				n = n + 10 - v[n];
			else
				n = n - v[n];
		}
	}
	sort(st,st+top);
	for(int i=0; i<top; i++)
		printf("%d\n",st[i]);
	return 0;
}

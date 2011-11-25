#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int v[20000],st[20000];
bool ch[20000];
int main()
{
	int n,_max(0),num,tmp;
	scanf("%d",&n);
	v[0] = -1;
	for(int i = 0; i < n; i++) 
	{
		scanf("%d",&num);
		memset(ch,false,sizeof(ch));
		for(int j = _max; j >= 0; j--) 
		if(v[j] && !ch[j])
		{
			tmp = (num + j)% n;
			if(!tmp) {
				v[n] = num;
				break;
			}
			if(!v[tmp] ) {
				v[tmp] = num;
				ch[tmp] = true;
				if(tmp > _max)
					_max = tmp;
			}
		}
		if(v[n])
			break;
	}
	int top(0),ori(n);
	if(v[n] == 0)
		printf("0\n");
	else {
		while(n != 0) {
			st[top++] = v[n];
			if(v[n] > n)
				n = n + ori - v[n];
			else
				n = n - v[n];
		}
	}
	sort(st,st+top);
	printf("%d\n",top);
	for(int i=0; i<top; i++)
		printf("%d\n",st[i]);
	return 0;
}

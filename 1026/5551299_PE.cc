#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int N = 210;
int loop[N],to[N];
char ori[N],des[N];
void loop_check(int n)
{
	for(int i = 1; i <= n; i++)
	{
		int now = to[i];
		loop[i] = 1;
		while(now != i) {
			loop[i]++;
			now = to[now];
		}
	}
}
int main()
{
	int m,n,now;
	char dummy;
	while(cin >> n && n)
	{
		for(int i = 1; i <= n; i++)
			cin >> to[i];
		loop_check(n);
		memset(des,0,sizeof(des));
		while(cin >> m  && m) {
			ori[0] = ' ';
			getchar();
			gets(ori+1);
			for(int i = strlen(ori); i <= n; i++)
				ori[i] = ' ';
			ori[n+1] = '\0';
			for(int i = 1; i <= n; i++)
			{
				now = i;
				for(int j = m % loop[i]; j > 0; j--)
					now = to[now];
				des[now] = ori[i];
			}
			des[n+1] = '\0';
			printf("%s\n",des+1);
		}
	}
	return 0;
}
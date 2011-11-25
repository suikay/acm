#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	char x[1000],y[1000];
	int xs[26],ys[26];
	scanf("%d\n",&n);
	for(int i = 1; i <= n; i++)
	{
		memset(xs,0,sizeof(xs));
		memset(ys,0,sizeof(ys));
		gets(x);
		gets(y);
		for(int ii = 0; ii < strlen(x); ii++)
			xs[x[ii]-'a']++;
		for(int j = 0; j < strlen(y); j++)
			ys[y[j]-'a']++;
		int res(0);
		for(int j = 0; j < 26; j++)
			if(xs[j]!=ys[j])
				res += abs(xs[j]-ys[j]);
		printf("Case #1:  %d\n",res);
	}
	return 0;
}
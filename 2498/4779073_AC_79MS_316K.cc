#include<stdio.h>
#include<string.h>
int main()
{
	int n,t,kk,k,tt,v[]={9,3,7},res;
	char x[10000];
	scanf("%d\n",&n);
	for(int i = 1; i <= n; i++)
	{
		gets(x);
		res = 0;
		tt = 0;
		for(int j = strlen(x)-1; j >= 0; j--)
			if(x[j] == '?'){
				kk = j;
				k = v[tt++];
				tt %= 3;
			}
			else{
				res += (x[j]-'0')*v[tt++];
				tt %= 3;
			}
		for(int ii = 0; ii < 10; ii++)
			if(!((ii * k +res)%10))	{
				x[kk] = ii+'0';
				break;
			}
		printf("Scenario #%d:\n",i);
		puts(x);
		printf("\n");
	}
	return 0;
}

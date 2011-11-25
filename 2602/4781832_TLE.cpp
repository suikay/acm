#include<stdio.h>
#define M 1000100
char x[M],y[M];
int main()
{
	int n,last(0);
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i = n-1; i >= 0; i--){
		x[i] += y[i] + last;
		if(x[i]>=10){
			x[i] %= 10;
			last = 1;
		}
		else
			last = 0;
	}
	if(last)
		printf("%d",last);
	for(int i = 0; i < n; i++)
		printf("%d",x[i]);
	printf("\n");
	return 0;
}
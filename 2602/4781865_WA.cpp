#include<stdio.h>
#define M 1000100
char x[M],y[M];
int main()
{
	int n,last(0);
	n = getchar() - '0';
	getchar();
	for(int i = 0; i < n; i++){
		x[i] = getchar();
		x[i] -= '0';
		getchar();
		y[i] = getchar();
		y[i] -= '0';
		getchar();
	}
	for(int i = n-1; i >= 0; i--){
		x[i] += y[i] + last;
		if(x[i] >= 10){
			x[i] %= 10;
			last = 1;
		}
		else
			last = 0;
	}
	if(last)
		putchar('1');
	for(int i = 0; i < n; i++)
		putchar(x[i]+'0');
	printf("\n");
	return 0;
}
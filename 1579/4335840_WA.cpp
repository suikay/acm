#include <stdio.h>
int data[21][21][21];
int f(int a ,int b, int c)
{
	if(a > 20 || b > 20 || c >20 )
		return f(20,20,20);
	if (data[a][b][c])
		return data[a][b][c];
	if ( a <= 0 || b <= 0 || c <= 0)
		return 1;
	if ( a< b && b < c) 
		data[a][b][c] = f(a, b, c-1) + f(a, b-1, c-1) - f(a, b-1, c) ;
	else
		data[a][b][c] = f(a-1, b, c) + f(a-1, b-1, c) + f(a-1, b, c-1) - f(a-1, b-1, c-1) ;
	return data[a][b][c];
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	while ( !(a == -1 && b == -1 && c == -1)){
		printf("w(%d, %d, %d) = %d\n",a,b,c,f(a,b,c));
		scanf("%d%d%d",&a,&b,&c);
	}
	return 0;
}
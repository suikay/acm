#include <stdio.h>
int main()
{
	int num,a,b;
	scanf("%d",&num);
	for ( int i = 0; i < num; i++)
	{
		scanf("%d%d",&a,&b);
		printf("%s",a < b ? "NO BRAINS\n":"MMM BRAINS\n");
	}
	return 0;
}
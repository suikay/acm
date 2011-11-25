#include <stdio.h>
#include <memory.h>
#include <string.h>
char str1[1000],str2[1000];
int data[1001][1001];
int str1len,str2len,i,j;
int max(int x,int y)
{
	return x>y?x:y;
}
int f(int x,int y)
{
	if ( x < 0 || y < 0)
		return 0;
	if (str1[x] == str2[y])
		data[x][y] = 1 + f(x-1,y-1);
	else
		data[x][y] = max( f(x-1,y),f(x,y-1));
	return data[x][y];
}

int main()
{

	while ( scanf("%s%s",str1,str2) == 2)
	{
		memset(data,0,sizeof(data));
		str1len = strlen(str1);
		str2len = strlen(str2);
		printf("%d\n",f(str1len-1,str2len-1));
	}
	return 0;
}

#include <stdio.h>
#include <memory.h>
#include <string.h>
#define max(x,y) (x) = (x)>(y)?(x):(y)
char str1[1000],str2[1000];
int data[1001][1001];
int str1len,str2len,i,j;


int main()
{

	while ( scanf("%s%s",str1,str2) == 2)
	{
		memset(data,0,sizeof(data));
		str1len = strlen(str1);
		str2len = strlen(str2);
		for( i = 0; i <str1len ; i++)
			for( j = 0; j < str2len; j++)
			{
				if(str1[i] == str2[j] )
					if(i > 0 && j > 0)
						data[i][j] = data[i-1][j-1] + 1;
					else
						data[i][j] = 1;
				else {
					if(i)
						max(data[i][j],data[i-1][j]);
					if(j)
						max(data[i][j],data[i][j-1]);
				}
			}
		max(data[str1len][str2len],data[str1len-1][str2len-1]);
		printf("%d\n",data[str1len][str2len]);
	}
	return 0;
}

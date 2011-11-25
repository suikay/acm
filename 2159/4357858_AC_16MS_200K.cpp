#include <stdio.h>
int data1[26],data2[26],much[100];
int main()
{
	int i;
	char c;
	c = getchar();
	while ( c != '\n')
	{
		data1[c - 'A'] ++;
		c = getchar();
	}
	for ( i = 0 ; i < 26; i ++)
		much[data1[i]]++;
	c = getchar();
	while( c != '\n')
	{
		data2[c - 'A'] ++;
		c = getchar();
	}
	for ( i = 0; i < 26 ; i++)
		much[data2[i]]--;
	for ( i = 0; i < 100; i ++)
		if (much[i] != 0)
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}
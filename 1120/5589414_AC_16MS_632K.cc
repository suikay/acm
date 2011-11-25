#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
char x[22][22],tmp[22][22],_map[100];
int d[16];
int main()
{
	_map[0] = '.';
	_map[1] = '!';
	_map[2] = 'X';
	_map[3] = '#';

	int n;
	memset(x,0,sizeof(x));
	scanf("%d",&n);
	for(int i = 0; i < 16; i++)
		scanf("%d",d+i);
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= 20; j++)
			scanf("%d",&(x[i][j]));
	while(n--)
	{
		for(int i = 1; i <= 20; i++)
			for(int j = 1; j <= 20; j++) {
				tmp[i][j] = x[i][j] + d[x[i-1][j]+x[i][j-1]+x[i+1][j]+x[i][j+1]+x[i][j]];
				if(tmp[i][j] >3)
					tmp[i][j] = 3;
				else if(tmp[i][j] < 0)
					tmp[i][j] = 0;
			}
		memcpy(x,tmp,sizeof(tmp));
	}
	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= 20; j++) 
			putchar(_map[x[i][j]]);
		puts("");
	}
	
	return 0;
}
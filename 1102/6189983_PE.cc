#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
char num[10][7] = { {'-','|','|',' ','|','|','-'},
					{' ',' ','|',' ',' ','|',' '},
					{'-',' ','|','-','|',' ','-'},
					{'-',' ','|','-',' ','|','-'},
					{' ','|','|','-',' ','|',' '},
					{'-','|',' ','-',' ','|','-'},
					{'-','|',' ','-','|','|','-'},
					{'-',' ','|',' ',' ','|',' '},
					{'-','|','|','-','|','|','-'},
					{'-','|','|','-',' ','|','-'}};
int main()
{
	int t;
	char ori[10];
	//freopen("out.txt","w",stdout);
	while(scanf("%d%s",&t,ori) && t)
	{
		int len = strlen(ori);
		for(int i = 0; i < len; i++)
			ori[i] -= '0';

		for(int i = 0; i < len; i++) {
			putchar(' ');
			for(int j = 0; j < t; j++)
				putchar(num[ori[i]][0]);
			putchar(' ');
		}
		puts("");

		for(int i = 0; i < t; i++) {
			for(int j = 0; j < len; j++) {
				putchar(num[ori[j]][1]);
				for(int k = 0; k < t; k++)
					putchar(' ');
				putchar(num[ori[j]][2]);
			}
			puts("");
		}

		for(int i = 0; i < len; i++) {
			putchar(' ');
			for(int j = 0; j < t; j++)
				putchar(num[ori[i]][3]);
			putchar(' ');
		}
		puts("");

		for(int i = 0; i < t; i++) {
			for(int j = 0; j < len; j++) {
				putchar(num[ori[j]][4]);
				for(int k = 0; k < t; k++)
					putchar(' ');
				putchar(num[ori[j]][5]);
			}
			puts("");
		}

		for(int i = 0; i < len; i++) {
			putchar(' ');
			for(int j = 0; j < t; j++)
				putchar(num[ori[i]][6]);
			putchar(' ');
		}
		puts(""); puts("");
	}


	return 0;
}

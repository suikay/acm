#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
const int N = 100000;
int type[N],cnt[3],ptr[3];
char buffer[N],bu[3][N];
int main()
{
	int len;
	while(true)
	{
		for(int i = 0; i < 3; i++)
			scanf("%d",ptr+i);
		if(!ptr[0] && !ptr[1] && !ptr[2])
			return 0;
		scanf("%s",buffer);
		len = strlen(buffer);
		memset(cnt,0,sizeof(cnt));
		for(int i = 0; i < len; i++)
			if(buffer[i] >= 'a' && buffer[i] <= 'i') {
				type[i] = 0;
				bu[0][cnt[0]++] = buffer[i];
			}
			else if(buffer[i] >= 'j' && buffer[i] <= 'r') {
				type[i] = 1;
				bu[1][cnt[1]++] = buffer[i];
			}
			else {
				type[i] = 2;
				bu[2][cnt[2]++] = buffer[i];
			}
		for(int i = 0; i < 3; i++) {
			if(ptr[i] < 0) 
				ptr[i] += ((-ptr[i]/cnt[i])+3)*cnt[i];
			ptr[i] %= cnt[i];
			ptr[i] = cnt[i] - ptr[i];
		}
		/*
		for(int i = 0; i < 3; i++)
			cout << ptr[i] << endl;
			*/
		for(int i = 0; i < len; i++)
			putchar(bu[type[i]][(ptr[type[i]]++)%cnt[type[i]]]);
		puts("");
	}
		

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int compare(const void*a ,const void *b)
{
	return - *((char*)a) + *((char*)b);
}
int reserve(int a)
{
	int b = 0;
	while(a) {
		b = b * 10 + a % 10;
		a /= 10;
	}
	return b;
}
bool invalid(char*s )
{
	for(int i = 0; i < 4; i++)
		if(!isdigit(s[i]))
			return true;
	char c = s[0];
	for(int i = 0; i < 4; i++)
		if(s[i] != c)
			return false;
	return true;
}
int main()
{
	int m,n,q,time;
	char num[5];
	while(true) {
		gets(num);
		if(num[0] == '-')
			break;
		printf("N=%s:\n",num);
		if(invalid(num)) {
			printf("No!!\n");
			continue;
		}
		time = 1;
		while(true) {
			qsort(num,4,sizeof(char),compare);
			n = atoi(num);
			q = reserve(n);
			m = n - q;
			printf("%d-%d=%d\n",n,q,m);
			if(!m || m == 6174) {
				printf("Ok!! %d times\n",time);
				break;
			}
			time++;
			strcpy(num ,itoa(m,num,10));
		}
	}
}

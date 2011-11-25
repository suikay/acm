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
char* itoa(int x)
{
	char s[5];
	int n = 0;
	while(x) {
		s[n++] = '0' + x % 10;
		x /= 10;
	}
	s[n] = '\0';
	return s;
}
int main()
{
	int m,n,q,time;
	char num[100];
	while(true) {
		gets(num);
		if(num[0] == '-' && num[1] == '1' && num[2] == '\0')
			break;
		printf("N=%d:\n",num);
		if(invalid(num) || strlen(num) > 4) {
			printf("No!!\n");
			continue;
		}
		time = 1;
		while(true) {
			qsort(num,strlen(num),sizeof(char),compare);
			n = atoi(num);
			q = reserve(n);
			m = n - q;
			printf("%d-%d=%d\n",n,q,m);
			if(!m || m == 6174) {
				printf("Ok!! %d times\n",time);
				break;
			}
			time++;
			strcpy(num ,itoa(m));
		}
	}
}

#include <stdio.h>
#define N 1000010
int p[N];
char str[N];

bool input(int &n)
{
	scanf("%d",&n);
	if(!n)
		return false;
	gets(str);
	gets(str);
	return true;
}
void make(int n)
{
	p[0] = -1;
	int j = -1;
	for(int i = 1; i < n; i++)
	{
		while(j >= 0 && str[i] != str[j+1])
			j = p[j];
		if(str[j+1] == str[i])
			j++;
		p[i] = j;
	}
}

void f(int n)
{
	int tmp;
	for(int i = 1; i < n; i++)
	{
		tmp = p[i];
		if(i-tmp <= 0)
			continue;
		if((i+1)%(i-tmp) == 0) {
			tmp = (i+1)/(i-tmp);
			if(tmp > 1)
				printf("%d %d\n",i+1,tmp);
		}
	}
}

int main()
{
	int n,cnt(1);
	while(input(n))
	{
		make(n);
		printf("Test case #%d\n",cnt++);
		f(n);
		puts("");
	}

	return 0;
}
#include<string.h>
#include<stdio.h>
#define isalpha(x) ( x >= 'A' && x <= 'Z')
int main()
{
	char tmp[300];
	int sum,len;
	while(true){
		sum = 0;
		gets(tmp);
		if(tmp[0] == '#')
			return 0;
		len = strlen(tmp);
		for(int i = 1; i <= len; i++)
			if(isalpha(tmp[i-1]))
				sum += i * (tmp[i-1] - 'A'+1);
		printf("%d\n",sum);
	}
	return 0;
}
#include<string.h>
#include<stdio.h>
#define N 1100000
char ori[N],cha[N];
int main()
{
	int tmp,len;
	while(true)
	{
		scanf("%s",ori);
		if(ori[0] == '.' && ori[1] == '\0')
			return 0;
		len = strlen(ori);
		for(int i = len; i >= 1; i--)
			if(len % i)
				continue;
			else {
				strcpy(cha,ori+len/i);
				tmp = len-len/i;
				for(int j = tmp; j < len; j++)
					cha[j] = ori[j-tmp];
				cha[len] = '\0';
				if(strcmp(cha,ori) == 0) {
					printf("%d\n",i);
					break;
				}
			}
	}
}
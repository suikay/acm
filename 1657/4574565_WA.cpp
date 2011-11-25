#include <stdio.h>
#include <string.h>
#define abs(x) ((x)>0)?(x):-(x)
#define max(x,y) x > y? x:y
int main()
{
	char s[50];
	int n;
	scanf("%d\n",&n);
	for(int i = 0; i < n ;i++) {
		int y1,y2;
		char x1,x2;
		gets(s);
		sscanf(s,"%c%d %c%d",&x1,&y1,&x2,&y2);
		int x = abs(x1-x2);
		int y = abs(y1-y2);
		if(!x&&!y){
			printf("0 0 0 0\n");
			continue;
		}
		printf("%d ",max(x,y));
		if(x==y||!x || !y)
			printf("1 ");
		else
			printf("2 ");
		if(!x||!y)
			printf("1 ");
		else
			printf("2 ");
		if(x==y)
			printf("1\n");
		else
			if(abs(y-x)%2)
				printf("Inf\n");
			else
				printf("2\n");
	}
	return 0;
}
#include <stdio.h>
int son[10000];
int main()
{
	int p,oper,x,y,count;
	char c;
	scanf("%d",&p);
	for (oper = 1; oper < p ; p++)
	{
		do {
			c = getchar();
		}while(c == '\n');
		if (c == 'M') {
			scanf("%d%d",&x,&y);
			while (son[x])
				x = son[x];
			son[x] = y;
		}
		else {
			scanf("%d",&x);
			count = 0;
			while(son[x]) {
				count++;
				x = son[x];
			}
			printf("%d\n",count);
		}
	}
	return 0;
}

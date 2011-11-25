#include <stdio.h>
int son[100009],parent[1000009];
int main()
{
	int p,oper,x,y,count;
	char c;
	scanf("%d",&p);
	for (oper = 0; oper < p ; oper++)
	{
		getchar();
		c = getchar();
		if (c == 'M') {
			scanf("%d%d",&x,&y);
			while (son[x])
				x = son[x];
			while (parent[y])
				y = parent[y];
			son[x] = y;
			parent[y] = x;
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

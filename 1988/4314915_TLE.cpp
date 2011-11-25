#include <stdio.h>
#include <memory.h>
int son[100009],parent[1000009],rank[1000009];
int main()
{
	int p,oper,x,y,count,xparent,yparent,xson,yson;
	char c;
	scanf("%d",&p);
	memset(rank,1,sizeof(int));
	for (oper = 0; oper < p ; oper++)
	{
		getchar();
		c = getchar();
		if (c == 'M') {
			scanf("%d%d",&x,&y);
			xparent = x;
			xson = x;
			yparent = y;
			yson = y;
			while (parent[xparent])
				xparent = parent[xparent]	;
			while (son[xson])
				xson = son[xson];
			while (parent[yparent])
				yparent = parent[yparent]	;
			while (son[yson])
				yson = son[yson];
			rank[xparent] += rank[yparent];
			son[xparent] = yson;
			son[xson] = yson;
			rank[xson] = rank[yparent] + 1;
			parent[yparent] = xparent;
		}
		else {
			scanf("%d",&x);
			count = 0;
			while(son[x]) {
				count += rank[x];
				x = son[x];
			}
			printf("%d\n",count);
		}
	}
	return 0;
}

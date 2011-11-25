#include <stdio.h>
#include <string.h>
bool bp[1100];
int cnt[1100],p[300],pn,mid[1100];
int max(int x, int y) {
	if(x > y)
		return x;
	return y;
}
int main()
{
	pn = 0;
	memset(bp,true,sizeof(bp));
	cnt[0] = 0;
	cnt[1] = 1;
	p[pn++] = 1;
	for(int i = 2; i <= 1000; i++)
	{
		if(bp[i]) {
			for(int j = i*i; j <= 1000; j += i)
				bp[j] = false;
			p[pn++] = i;
		}
		cnt[i] = pn;
	}
	int x,y;
	while(scanf("%d%d",&x,&y) == 2) 
	{
		printf("%d %d:",x,y);
		if(cnt[x] % 2) {
			for(int i = max(0,cnt[x]/2-y+1); (i < (cnt[x]/2+y)) && (p[i] <= x) && i < pn; i++)
				printf(" %d",p[i]);
			puts("");
		} else {
			for(int i = max(0,cnt[x]/2-y); (i < (cnt[x]/2+y)) && (p[i] <= x) && i < pn; i++)
				printf(" %d",p[i]);
			puts("");
		}
		puts("");
	}
	return 0;
}

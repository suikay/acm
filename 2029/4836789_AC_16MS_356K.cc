#include<stdio.h>
#include<memory.h>
int main()
{
	bool map[101][101];
	int n,w,h,s,t,xx,yy,res,max;
	int count[101][101];
	while(true)
	{
		memset(map,false,sizeof(map));
		memset(count,0,sizeof(count));
		scanf("%d",&n);
		if(!n)
			return 0;
		scanf("%d%d",&w,&h);
		for(int i = 0; i < n; i++){
			scanf("%d%d",&xx,&yy);
			map[xx][yy] = true;
		}
		scanf("%d%d",&s,&t);
		max = 0;
		for(int i = 1; i <= w-s+1; i++)
			for(int j = 1; j <= h-t+1; j++){
				res = 0;
				for(int k = 0; k < s; k++)
					for(int l = 0; l < t; l++)
						if(map[k+i][l+j])
							res++;
				if(res > max)
					max = res;
			}
		printf("%d\n",max);
	}
	return 0;
}

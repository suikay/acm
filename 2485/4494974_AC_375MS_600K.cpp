#include <stdio.h>
#include <memory.h>
#define INF 99999999
int road[501][501];
int in[501],inv[501];
int main()
{
	int n,m;
	int i,j,k,l;
	int mink,min,res;
	scanf("%d",&n);
	for( i = 0; i < n ;i ++) {
		scanf("%d",&m);
		memset(in,0,501*sizeof(int));
		memset(inv,0,501*sizeof(int));
		for (j = 0; j < m;j++)
			for( k = 0; k < m;k++)
				scanf("%d",&road[j][k]);
		in[0] = 0;
		inv[0] = 1;
		res = -1;
		for( j = 1; j < m ;j++) {
			min = INF;
			for(k = 0; k < j ;k++)
				for( l = 0; l < m; l++)
					if( !inv[l] && road[in[k]][l] && road[in[k]][l] < min) {
						mink = l;
						min = road[in[k]][l];
					}
			inv[mink] = 1;
			in[j] = mink;
			if(res < min)
				res = min;
		}
		printf("%d\n",res);
	}
}
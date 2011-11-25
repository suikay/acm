#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int data[1005][1005],dis[1005];
bool final[1005];
#define MAX 3000000
int main()
{
	int i,j,k,t,n,a,b,c,v,_min;
	scanf("%d%d",&t,&n);
	for ( i = 1; i <= n ; i++)
		for ( j = 1; j <= n ; j++)
			data[i][j] = MAX;
	for ( i = 0; i < t ;i ++) {
		scanf("%d%d%d",&a,&b,&c);
		if ( data[a][b] > c) {
			data[a][b] = c;
			data[b][a] = c;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	memset(final,false,sizeof(final));
	dis[1] = 0;
	for(i = 1; i < n; i++) {
		_min = 0x7fffffff;
		for( k = 1; k <= n; k++)
			if (!final[k] && dis[k] < _min)
			{
				v = k;
				_min = dis[k];
			}
		final[v] = true;
		for(k = 1; k <= n; k++)
			if(!final[k] && dis[k] > (dis[v] + data[v][k]))
				dis[k] = dis[v] + data[v][k];
	}
	printf("%d\n",dis[n]);
	return 0;
}
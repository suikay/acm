#include<algorithm>
#include<stdio.h>
#include<memory.h>
using namespace std;
int main()
{
	int n1,n2,n,tmp;
	int minn[10],maxx[10];
	long long res;
	while(scanf("%d%d%d",&n1,&n2,&n))
	{
		memset(minn,0x7f,sizeof(minn));
		memset(maxx,0xf0,sizeof(maxx));
		res = 0;
		if(!n1)
			break;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&tmp);
			res += tmp;
			if(tmp > maxx[0]){
				maxx[0] = tmp;
				sort(maxx,maxx+n1);
			}
			if(tmp < minn[n2-1]){
				minn[n2-1] = tmp;
				sort(minn,minn+n2);
			}
		}
		for(int i = 0; i < n1; i++)
			res -= maxx[i];
		for(int i = 0; i < n2; i++)
			res -= minn[i];
		printf("%.6f\n",res*1.0/(n-n1-n2));
	}
	return 0;
}
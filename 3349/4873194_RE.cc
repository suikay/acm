#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define P1 3173
#define P2 3121
#define P3 9919973
#define P4 3313
#define MAX 10000000
//#define abs(x) (x<0)?(-x):(x)
#define clean(x) memset((x),false,sizeof((x)))
bool h1[MAX],h2[MAX],h3[MAX],h4[MAX];
int main()
{
	int n,arr[6];
	int tmp0,tmp1,tmp2,tmp3,tmp4,tmp5;
	bool flag = true;
	scanf("%d",&n);
	clean(h1);
	clean(h2);
	clean(h3);
	clean(h4);
	for(int i = 0; i < n && flag; i++)	{
		tmp5 = 0;
		for(int j = 0; j < 6; j++)	{
			scanf("%d",&arr[j]);
			tmp5 += arr[j];
		}
		tmp0 = (arr[0]+arr[5])%P1*(arr[2]+arr[1])%P1*((arr[4]+arr[3])%P1);
		tmp1 = (arr[0]+arr[1])%P1*(arr[2]+arr[3])%P1*((arr[4]+arr[5])%P1);
		tmp2 = abs(arr[0]-arr[1])%P2*abs(arr[2]-arr[3])%P2*(abs(arr[4]-arr[5])%P2);
		tmp3 = abs(arr[0]-arr[5])%P2*abs(arr[2]-arr[1])%P2*(abs(arr[3]-arr[4])%P2);
		tmp4 = (arr[0] + arr[2] + arr[4])%P4*((arr[1] + arr[3] + arr[5])%P4);
		tmp5 %= P3;
		if(h1[tmp0] && h1[tmp1] && h2[tmp2] && h2[tmp3] && h3[tmp4] && h4[tmp5])
			flag = false;
		h1[tmp0] = h1[tmp1] = h2[tmp3] = h2[tmp2] = h3[tmp4] = h4[tmp5] = true;
	}
	if(flag)
		printf("No two snowflakes are alike.\n");
	else
		printf("Twin snowflakes found.\n");
	return 0;
}

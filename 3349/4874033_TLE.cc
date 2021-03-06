#include<stdlib.h>
#include<stdio.h>
#include<memory.h>
#define P1 3313
#define P2 3329
#define MAX 10000000
struct Hash{
	int h2;
	int h3;
	Hash* next;
};
Hash* h1[MAX];
int main()
{
	Hash *htmp,*htmp2;
	int arr[6],n,sum,kk,c;
	int tmp1,tmp2,tmp3;
	bool flag = true;
	scanf("%d",&n);
	c = getchar();
	memset(h1,0,sizeof(h1));
	for(int i = 0; i < n && flag; i++)
	{
		tmp1  = 0;
		for(int j = 0; j < 6; j++){
			scanf("%d",&arr[j]);
			tmp1 += arr[j];
		}
		tmp1 %= MAX;
		tmp2 = (arr[0]-arr[1])*(arr[2]-arr[3])*(arr[4]-arr[5])*(arr[0]-arr[5])*(arr[2]-arr[1])*(arr[4]-arr[3]);
		tmp3 = (arr[0]+arr[2]+arr[4])*(arr[1]+arr[3]+arr[5]);
		if(h1[tmp1] == 0)
		{
			htmp = new Hash();
			htmp->h2 = tmp2;
			htmp->h3 = tmp3;
			htmp->next = 0;
			h1[tmp1] = htmp;
		}
		else
		{
			htmp2 = h1[tmp1];
			while(htmp2 && flag){
				if((htmp2->h2 == tmp2) && (htmp2->h3 == tmp3))
					flag = false;
				else
					htmp2 = htmp2->next;
			}
			if(flag){
				htmp = new Hash();
				htmp->h2 = tmp2;
				htmp->h3 = tmp3;
				htmp->next = h1[tmp1];
				h1[tmp1] = htmp;
			}
		}
	}
	if(flag)
		printf("No two snowflakes are alike.\n");
	else
		printf("Twin snowflakes found.\n");
	return 0;
}
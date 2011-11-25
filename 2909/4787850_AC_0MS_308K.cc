#include<stdio.h>
#include<memory.h>
int pri[3500],priN;
int main()
{
	bool bpri[33000];
	int res;
	priN = 0;
	memset(bpri,true,sizeof(bpri));
	bpri[0] = bpri[1] = false;
	for(int i = 2; i < 33000; i++)
		if(bpri[i])	{
			pri[priN++] = i;
			for(int j = 2*i; j < 33000; j+=i)
				bpri[j] = false;
		}
	int n;
	while(scanf("%d",&n)&&n)
	{
		res = 0;
		for(int i = 0; i < priN; i++)
			if(pri[i] > n/2)
				break;
			else
				if(bpri[n-pri[i]])
					res++;
		printf("%d\n",res);
	}
	return 0;
}
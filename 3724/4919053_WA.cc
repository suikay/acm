#include<math.h>
#include<memory.h>
#include<stdio.h>
int main()
{
	bool v[1024];
	float x,y;
	double e,tmp;
	memset(v,true,sizeof(v));
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)	{
		scanf("%f%f",&x,&y);
		e = exp(x);
		tmp = 1.0;
		for(int j = 1; j < 1024; j+=2){
			for(int k = 9; k >= 0; k--)
			{
				if((j >> k) & 1)
					tmp = tmp * e + 1.0;
				else
					tmp = tmp + 1.0;
			}
			tmp -= 1.0;
			if(fabs(tmp - y) > 10e-4)
				v[j] = false;
		}
	}
	int last = 0;
	for(int j = 1; j < 1024; j+=2)
		if(v[j]){
			for(int k = 0; k < 10; k++)	{
				if((j >> k) & 1)
					last++;
				printf("%d\n",last);
			}
			return 0;
		}
		return 0;
}
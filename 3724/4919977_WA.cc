#include<math.h>
#include<memory.h>
#include<stdio.h>
int n,record[10];
float x[20],y[20];
double xx[20][11],yy[20];
bool f(int no,int last)
{
	if(no == 10)	{
		for(int i = 0; i < n; i++)	{
			for(int j = 0; j < 10; j++)
				yy[i] += xx[i][record[j]];
		}
		for(int i = 0; i < n; i++)
			if(fabs(yy[i] - y[i]) > 10e-3)
				return false;
		for(int i = 0; i < 10; i++)
			printf("%d\n",record[i]);
		return true;
	}
	while(last <= 10){
		record[no] = last;
		if(!f(no+1,last))
			last++;
		else
			return true;
	}
	return false;
}

int main()
{
	bool v[1024];
	//float x,y;
	double e,tmp;
	memset(v,true,sizeof(v));
	scanf("%d",&n);
	for(int i = 0; i < n; i++)	{
		scanf("%f%f",&(x[i]),&(y[i]));
		xx[i][0] = 1.0;
		e = exp(x[i]);
		tmp = 1.0;
		for(int j = 1; j <= 10; j++)
			xx[i][j] = xx[i][j-1]*e;
	}
	f(0,1);
}
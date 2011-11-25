#include<math.h>
#include<memory.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int n,record[10];
double x[20],y[20];
double xx[20][11],yy[20];
bool f(int no,int last)
{
	if(no == 10)	{
		//if(record[0] == 2)
			//cout << "hello";
		for(int i = 0; i < n; i++)	{
			yy[i] = 0;
			for(int j = 0; j < 10; j++)
				yy[i] += xx[i][record[j]];
		}
		for(int i = 0; i < n; i++)
			if(fabs(yy[i]/y[i] - 1.0) > 10e-5)
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
		//scanf("%f%f",&(x[i]),&(y[i]));
		cin >> x[i] >> y[i];
		xx[i][0] = 1.0;
		e = exp(x[i]);
		tmp = 1.0;
		for(int j = 1; j <= 10; j++)
			xx[i][j] = xx[i][j-1]*e;
	}
	f(0,1);
}
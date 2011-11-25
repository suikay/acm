#include<string.h>
#include<stdio.h>
double f(int h,int m,int s,int sp)
{
	return (1.0*h + m/60.0 + s/(60.0*60.0))*sp;
}
int main()
{
	int lh,lm,ls,lsp,nh,nm,ns,nsp;
	double res=0.0;
	char x[100];
	lh = lm = ls = lsp = 0;
	while(gets(x))
	{
		if(strlen(x) >= 9)
		{
			sscanf(x,"%d:%d:%d %d",&nh,&nm,&ns,&nsp);
			res += f(nh-lh,nm-lm,ns-ls,lsp);
			lh = nh;
			lm = nm;
			ls = ns;
			lsp = nsp;
		}
		else
		{
			sscanf(x,"%d:%d:%d",&nh,&nm,&ns);
			printf("%s %.2f km\n",x,res+f(nh-lh,nm-lm,ns-ls,lsp));
		}
	}
	return 0;
}

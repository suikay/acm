#include<stdio.h>
int ff(int x,int mod)
{
	if(x < 0)
		return ((x + (-x)/mod*mod+mod)%mod);
	return x%mod;
}
int main()
{
	int a,b,c,d,e,f,g,h,i,t;
	int arr[1010];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		for(int j = 0; j < i; j++)
			if(!(j % 2))
				arr[j+3] = ff(d*arr[j+2] + e*arr[j+1] - f*arr[j],g);
			else
				arr[j+3] = ff(f*arr[j+2] - d*arr[j+1] + e*arr[j],h);
		printf("%d\n",arr[i]);
	}
	return 0;
}
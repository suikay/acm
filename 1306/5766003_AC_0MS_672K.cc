#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
double C(int a,int b)
{
	double res;
	res = 1.0;
	if(b >= a/2)
		b = a-b;
	for(int i = 1;i <= b; i++) 
		res = res*(a-i+1)/i;
	return res;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b) && a && b)
		printf("%d things taken %d at a time is %d exactly.\n",a,b,(int)(C(a,b)+0.5));

	return 0;
}
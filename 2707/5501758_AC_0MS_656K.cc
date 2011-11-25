#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define INF 0.999
bool fit(int a,int b,int c,int d)
{
//	printf("%d %d %d %d\n",a,b,c,d);
	if(min(a,b) <= min(c,d) &&
		max(a,b) <= max(c,d))
		return true;
	return false;
}
int main()
{
	int a,b,c,d;
	while(true) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(!a && !b && !c && !d)
			break;
		for(int i = 100; i > 0; i--) 
			if(fit(a*i/100.0+INF,b*i/100.0+INF,c,d)) {
				printf("%d",i);
				puts("%");
				break;
		}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
double phi[100000],tmp;
bool bp[100000];
int main()
{
//	for(int i = 1; i <= 65536; i++)
//		up[i] = down[i] = 1;
	double res;
	for(int i = 2; i <= 65536; i++)
		phi[i] = i;
	for(int i = 2; i <= 65536; i++)
		if(!bp[i])
			for(int j= i*i; i <= 900 && j <= 65536; j+=i)
				bp[j] = true;

	for(int i = 2; i <= 65536; i++) 
		if(!bp[i]){
			tmp = 1.0*(i-1)/i;
			for(int j = i; j <= 65536; j += i)
				phi[j] *= tmp;
	}
	int n;
	for(int i = 2; i <= 10; i++);
		//cout << phi[i] << endl;
	while(scanf("%d",&n) == 1)
		printf("%d\n",(int)(phi[n-1]+0.1));


	return 0;
}

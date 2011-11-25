#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int big[21000];
int main()
{
	int n,k,res,ress;
	for(int i = 2; i < 20000; i++)
		if(!big[i]) 
			for(int j = 2*i; j <= 20000; j+=i)
				big[j] = i;
	scanf("%d",&n);
	res = 0;
	while(n--)
	{
		scanf("%d",&k);
		if(res < big[k]) {
			res = big[k];
			ress = k;
		}
	}
	cout << ress << endl;

	return 0;
}

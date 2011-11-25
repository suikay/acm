#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int D,V;
	const double PI = 3.1415926;
	while(cin >> D >> V)
	{
		if(D == 0 && V == 0)
			return 0;
		printf("%.3f\n",pow(1.0*(D*D*D-6.0/PI*V),1.0/3));
	}
	return 0;
}
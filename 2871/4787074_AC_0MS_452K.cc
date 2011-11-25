#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	double last,now;
	cin >> last;
	while(cin >> now)
	{
		if(now > 998)
			break;
		else
			printf("%.2f\n",now-last);
		swap(last,now);
	}
	printf("End of Output\n");
	return 0;
}
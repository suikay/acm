#include<set>
#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 2100000000
bool v[500000] = {false};
int main()
{
	int hn[5900],hnc(0);
	long long tmp;
	set<long long,less<long long>>in;
	in.insert(1);
	in.insert(3);
	in.insert(2);
	in.insert(5);
	in.insert(7);
	in.lower_bound(0);
	for(int i = 1; i <= 5842; i++){
		tmp = *in.begin();
		in.insert(tmp*2);
		in.insert(tmp*3);
		in.insert(tmp*7);
		in.insert(tmp*5);
		in.erase(tmp);
		hn[i] = tmp;
	}
	int n;
	while(true)
	{
		scanf("%d",&n);
		if(!n)
			return 0;
		if(n == 11 || n == 12 || n == 13 ||
			((n%10) != 1 && (n%10) != 2 && (n%10) != 3))
			printf("The %dth humble number is %d.\n",n,hn[n]);
		else
			if((n % 10) == 1)
				printf("The %dst humble number is %d.\n",n,hn[n]);
			else
				if((n % 10) == 2)
					printf("The %dnd humble number is %d.\n",n,hn[n]);
				else
					printf("The %drd humble number is %d.\n",n,hn[n]);
	}
	
	return 0;
}
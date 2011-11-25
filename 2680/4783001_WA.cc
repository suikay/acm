#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n,left,right,onep,zerop,tmp;
	string ori,cpy;
	while(cin >> n)
	{
		onep = zerop = 0;
		left = 0;
		right = 1;
		for(int i = 1; i < n; i++){
			if(left == 0)
				tmp = onep + 1 + zerop;
			else
				tmp = onep + zerop;
			onep = zerop + onep;
			zerop = tmp;
			left = 1 - left;
		}
		cout << zerop << endl;		
	}
	return 0;
}
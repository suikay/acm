#include<iostream>
using namespace std;
int main()
{
	int n,left,tmp;
	int zerop[1010],onep[1010];
	zerop[1] = onep[1] = 0;
	left = 0;
	for(int i = 2; i <= 1000; i++)	{
		zerop[i] = onep[i] = zerop[i-1] + onep[i-1];
		if(left == 0){
			left = 1;
			zerop[i]++;
		}
		else
			left = 0;
	}
	while(cin >> n)
	{
		cout << zerop[n] << endl;
	}
	return 0;
}

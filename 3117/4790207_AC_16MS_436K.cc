#include<string>
#include<iostream>
using namespace std;
int main()
{
	string d;
	int t,m,sum,p;
	while(cin >> t >> m)
	{
		sum = 0;
		if(!t&&!m)
			break;
		for(int i = t; i > 0; i--){
			cin >> d >> p;
			sum += p;
		}
		cout << m*3 - sum << endl;
	}
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		if(!a&&!b&&!c&&!d)
			break;
		cout << a+c-b << endl;
	}
	return 0;
}
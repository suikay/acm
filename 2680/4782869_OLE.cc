#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	string ori,cpy;
	while(cin >> n)
	{
		cpy = ori = "10";
		for(int i = 1; i < n; i++)
		{
			for(int i = 0; i < cpy.size(); i++)
				cpy[i] = '0'+(1-(cpy[i]-'0'));
			ori += cpy;
			cpy = ori;
		}
		int res(0);
		for(int i = 1; i < ori.size(); i++)
			if(ori[i]=='0' && ori[i-1] == '0')
				res++;
		cout << ori << endl;
		cout << res << endl;
	}
	return 0;
}
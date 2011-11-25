#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int f(string& x)
{
	return (atoi(x.c_str()));
}
int main()
{
	string sen;
	int pls,eq;
	while(cin >> sen)
	{
		for(int i = 0; i < sen.size(); i++)
			if(sen[i] == '+')
				pls = i;
			else
				if(sen[i] == '=')
					eq = i;
		string a(sen.begin(),sen.begin()+pls);
		string b(sen.begin()+pls,sen.begin()+eq);
		string c(sen.begin()+eq,sen.end());
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		reverse(c.begin(),c.end());
		if((f(a)+f(b)) == f(c))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
	return 0;
}
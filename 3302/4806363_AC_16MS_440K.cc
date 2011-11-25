#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
bool f(string& s1,string& s2)
{
	int x(0);
	for(int i = 0;(x < s2.size()) && i < s1.size(); i++)
		if(s1[i] == s2[x])
			x++;
	if(x == s2.size())
		return true;
	return false;
}
int main()
{
	string s1,s2;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> s1 >> s2;
		string s3(s2);
		reverse(s2.begin(),s2.end());
		//cout << s1.find(s2) << endl;
		if(f(s1,s2) || f(s1,s3))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
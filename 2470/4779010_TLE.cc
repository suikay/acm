#include<vector>
#include<iostream>
using namespace std;
bool equal(vector<int>& x,vector<int>& y)
{
	int sz = x.size();
	for(int i = 0; i < sz; i++)
		if(x[i] != y[i])
			return false;
	return true;
}
int main()
{
	int n,tmp;
	while(cin >> n && n)
	{
		vector<int>p1(n+1,0),p2(n+1,0);
		for(int i = 1; i <= n; i++){
			cin >> tmp;
			p1[i] = tmp;
			p2[tmp] = i;
		}
		if(equal(p1,p2))
			cout << "ambiguous" << endl;
		else
			cout << "not ambiguous" << endl;
	}
	return 0;
}
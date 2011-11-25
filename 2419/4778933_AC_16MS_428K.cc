#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	vector<string> set;
	int p,t;
	cin >> p >> t;
	string tmp('k',t);
	for(int i = 0; i < p; i++)
		set.push_back(tmp);
	int x,y;
	while(cin >> x >> y)
		set[x-1][y-1] = '1';
	sort(set.begin(),set.end());
	int res = 0;
	string last = tmp;
	for(int i = 0; i < p; i++)
		if(last != set[i]){
			last = set[i];
			res++;
		}
	cout << res << endl;
	return 0;
}
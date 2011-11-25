#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string res(1200,0),tmp;
	while(cin >> tmp)
	{
		if(tmp.size() == 1 && tmp[0] == '0')
			break;
		reverse(tmp.begin(),tmp.end());
		for(int i = 0; i < tmp.size(); i++)
			res[i] += tmp[i] - '0';
	}
	for(int i = 0; i < res.size()-1; i++){
		res[i+1] += res[i]/10;
		res[i] %= 10;
		res[i] += '0';
	}
	res[res.size()-1] += '0';
	int i;
	for(i = res.size() - 1; i > 0; i--)
		if(res[i] != '0')
			break;
	while(i >= 0)
		cout << res[i--];
	cout  << endl;
	return 0;
}
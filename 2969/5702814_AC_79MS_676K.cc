#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
void put(string x)
{
	if(x.size() == 0)
		cout << "impossible" << endl;
	else if(x[0] == '0')
		cout << "0" << endl;
	else
		cout << x << endl;
}
int cnt[10];
int main()
{
	string tmp;
	int sum,now;
	cin >> tmp;
	for(int i = tmp.size()-1; i >= 0; i--) {
		now = tmp[i] - '0';
		cnt[now]++;
		sum += now;
	}
	if(cnt[0] == 0 && cnt[5] == 0)
	{
		printf("impossible\n");
		return 0;
	}
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	if(cnt[0] == 0) {
		tmp.erase(tmp.find('5'),1);
		tmp += "5";
	}
	if((sum % 3) == 0) {
		put(tmp);
		return 0;
	}
	if((sum % 3) == 1) {
		for(int i = tmp.size()-2; i >= 0; i--) {
			if((tmp[i]-'0') % 3 == 1) {
				tmp.erase(tmp.begin()+i);
				put(tmp);
				return 0;
			}
		}
		for(int i = tmp.size()-2; i >= 0; i--)
			if((tmp[i]-'0') % 3 == 2) {
				for(int j = i - 1; j >= 0; j--)
					if((tmp[j]-'0') % 3 == 2) {
						tmp.erase(tmp.begin()+i);
						tmp.erase(tmp.begin()+j);
						put(tmp);
						return 0;
					}
				break;
			}
		cout << "impossible" << endl;
	} else {
		for(int i = tmp.size()-2; i >= 0; i--) {
			if((tmp[i]-'0') % 3 == 2) {
				tmp.erase(tmp.begin()+i);
				put(tmp);
				return 0;
			}
		}
		for(int i = tmp.size()-2; i >= 0; i--)
			if((tmp[i]-'0') % 3 == 1) {
				for(int j = i - 1; j >= 0; j--)
					if((tmp[j]-'0') % 3 == 1) {
						tmp.erase(tmp.begin()+i);
						tmp.erase(tmp.begin()+j);
						put(tmp);
						return 0;
					}
				break;
			}
		cout << "impossible" << endl;
	}


	return 0;
}
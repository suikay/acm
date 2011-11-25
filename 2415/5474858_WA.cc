#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n,p[3],dis[55][55];
	char m[55][55];
	while(cin >> n && n)
	{
		cin >> p[0] >> p[1] >> p[2];
		for(int i = 0; i < 3; i++)
			p[i]--;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> m[i][j];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(i != j) {
					if(m[i][i] == m[i][j])
						dis[i][j] = 1;
					else
						dis[i][j] = 999999;
				}
				else
					dis[i][i] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					if(m[j][j] == m[i][k] && 
						( dis[j][i] + dis[i][k] < dis[j][k])) {
							dis[j][k] = dis[j][i] + dis[i][k];
						}
		int res = 9999999;
		for(int i = 0; i < n; i++) {
			int tmp = dis[p[0]][i] + dis[p[1]][i] + dis[p[2]][i];
			if(tmp < res) {
				//cout << i << endl;
				res = tmp;
			}
		}
		if(res < 300)
			cout << res << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}
	
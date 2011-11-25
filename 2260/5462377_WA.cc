#include<iostream>
#include<string.h>
using namespace std;
int m[110][110];
int main()
{
	int n,r[110],c[110];
	while(cin >> n && n) 
	{
		bool v(true);
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				cin >> m[i][j];
				if(m[i][j] == 1) {
					r[i]++;
					c[j]++;
				}
			}
		int cc,rr;
		cc = rr = -1;
		for(int i = 0; i < n; i++) {
			if(r[i] % 2) {
				if(rr == -1)
					rr = i;
				else
					v = false;
			}
			if(c[i] % 2) {
				if(cc == -1)
					cc = i;
				else
					v = false;
			}
		}
		if(v == false)
			cout << "Corrupt" << endl;
		else
		if(rr == -1 && cc == -1)
			cout << "OK" << endl;
		else {
				if(m[rr][cc] == 1)
					cout << "Change bit (" << rr+1 << "," << cc+1 << ")" << endl;
				else
					cout << "Corrupt" << endl;
			}
	}
	return 0;
}



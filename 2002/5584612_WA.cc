#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int P(9999991),N(1000000);
int hash[N];
unsigned int next[N];
int sx[N],sy[N],dx[N],dy[N],x[1000],y[1000];
int main()
{
	int n,now,h1,cnt,tmpx,tmpy,pn;
	unsigned int _mid;
	bool success;
	while(scanf("%d",&n) && n)
	{
		memset(next,0,sizeof(next));
		memset(hash,0,sizeof(hash));
		cnt = 0;
		pn = 1;
		for(int i = 0; i < n; i++) {
			scanf("%d%d",x+i,y+i);
//			x[i] += 20000;
//			y[i] += 20000;
		}
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
			{
				success = false;
				sx[pn] = x[i] + x[j];
				sy[pn] = y[i] + y[j];
				dx[pn] = abs(x[i] - x[j]);
				dy[pn] = abs(y[i] - y[j]);
//				cout << sx[pn] << " " << sy[pn] << " " << dx[pn] << " " << dy[pn] << endl;
				_mid = (((unsigned int)sx[pn]) << 16) + sy[pn];
//				cout << _mid << endl;
				now = _mid % P;
				h1 = hash[now];
				while(!success && h1)
				{
//					cout << "HERE " << sx[h1] << " " << sy[h1] << " " << sx[pn] << " " << sy[pn] << endl;
//					cout << dx[h1] << dy[h1] << dx[pn] << dy[pn] << endl;
					if(sx[h1] == sx[pn] && sy[h1] == sy[pn] &&
						((dx[h1]*dx[pn]) == (dy[pn]*dy[h1]))) {
							success = true;
					}
					h1 = next[h1];
				}
				if(!success) {
					next[pn] = hash[now];
					hash[now] = pn++;
				}
				else
					cnt++;
			}
		printf("%d\n",cnt);
	}

	return 0;
}

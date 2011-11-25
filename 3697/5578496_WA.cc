#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
using namespace std;
bitset<10001> ori[10001],pp;
int next[10001];
int main()
{
	bitset<10001> tmp;
	pp.flip();
	int a,b,x,y,now,last;
	bool ok;
	while(scanf("%d%d",&a,&b))
	{
		bitset<10001> clean;
		for(int i = 1; i <= a; i++)
			clean[i] = 1;
		if(!a && !b)
			return 0;
		for(int i = 1; i <= a; i++) {
			ori[i] = clean;
			next[i] = i+1;
		}
		next[a] = 1;
		for(int i = 0; i < b; i++) {
			scanf("%d%d",&x,&y);
			ori[x][y] = 0;
			ori[y][x] = 0;
		}
		last = a;
		now = 1;
		for(int i = a; i >= 1; i--) {
			ok = false;
			for(int cnt = 0;cnt < 2 ;) {
				if(ori[1][now] == 1) {
					ori[1] |= ori[now];
					ok = true;
					break;
				}
				else {
					last = now;
					now = next[now];
				}
				if(next[now] <= now)
				cnt++;
			}
			if(!ok)
				break;
			next[last] = next[now];
		}
		printf("Case %d: %d",ori[1].count()-1);
	}

	return 0;
}
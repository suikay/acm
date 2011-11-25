#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
char map[4][4];
int over()
{
	int cnt(0);
	char c1,c2;
	bool f1,f2;
	for(int i = 0; i < 3; i++) {
		f1 = true; c1 = map[i][0];
		f2 = true; c2 = map[0][i];
		for(int j = 1; j < 3; j++) {
			if(c1 != map[i][j])
				f1 = false;
			if(c2 != map[j][i])
				f2 = false;
		}
		if(f1) cnt++;
		if(f2) cnt++;
	}
	if(map[0][0] == map[1][1] && map[1][1] == map[2][2])
		cnt++;
	if(map[0][2] == map[1][1] && map[1][1] == map[2][0])
		cnt++;
	return cnt;
}
int main()
{
	int t,xx,oo,tmp;
	cin >> t;
	while(t--)
	{
		xx = oo = 0;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				cin >> map[i][j];
				if(map[i][j] == 'X')	xx++;
				if(map[i][j] == 'O')	oo++;
			}
		tmp = over();
		if(tmp > 1 || (tmp == 1 && oo >= xx) ||
			oo > xx)
			puts("no");
		else
			puts("yes");
	}
	return 0;
}

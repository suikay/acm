#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;
char str[2][100009];
bool flag;
int i,j,len[2],last;
int main()
{
	while (	cin >> str[0]>> str[1])
	{
		flag = false;
		len[0] = strlen(str[0]);
		len[1] = strlen(str[1]);
		last = 0;
		for ( i = 0 ; i < len[1] ; i ++)
			while (last < len[0] && str[0][last] == str[1][i]) {
					last ++;
					break;
			}
		if (last == len[0])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
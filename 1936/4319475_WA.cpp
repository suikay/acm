#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;
char str[2][100009];
bool flag;
int i,j,len[2],last;
int main()
{
	while (		cin >> str[0])
	{
		cin >> str[1];
		flag = false;
		len[0] = strlen(str[0]);
		len[1] = strlen(str[1]);
		last = 0;
		for ( i = 0 ; i < len[0] ; i ++)
				while (last < len[1] && str[1][last] != str[0][i])
					last ++;
		if (last != len[1])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
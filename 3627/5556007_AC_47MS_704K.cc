#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int x[21000],s;
	int n;
	scanf("%d%d",&n,&s);
	for(int i = 0; i < n; i++)
		scanf("%d",x+i);
	sort(x,x+n);
	int cnt(0);
	for(int i = n-1;s > 0 && i >= 0; i--,cnt++)
		s -= x[i];
	cout << cnt << endl;

	return 0;
}
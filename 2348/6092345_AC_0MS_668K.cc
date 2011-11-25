#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

bool win(int x,int y)
{
	if(x % y == 0)
		return true;
	if(y/x > 1)
		return true;
	if(win(y%x,x))
		return false;
	return true;
}

int main()
{
	int x,y;
	while(true)
	{
		scanf("%d%d",&x,&y);
		if(!x && !y)
			return 0;
		if(x > y)
			swap(x,y);
		if(win(x,y))
			puts("Stan wins");
		else
			puts("Ollie wins");
	}

	return 0;
}

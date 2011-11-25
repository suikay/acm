#include <stdio.h>
#include <iostream>
using namespace std;
int list[15];
bool joseph(int x,int y)
{
	int pos(0);
	for(int i = 2*y; i > y; i--)
	{
		pos = (pos + x % i  + i) % i;
		if(pos > 0 && pos <= y)
			return false;
		pos = (pos-1+i)%i;
	}
//	cout << y << " " << x << endl;
	return true;
}
void LIST()
{
	for(int i =	1; i < 14; i++)
		for(int j = i+1;true; j++)
			if(joseph(j,i)) {
				list[i] = j;
				break;
			}
}
int main()
{
	LIST();
	int n;
	while(scanf("%d",&n) && n)
		printf("%d\n",list[n]);
	return 0;
}
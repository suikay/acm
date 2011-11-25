#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const int des = 65535;
int move[16];
int f(int x,int y)
{
	if(x >= 0 && x < 4 && y >= 0 && y < 4)
		return x*4+y;
	else
		return -1;
}
int add(int x,int y)
{
	static int p;
	p = f(x,y);
	if(p < 0)
		return 0;
	return (1 << p);
}
void init()
{
	int p;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++){
			p = add(i,j);
			p |= add(i-1,j);
			p |= add(i,j-1);
			p |= add(i+1,j);
			p |= add(i,j+1);
			move[i*4+j] = p;
	}
}
int status[100000],steps[100000];
bool v[100000];
int bfs(int ori)
{
	memset(v,false,sizeof(v));
	int top,end,tt;
	if(ori == 0 || ori == des)
		return 0;
	top = end = 0;
	status[end] = ori;
	v[ori] = true;
	steps[end++] = 0;
	while(top < end)
	{
		tt = status[top];
		for(int i = 0; i < 16; i++)
			if(!v[tt^move[i]]) {
				status[end] = tt^move[i];
				steps[end] = steps[top] + 1;
				if(status[end] == 0 || status[end] == des)
					return steps[end];
				v[status[end]] = true;
				end++;
			}
		top++;
	}
	return -1;
}

int main()
{
	char pp;
	int ori(0);
	init();
	for(int i = 0; i < 16; i++) {
		cin >> pp;
		if(pp == 'b')
			ori |= (1 << i);
	}
	cout << bfs(ori) << endl;

	return 0;
}
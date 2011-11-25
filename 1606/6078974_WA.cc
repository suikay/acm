#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int st[1000000],top;
bool v[1010][1010];
int a, b, want, more;
void output()
{
	for(int i = 0; i < top; i++)
		switch(st[i]) {
			case 1:	puts("fill A");		break;
			case 2: puts("fill B");		break;
			case 3: puts("empty A");	break;
			case 4: puts("empty B");	break;
			case 5: puts("pour A B");	break;
			case 6: puts("pour B A");	break;
	}
	puts("success");
}
bool dfs(int x,int y)
{
	if(y == want) {
		output();
		return true;
	}		
	if(v[x][y])
		return false;
	v[x][y] = true;
	if(x != a) {
		st[top++] = 1;
		if(dfs(a,y))
			return true;
		top--;
	}
	if(y != b) {
		st[top++] = 2;
		if(dfs(x,b))
			return true;
	}
	if(x != 0) {
		st[top++] = 3;
		if(dfs(0,y))
			return true;
		top--;
	}
	if(y != 0) {
		st[top++] = 4;
		if(dfs(x,0))
			return true;
		top--;
	}
	if(x != 0 && y != b) {
		st[top++] = 3;
		more = min(x,b-y);
		if(dfs(x-more,y+more))
			return true;
		top--;
	}
	if(y != 0 && x != a) {
		st[top++] = 4;
		more = min(a-x,y);
		if(dfs(x+more,y-more))
			return true;
		top--;
	}
	return false;
}
int main()
{
	while(scanf("%d%d%d",&a,&b,&want) == 3) {
		memset(v,false,sizeof(v));
		top = 0;
		dfs(0,0);
	}

	return 0;
}

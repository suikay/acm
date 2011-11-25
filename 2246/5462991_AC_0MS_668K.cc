#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct M {
	int r,c;
	M(int a,int b) {
		this->r = a;
		this->c = b;
	}
	M() {}
}M;
M m[300];
int count;
bool valid(true);
M cal(M &a ,M &b)
{
	if(a.c != b.r)
		valid = false;
	count += a.r * a.c * b.c;
	return M(a.r,b.c);
}
M dfs()
{
	char a;
	M t1,t2;
	if(!(cin >> a))
		exit(0);
	if(a == '(') { 
		t1 = dfs();
		t2 = dfs();
		cin >> a;
		return cal(t1,t2);
	}
	return m[a];
}
int main()
{
	int n;
	char tmp;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		cin >> m[tmp].r >> m[tmp].c ;
	}
	while(true)
	{
		count = 0;
		valid = true;
		dfs();
		if(valid)
			printf("%d\n",count);
		else
			printf("error\n");
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define STUDENT 310
#define COURSE 110
bool connect[COURSE][STUDENT];
bool check[STUDENT];
int match[COURSE];
int student,course;
void input()
{
	int cnt,s;
	scanf("%d%d",&course,&student);
	memset(match,-1,sizeof(match));
	memset(connect,false,sizeof(connect));

	for(int i = 0; i < course; i++) {
		scanf("%d",&cnt);
		for(int j = 0; j < cnt; j++) {
			scanf("%d",&s);
			connect[i][s] = true;
		}
	}
}

bool dfs(int x)
{
	int tmp;
	//cout << " H " << x << endl;
	for(int i = 1; i <= student; i++)
		if(connect[x][i] && !check[i])
		{
			check[i] = true;
			if((match[i] == -1 || dfs(match[i])))
			{
				match[i] = x;
				return true;
			}
		}
	return false;
}

bool MaxMatch()
{
	for(int i = 0; i < course; i++)
	{
		memset(check,false,sizeof(check));
		if(!dfs(i))
			return false;
	}

	return true;
}

int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		input();
		if(MaxMatch())
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}

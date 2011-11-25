#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define STUDENT 310
#define COURSE 110
bool connect[COURSE][STUDENT];
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
		if(connect[x][i])
		{
			if(match[i] == -1) {
				match[i] = x;
				return true;
			}
			else {
				tmp = match[i];
				connect[tmp][i] = false;
				if(dfs(tmp)) {
					match[i] = x;
					return true;
				}
				connect[tmp][i] = true;
			}
		}
	return false;
}

bool MaxMatch()
{
	for(int i = 0; i < course; i++)
		if(!dfs(i))
			return false;
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

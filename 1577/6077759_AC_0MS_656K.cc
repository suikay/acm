#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
///using namespace std;
int left[100],right[100];
char tmp[100][100];
void add(int root,int op)
{
	if(root > op) {
		if(!left[root])
			left[root] = op;
		else
			add(left[root],op);
	} else {
		if(!right[root])
			right[root] = op;
		else
			add(right[root],op);
	}
}

void out(int root)
{
	putchar(root+'A'-1);
	if(left[root])
		out(left[root]);
	if(right[root])
		out(right[root]);
}

int main()
{
	int root,k;
	while(true)
	{
		k = 0;
		while(true) {
			scanf("%s",tmp[k]);
			if(tmp[k][0] == '*' || tmp[k][0] == '$')
				break;
			k++;
		}
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		root = tmp[k-1][0] - 'A' + 1;
		for(int i = k-2; i >= 0; i--) 
			for(int j = 0; j < strlen(tmp[i]); j++)
				add(root,tmp[i][j]-'A'+1);
		out(root);
		putchar('\n');
		if(tmp[k][0] == '$')
			return 0;
	}

	return 0;
}

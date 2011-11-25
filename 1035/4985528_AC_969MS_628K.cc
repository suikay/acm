#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
char dic[10050][20];
//char dicn[10050][20];
int n;
bool com(char* a,char* b)
{
	if(strlen(a) != strlen(b))	{
		if(strlen(a) > strlen(b))
			swap(a,b);
		int as = strlen(a),bs = strlen(b);
		int j = 0;
		for(; j < as; j++)
			if(a[j] != b[j])
				break;
		for(;j < as; j++)
			if(a[j] != b[j+1])
				break;
		if(j == as)
			return true;
		else
			return false;
	}
	else	{
		int sz = strlen(a);
		int j = 0; 
		for(; j < sz; j++)
			if(a[j] != b[j])
				break;
		j++;
		for(;j < sz; j++)
			if(a[j] != b[j])
				break;
		if(j == sz)
			return true;
		else
			return false;
	}
}

int main()
{
	n = 0;
	int sz;
	int top ,queue[10040];
	int flag;
	char tmp[20];
	while(true)
	{
		cin >> dic[n];
		if(dic[n][0] == '#')
			break;
		else
			n++;
	}
	//sort(dic,dic+n);
	while(true)
	{
		cin >> tmp;
		if(tmp[0] == '#')
			break;
		else
		{
			top = 0;
			sz = strlen(tmp);
			flag = -1;
			for(int i = 0; i < n && flag<0; i++)
			{
				if(abs((int)(sz - strlen(dic[i]))) > 1)
					continue;
				else{
					if(strcmp(tmp,dic[i]) == 0)
						flag = i;
					else
						if(com(tmp,dic[i]))
							queue[top++] = i;
					}
			}
			if(flag < 0)	{
				printf("%s:",tmp);
				for(int k = 0; k < top ;k++)
					printf(" %s",dic[queue[k]]);
			}
			else
				printf("%s is correct",tmp);
			printf("\n");
		}
	}
	return 0;
}
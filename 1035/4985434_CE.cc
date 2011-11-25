#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string dic[10050];
int dicn[10050];
int n;
/*
bool find(string want)
{
	int left(0),right(n);
	int mid((left+right)/2);
	while(dic[mid] != want)
		if(dic[mid].compare(want) == -1)
		{
			if(left == mid)
				return false;
			left = mid;
			mid = (left+right)/2;
		}
		else
		{
			if(right == mid)
				return false;
			right = mid;
			mid = (left + right)/2;
		}
	return true;
}
*/
bool com(string a,string b)
{
	if(a.size() != b.size())	{
		if(a.size() > b.size())
			swap(a,b);
		int as = a.size(),bs = b.size();
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
		int sz = a.size();
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
	string tmp;
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
			sz = tmp.size();
			flag = -1;
			for(int i = 0; i < n && flag<0; i++)
			{
				if(abs(sz - dic[i].size()) > 1)
					continue;
				else{
					if(tmp == dic[i])
						flag = i;
					else
						if(com(tmp,dic[i]))
							queue[top++] = i;
					}
			}
			if(flag < 0)	{
				cout << tmp << ":";
				for(int k = 0; k < top ;k++)
					cout << " " << dic[queue[k]] ;
			}
			else
				cout << tmp << " is correct" ;
			cout << endl;
		}
	}
	return 0;
}
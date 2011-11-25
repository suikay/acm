#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
	int n,min;
	int record[11];
	char result[20];
	bool flag;
	while(true) {
		flag = true;
		memset(record,0,11* sizeof(int));
		while(true) {
			cin >> n;
			if(!n)
				break;
			getchar();
			gets(result);
			if(result[4] == 'h')
				if(record[n] < 0)
					flag = false;
				else
					record[n] = 1;
			else 
				if(result[4] == 'l')
					if(record[n] > 0)
						flag = false;
					else
						record[n] = -1;
				else 
					break;
		}
		if(!n)
			break;
		for(int i = 1; flag && i < n ;i++)
			if(record[i] == 1)
			{
				flag = false;
				break;
			}
		for(int j = 10;flag && j > n;j--)
			if(record[j] == -1)
			{
				flag = false;
				break;
			}
		if(flag)
			printf("Stan may be honest\n");
		else
			printf("Stan is dishonest\n");
	}
}
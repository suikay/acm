#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//#define abs(x) ((x)>0)?(x):(-(x))
#define max(x,y) x > y? x:y
int main()
{
	string s;
	int n;
	scanf("%d\n",&n);
	for(int i = 0; i < n ;i++) {
		int y1,y2;
		char x1,x2;
		getline(cin,s);
		stringstream ss(s);
		char dummy;
		ss >> x1 >> y1 >>x2 >> y2;
		int x = abs(x1-x2);
		int y = abs(y1-y2);
		if(!x&&!y){
			printf("0 0 0 0\n");
			continue;
		}
		printf("%d ",max(x,y));
		if(x==y||!x || !y)
			printf("1 ");
		else
			printf("2 ");
		if(!x||!y)
			printf("1 ");
		else
			printf("2 ");
		if(x==y)
			printf("1\n");
		else
			if((abs(y-x)%2)!=0)
				printf("Inf\n");
			else
				printf("2\n");
	}
	return 0;
}
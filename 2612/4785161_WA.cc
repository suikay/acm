#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char tmp;
	char touch[13][13];
	int count[13][13] = {0};
	int x[] = {-1,-1,-1,0,1,1,1,0},y[]={1,0,-1,-1,-1,0,1,1};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> tmp;
			if(tmp == '*')
				for(int k = 0; k < 8; k++)
					count[i+x[k]][j+y[k]]++;
			touch[i][j] = tmp;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> tmp;
			if(tmp == 'x')
				if(touch[i][j] != '*')
					printf("%d",count[i][j]);
				else
					printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
	return 0;
}
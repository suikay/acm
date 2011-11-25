#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char tmp;
	char touch[13][13],get[13][13];
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
	bool flag = false;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			cin >> get[i][j];
			if(get[i][j]== 'x' && touch[i][j] == '*')
				flag = true;
		}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			switch(touch[i][j]){
				case '*':	if(flag)
								putchar('*');
							else
								putchar('.');
					break;
				case '.':	if(get[i][j] == 'x')
								cout << count[i][j];
							else
								putchar('.');
		}
		cout << endl;
	}
	return 0;
}
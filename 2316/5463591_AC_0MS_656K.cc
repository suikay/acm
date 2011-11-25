#include<string>
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	string ori;
	int arr[20];
	memset(arr,0,sizeof(arr));
	while(cin >> ori)
		for(int i = 0; i < ori.size(); i++)
			arr[i] = (arr[i] + ori[i]-'0') % 10;
	for(int i = 0; i < ori.size();i++)
		cout << arr[i];
	cout << endl;
	return 0;
}

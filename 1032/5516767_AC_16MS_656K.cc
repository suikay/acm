#include <iostream>
using namespace std;
int sum[100];
void init()
{
	sum[0] = -1;
	for(int i = 1; i < 100; i++)
		sum[i] = sum[i-1] + i;
}

int main()
{
	int n,i,arr[100];
	init();
	cin >> n;
	for(i = 2; i < 100; i++)
		if(sum[i] > n)
			break;
	--i;
	int last = n - sum[i];
	for(int j = 0; j < i-1; j++)
		arr[j] = j+2;
	for(int j = i-2; last && j >= 0; j--,last--)
		arr[j]++;
	arr[i-2] += last;
	for(int j = 0; j < i-2; j++)
		cout << arr[j] << " ";
	cout << arr[i-2] << endl;
	return 0;
}
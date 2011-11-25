#include<iostream>
using namespace std;
int main()
{
	int matrix[360][360]={0};
	int n,tmp;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
		{
			cin >> tmp;
			matrix[i][j] += tmp;
			if(matrix[i+1][j] < matrix[i][j])
				matrix[i+1][j] = matrix[i][j];
			if(matrix[i+1][j+1] < matrix[i][j])
				matrix[i+1][j+1] = matrix[i][j];
		}
	int res(0);
	for(int i = 1;i <= n; i++)
		if(res < matrix[n][i])
			res = matrix[n][i];
	cout << res << endl;
	return 0;
}
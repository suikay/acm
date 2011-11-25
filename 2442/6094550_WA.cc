#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int arr[110][2100],p[110];
int main()
{
	int t,sum,pn,now,m,n,np;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) 
				scanf("%d",&arr[i][j]);
			arr[i][n] = 10001;
			sort(arr[i],arr[i]+n+1);
		}
		sum = 0;
		for(int i = 0; i < m; i++) {
			sum += arr[i][0];
			p[i] = 1;
		}
		printf("%d",sum);
		for(int i = 1; i < n; i++) {
			now = 10001;
			np = 0;
			for(int j = 0; j < m; j++)
				if(arr[j][p[j]]-arr[j][p[j]-1] < now)	{
					now = arr[j][p[j]]-arr[j][p[j]-1];
					//cout << j << " " << p[j] << " " << now << endl;
					np = j;
				}
//			cout << now << endl;
			sum = sum+now;
			printf(" %d",sum);
			p[np]++;
		}
		puts("");
	}

	return 0;
}


#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
#define NIL -999999999.999999
#define NI 9999999999.9999
double ag[220][220];

int x[220],y[220];
int main()
{
	int n,tmp,mmax(0);
	double agn;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++){
		ag[i][i] = NI;
		for(int j = i+1; j < n; j++)	{
			if(x[i] == x[j])
				agn = NIL;
			else
				agn = 1.0*(y[i]-y[j])/(x[i]-x[j]);
			ag[i][j] = ag[j][i] = agn;
		}
	}
	for(int i = 0; i < n; i++){
		sort(ag[i],ag[i]+n);
		agn = -1;
		tmp = 1;
		for(int j = 0; j < n; j++){
			if(i == j)
				continue;
			if(ag[i][j] == agn)
				tmp++;
			else {
				if(tmp > mmax)
					mmax = tmp;
				tmp = 2;
				agn = ag[i][j];
			}
		}
		if(tmp > mmax)
			mmax = tmp;
	}
	cout << mmax << endl;
	return 0;
}
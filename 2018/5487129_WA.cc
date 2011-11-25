#include<iostream>
using namespace std;
int cows[110000];
int main()
{
	double nowlen,taillen,res(0.0);
	int n,ncows;
	int tailn,nown;
	cin >> n >> ncows;
	nowlen = taillen = 0.0;
	tailn = nown = 0;
	for(int i = 0; i < ncows; i++) {
		cin >> cows[i];
		nowlen += cows[i];
		nown++;
	}
	for(int i = ncows; i < n; i++) {
		cin >> cows[i];
		nowlen += cows[i];
		taillen += cows[i-ncows];
		nown++;
		tailn++;
		if(tailn && ((taillen/tailn) < (nowlen-taillen)/(nown-tailn))) {
			nowlen -= taillen;
			nown -= tailn;
			tailn = 0;
			taillen = 0;
		}
		if(nowlen / nown > res)
			res = nowlen/nown;
	}
	cout << (int)(res*1000 + 0.1) << endl;
	return 0;
}
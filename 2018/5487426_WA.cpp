#include<iostream>
#include<stdio.h>
using namespace std;
long long cows[110000];
int main()
{
	long long nowlen,taillen,res(0.0), n,ncows,tailn,nown;
	cin >> n >> ncows;
	nowlen = taillen = 0;
	tailn = nown = 0;
	for(int i = 0; i < ncows; i++) {
		cin >> cows[i];
		cows[i] *= 1000;
		nowlen += cows[i];
	}
	nown = ncows;
	for(int i = ncows; i < n; i++) {
		cin >> cows[i];
		cows[i] *= 1000;
		nowlen += cows[i];
		taillen += cows[i-ncows];
		nown++;
		tailn++;
		if(nowlen / nown > res)
			res = nowlen/nown;
		if(tailn && ((taillen/tailn) < (nowlen-taillen)/(nown-tailn))) {
			nowlen -= taillen;
			nown -= tailn;
			tailn = 0;
			taillen = 0;
		}
		if(nowlen / nown > res)
			res = nowlen/nown;
	}
	cout << res << endl;
	return 0;
}






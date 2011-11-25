#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
bool v[200000];
int pack[20000],p[6];
int main()
{
	int want,sum,j,pp,k(0);
	while(true)
	{
		++k;
		pp = 0;
		sum = 0;
		memset(v,false,sizeof(v));		
		for(int i = 0; i < 6; i++) {
			scanf("%d",p+i);
			sum += p[i]*(i+1);
		}
		if(sum == 0)
			return 0;
		if(sum % 2) {
			cout << "Collection #" << k << ":" << endl;
			cout << "Can't be divided." << endl;
			continue;
		}
		want = sum >> 1;
		sum = 0;
		for(int i = 0; i < 6; i++) {
			for(j = 1; p[i] > j; j <<= 1) {
				pack[pp++] = (i+1)*j;
				p[i] -= j;
			}
			if(p[i])
				pack[pp++] = p[i]*(1+i);
		}
		v[0] = true;
		for(int i = 0 ;i < pp; i++) {
			for(j = want - 1; j >= 0; j--)
				if(v[j])
					v[j+pack[i]] = true;
		}
		if(v[want]) {
			cout << "Collection #" << k << ":" << endl;
			cout << "Can be divided." << endl;
		}
		else {			
			cout << "Collection #" << k << ":" << endl;
			cout << "Can't be divided." << endl << endl;
		}
	}



	return 0;
}
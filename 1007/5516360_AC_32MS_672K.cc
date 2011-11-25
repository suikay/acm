#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int M(110);
struct DNA
{
	string str;
	int sortness;
	bool operator()(const DNA &a,const DNA &b) {
		if(a.sortness == b.sortness)
			return a.str < b.str;
		else
			return a.sortness < b.sortness;
	}
};
void cal(DNA &x)
{
	int sz = x.str.size(),sum(0);
	for(int i = 0; i < sz; i++)
		for(int j = i+1; j < sz; j++)
			if(x.str[i] > x.str[j])
				sum++;
	x.sortness = sum;
}
DNA dna[M];
int main()
{
	int m,n;
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		cin >> dna[i].str;
		cal(dna[i]);
	}
	sort(dna,dna+n,DNA());
	for(int i = 0; i < n; i++)
		cout << dna[i].str << endl;
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
const double pi = 3.1415926;
struct Pie
{
	double area,per;
	int div;
	bool operator<(const Pie &b) const{
		return this->per < b.per;
	}
};
Pie p[11000];
int main()
{
	int k,n,f,r;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&f);
		f++;
		for(int i = 0; i < n; i++) {
			scanf("%d",&r);
			p[i].area = pi*r*r;
			p[i].div = 1;
			p[i].per = p[i].area;
		}
		make_heap(p,p+n);
		for(int i = n; i < f; i++) {
			p[0].div++;
			p[0].per = p[0].area/p[0].div;
			pop_heap(p,p+n);
			push_heap(p,p+n);
		}
		sort(p,p+n);
		reverse(p,p+n);
		printf("%.4f\n",p[min(n,f)-1].per);
	}


	return 0;
}
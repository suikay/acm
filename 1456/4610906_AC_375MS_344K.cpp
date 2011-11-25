#include<stdio.h>
#include<algorithm>
#include<iostream>
#define N 10110
using namespace std;
typedef struct Product{
	int w;
	int dl;
	bool operator()(Product a,Product b){
		return a.w > b.w;
	}
}Product;
Product p[N];
bool get[N];
int n;
bool input()
{
	if(!(cin >> n))
		return false;
	for(int i = 0; i < n; i++)
		cin >> p[i].w >> p[i].dl;
		//scanf("%d%d",&(p[i].w),&(p[i].dl));
	sort(p,p+n,Product());
	return true;
}
int greed()
{
	int sum(0),j;
	memset(get,false,sizeof(get));
	for(int i=0; i<n; i++)	{
		j = p[i].dl;
		while(j >= 1 && get[j])
			j--;
		if(j>0)	{
			get[j] = true;
			sum += p[i].w;
		}
	}
	return sum;
}
int main()
{
	while(input())
		cout << greed() << endl;
	return 0;
}
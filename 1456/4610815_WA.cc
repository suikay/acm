#include<stdio.h>
#include<algorithm>
#define N 10010
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
	if(scanf("%d",&n)==0)
		return false;
	for(int i = 0; i < n; i++)
		scanf("%d%d",&p[i].w,&p[i].dl);
	sort(p,p+n,Product());
}
int greed()
{
	int sum(0),j;
	memset(get,false,sizeof(get));
	for(int i=0; i<n; i++)	{
		j = p[i].dl;
		while(j >= 1 && get[j])
			j--;
		if(j)	{
			get[j] = true;
			sum += p[i].w;
		}
	}
	return sum;
}
int main()
{
	while(input())
		printf("%d\n",greed());
	return 0;
}
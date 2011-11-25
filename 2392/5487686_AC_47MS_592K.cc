#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Brick {
	int a,c,h;
	bool operator()(const Brick &a,const Brick &b) {
		if(a.a == b.a)
			return a.h > b.h;
		else
			return a.a < b.a;
	}
};
Brick b[410];
bool v[41000];
int main()
{
	int k;
	scanf("%d",&k);
	for(int i = 0; i < k; i++)
		scanf("%d%d%d",&(b[i].h),&(b[i].a),&(b[i].c));
	sort(b,b+k,Brick());
	int height(0),mh(0);
	memset(v,false,sizeof(v));
	v[0] = true;
	for(int i = 0; i < k; i++) 
		for(int j = mh; j >= 0; j--)
			if(v[j+b[i].h])
				continue;
			else if(v[j]){
				height = j;
				for(int k = 0; k < b[i].c && (height+b[i].h  <= b[i].a); k++) {
					height += b[i].h;
					v[height] = true;
				}
				if(height > mh)
					mh = height;
			}
	printf("%d\n",mh);

	return 0;
}
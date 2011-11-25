#include<stdio.h>
#include<string.h>
int main()
{
	int n,k,last,complete,tmp;
	bool v[11000];
	scanf("%d%d",&n,&k);
	last = k;
	complete = 0;
	memset(v,false,sizeof(v));
	for(int i = 0; i < n; i++) {
		scanf("%d",&tmp);
		if(!v[tmp]) {
			v[tmp] = true;
			last--;
			if(last == 0) {
				memset(v,false,sizeof(v));
				last = k;
				complete++;
			}
		}
	}
	printf("%d\n",complete+1);
	return 0;
}
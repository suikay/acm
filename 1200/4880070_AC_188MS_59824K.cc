#include<stdlib.h>
#include<memory.h>
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX 5000000
#define P	3313
struct Hash{
	int hash;
	int next;
};
Hash h[MAX];
int c[MAX];
char x[MAX];
int main()
{
	int n,nc;
	while(scanf("%d%d\n",&n,&nc)!=EOF)
	{
		memset(c,0,sizeof(c));
		memset(h,0,sizeof(h));
		//printf("%d %d %d",sizeof(c),sizeof(h),sizeof(x));
		int tmp1,tmp2,zz,ptr = 1,res = 0;
		scanf("%s",x);
		bool flag;
		int len = strlen(x) - n + 1;
		for(int i = 0; i < len; i++)	{
			flag = true;
			tmp1 = 0;
			tmp2 = 0;
			for(int j = 0; j < n; j++){
				tmp1 = tmp1*26 + x[i+j]-'a';
				tmp2 = tmp2*P + x[i+j]-'a';
			}
			tmp1 = abs(tmp1)%MAX;
			tmp2 = abs(tmp2)%MAX;
			zz = c[tmp1];
			while(zz)
				if(h[zz].hash == tmp2){
					flag = false;
					break;
				}
				else
					zz = h[zz].next;
			if(flag){
				res++;
				h[ptr].hash = tmp2;
				h[ptr].next = c[tmp1];
				c[tmp1] = ptr++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}


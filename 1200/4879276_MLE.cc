#include<stdlib.h>
#include<memory.h>
#include<stdio.h>
#define MAX 50000000
//#define 
struct Hash{
	int hash;
	int next;
};
Hash h[MAX];
int c[MAX];
int main()
{
	memset(c,0,sizeof(c));
	int n,nc,tmp1,tmp2,zz,ptr = 1,res = 0;
	char x[1000000];
	scanf("%d%d\n",&n,&nc);
	scanf("%s",x);
	bool flag;
	int len = strlen(x) - n + 1;
	for(int i = 0; i < len; i++)	{
		flag = true;
		tmp1 = 0;
		tmp2 = 0;
		for(int j = 0; j < n; j++){
			tmp1 = tmp1*26 + x[i+j]-'a';
			tmp2 = x[i+j]^tmp2;
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
	return 0;
}
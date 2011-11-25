#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<iostream>
int min(int x,int y){
	return (x>y)?y:x;
}
char dna[11][25];
bool v[11];
int n,count,d[12][12],max,slen[12],sum;
void f(char *a,char *b,int &h,int &t)
{
	int tmp;
	int al=strlen(a),bl=strlen(b),i,j;
	for(i = 0;i < al; i++){
		if(a[i]==b[0]){
			tmp = min(al-i,bl);
			for(j=1; j<tmp; j++)
				if(a[i+j]!=b[j])
					break;
			if(j==tmp){
				h=tmp;
				break;
			}
			else
				h=0;
		}
	}
	for(i = 0;i < bl; i++){
		if(b[i]==a[0]){
			tmp = min(bl-i,al);
			for(j=1; j<tmp; j++)
				if(b[i+j]!=a[j])
					break;
			if(j==tmp){
				t=tmp;
				break;
			}
			else
				t=0;
		}
	}
}
void init()
{
	scanf("%d",&n);
	sum=0;
	for(int i=1; i<=n; i++){
		std::cin>>dna[i];
		slen[i]=strlen(dna[i]);
		sum+=slen[i];
	}
	for(int i=1; i<n; i++)
		for(int j=i+1; j<=n; j++)
			f(dna[i],dna[j],d[i][j],d[j][i]);
	memset(v,false,sizeof(v));
	max=0;
	count=0;
}
void dfs(int x,int len)
{
	if(count==n){
		if(len>max)
			max=len;
		return ;
	}
	for(int i=1; i<=n; i++)
		if(!v[i])	{
			v[i]=true;
			count++;
			if(slen[i]!=d[x][i])
				dfs(i,len+d[x][i]);
			else
				dfs(x,len+d[x][i]);
			count--;
			v[i]=false;
		}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)	{
		init();
		dfs(0,0);
		printf("%d\n",sum-max);
	}
	return 0;
}
		
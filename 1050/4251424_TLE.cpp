#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#define MAX_N 100
int matrix[MAX_N][MAX_N],temp[MAX_N][MAX_N];
int compare(const void *e1,const void *e2)
{
	int *c,*d;
	c=(int *)e1;
	d=(int *)e2;
	return *d-*c;
}
int main()
{
	int temp[MAX_N][MAX_N];
	int max=-9999,l,k,n,m,linetemp;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&matrix[i][j]);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			memset(temp,-9999,sizeof(temp));
			temp[i][j]=matrix[i][j];
			for(l=j+1;l<n;l++)
				temp[i][l]=temp[i][l-1]+matrix[i][l];
			for(k=i+1;k<m;k++){
				linetemp=0;
				for(l=j;l<n;l++){
					linetemp+=matrix[k][l];
					temp[k][l]=temp[k-1][l]+linetemp;
				}
			}
			qsort(temp,MAX_N*MAX_N,sizeof(int),compare);
			if(**temp>max){
				max=**temp;
			}
		}
		printf("%d",max);
		return 0;
}


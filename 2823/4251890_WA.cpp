#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int matrix[1000000];
int max[1000000];
int min[1000000];
int main()
{
	int maxi=-1,i,l,j,k,n;
	scanf("%d%d",&n,&k);
	memset(max,-9999,n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&matrix[i]);
	for(i=0;i<=(n-k);i++)
		for(j=i;j<i+k;j++)
			if(matrix[i]>=matrix[j]){
				if(matrix[i]>max[j])
					max[j]=matrix[i];
			}
			else
				if(max[i]<matrix[j])
					for(l=i;l<i+k;l++)
						max[l]=matrix[j];
	for(i=0;i<n;i++)
		printf("%d ",max[i]);
	return 0;
}

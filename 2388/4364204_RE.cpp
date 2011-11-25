#include <stdlib.h>
#include <stdio.h>
int CompareInt(const void *e1, const void *e2)
{
	return *((int * ) e1 ) - * (( int * )e2);
}
int main()
{
	int i,j,num;
	int data[100];
	scanf("%d",&num);
	for ( i = 0; i < num ; i++)
		scanf("%d",&data[i]);
	qsort(data,num,sizeof(int),CompareInt);
	printf("%d",data[num / 2]);
	return 0;
}

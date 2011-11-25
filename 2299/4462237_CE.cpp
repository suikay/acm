#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
unsigned long a[500005],b[500005];
unsigned long long count;
void Merge(int p,int q,int r)
{
	memcpy(b+p,a+p,r * sizeof(unsigned long));
	int i = p,j = q+1,k = p;
	while( i <= q && j <= r)
		if(b[i] < b[j])
			a[k++] = b[i++];
		else {
			count += q - i + 1;
			a[k++] = b[j++];
		}
	while( i <= q )
		a[k++] = b[i++];
	while( j <= r )
		a[k++] = b[j++];
}
void MergeSort(int p,int r)
{
	int q;
	if( p < r) {
		q = ( p + r) / 2;
		MergeSort(p,q);
		MergeSort(q+1,r);
		Merge(p,q,r);
	}
}

int main()
{
	unsigned long n,i;
	scanf("%u",&n);
	while( n > 0) {
		count = 0;
		for( i = 0; i < n;i++) 
			scanf("%d",&a[i]);
		MergeSort(0,n - 1);
		printf("%d\n",count);
		scanf("%d",&n);
	}
}
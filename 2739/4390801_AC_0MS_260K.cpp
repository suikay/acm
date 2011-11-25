#include <stdio.h>
int data[11000];
bool Npri[10000];
int main()
{
	int pri[2000], count = 0,sum,num;
	for ( int i = 2; i < 10001; i++)
		if(!Npri[i])
		{
			pri[count++] = i;
			sum = i * 2;
			while ( sum <= 10000) {
				Npri[sum] = true;
				sum += i;
			}
		}
	for ( int i = 0; i < count; i++) {
		sum = pri[i];
		for( int j = i + 1; sum <= 10000 && j < count; j++)
		{
			data[sum] ++;
			sum += pri[j];
		}
	}
	scanf("%d",&num) ;
	while(num) {
		printf("%d\n",data[num]);
		scanf("%d",&num) ;
	}
	return 0;
}
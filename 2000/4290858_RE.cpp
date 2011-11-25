#include<stdio.h>
int main()
{
	int data[10000],coin,day=1,maxplace,temp;
	scanf("%d",&temp);
	data[0] = 0;
	while(temp) {
		for(int i = 1;day <= 10000;i++)
			for(int j = 0; j < i && day <= 10000;j++) {
				data[day]=data[day-1] + i;
				day++;
			}
		printf("%d %d\n",temp ,data[temp]);
		scanf("%d",&temp);
	}
	return 0;
}
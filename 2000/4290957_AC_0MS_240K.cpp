#include<stdio.h>
int main()
{
	int data[10001],coin,wantday,day=1,maxplace,temp;
	scanf("%d",&wantday);
	temp = 0;
	for(int i = 1;day <= 10000;i++)
		for(int j = 0; j < i && day <= 10000;j++) {
				temp = data[day] = temp + i;
				day++;
		}
	while(wantday) {
		printf("%d %d\n",wantday ,data[wantday]);
		scanf("%d",&wantday);
	}
	return 0;
}
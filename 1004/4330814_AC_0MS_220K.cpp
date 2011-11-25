#include <stdio.h>
int main()
{
	float sum =0,temp;
	for( int i = 0; i < 12; i++) {
		scanf("%f",&temp);
		sum += temp*1000.0;
	}
	sum /= 12;
	if ((((int)sum)%10) > 4)
		printf("%3.2f",(sum+10)/1000);
	else
		printf("$%3.2f\n",sum/1000);
	return 0;
}
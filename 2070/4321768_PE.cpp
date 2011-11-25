#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(float a,float b)
{
	if (fabs( a - b) < 10e-4)
		return 1;
	if (a - b > 0.0)
		return 1;
	return 0;
}
int main()
{
	bool flag;
	float speed,weight,strength;
	scanf("%f%f%f",&speed,&weight,&strength);
	while ( fabs(speed - 0.0) > 10e-4)
	{
		flag = false;
		if (compare(4.5,speed) && compare(weight,150) && compare(strength,200)) {
			printf("Wide Receiver ");
			flag = true;
		}
		if (compare(6.0,speed) && compare(weight,300) && compare(strength,500))
			printf("%sLineman",flag?" ":(flag = true,""));
		if (compare(5.0,speed) && compare(weight,200) && compare(strength,300))
			printf("%sQuarterback",flag?" ":(flag = true,""));
		if (!flag)
			printf("No positions");
		printf("\n");
		scanf("%f%f%f",&speed,&weight,&strength);
	}
	return 0;
}
#include <stdio.h>
const double ESP(10e-5);
int main()
{
	double record[2000];
	record[0] = 0.0;
	for(int i = 1; i < 1000; i++)
		record[i] = record[i-1] + 1.0/(i+1);
	float num;
	while (scanf("%f",&num))
	{
		if(num <= ESP)
			break;
		for(int i = 1; i < 1000; i++)
			if(num + ESP <= record[i]) {
				printf("%d card(s)\n",i);
				break;
			}
	}
	return 0;
}
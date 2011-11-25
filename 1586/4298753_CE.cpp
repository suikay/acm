#include <stdio.h>
#include <math.h>
int main()
{
	float x[3],y[3],slide[3],temp,ttt;
	int equal = 0,i,j;
	scanf("%f",&x[0]);
	while (x[0] > -0.5)
	{
		scanf("%f%f%f%f%f",&y[0],&x[1],&y[1],&x[2],&y[2]);
		for ( i = 0; i < 3; i++)
			slide[i] = sqrt ((x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3])+(y[i] - y[(i + 1) % 3])*(y[i] - y[(i + 1) % 3]));
		for ( i = 0; i < 3; i++)
			for ( j = i + 1; j < 3; j++)
				if (slide[i] < slide[j]) {
					temp = slide[i];
					slide[i] = slide[j];
					slide[j] = temp;
				}
		if (slide[0]>(slide[1] + slide[2])
			printf("Not a Triangle\n");
		for ( i = 0; i < 2; i++)
			for ( j = i + 1; j < 3; j++)
				if (fabs(slide[i] - slide[j]) < 10e-4)
					equal ++;
		if (equal < 1)
			printf("Scalene ");
		else
			if (equal > 1) 
				printf("Equilateral ");
			else 
				printf("Isosceles ");
		ttt = (slide[0] *slide[0] - slide[1] * slide[1] - slide[2] * slide[2]);
		if (ttt > 10e-6)
			printf("Obtuse\n");
		else
			if (ttt < -10e-6)
				printf("Acute\n");
			else
				printf("Right\n");
		scanf("%f",&x[0]);
	}
	printf("End of Output\n");
	return 0;
}


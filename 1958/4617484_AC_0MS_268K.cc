#include<memory.h>
#include<stdio.h>
#define make(x,y) x=((x)>(y))?(y):(x)
int data[13][2];
int main()
{
	memset(data,0x7f,sizeof(data));
	//printf("%d\n",data[3][3]);
	for(int i=1; i<=12; i++)
		data[i][0]=(1<<i)-1;
	//printf("%d\n",data[2][0]);
	printf("1\n");
	data[1][1]=1;
	for(int i=2; i<=12; i++){
		for(int j=1; j<i; j++)
			make(data[i][1],data[j][0]+2*data[i-j][1]);
		printf("%d\n",data[i][1]);
	}
	return 0;
}


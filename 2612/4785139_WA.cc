#include<stdio.h>
int main()
{
	int n;
	scanf("%d\n",&n);
	char tmp;
	int count[12][12] = {0};
	int x[] = {-1,-1,-1,0,1,1,1,0},y[]={1,0,-1,-1,-1,0,1,1};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%c",&tmp);
			if(tmp == '*')
				for(int k = 0; k < 8; k++)
					count[i+x[k]][j+y[k]]++;
		}
		getchar();
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%c",&tmp);
			if(tmp == 'x')
				printf("%d",count[i][j]);
			else
				printf(".");
		}
		getchar();
		printf("\n");
	}
	return 0;
}
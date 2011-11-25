#include <stdio.h>
#include <string.h>
#include <memory.h>

int main()
{
	char son1[201],son2[201],dad[401];
	int i,num,j1,j2,j3,son1size,son2size;
	bool data1[401][201];
	scanf("%d",&num);
	for(i = 0; i < num ;i ++) {
		memset(data1,false,sizeof(data1));
		data1[0][0] = true;	
		scanf("%s",son1);
		son1size = strlen(son1);
		scanf("%s",son2);
		son2size = strlen(son2);
		scanf("%s",dad);
		for (j1 = 0; j1 < (strlen(dad)); j1++) {
			for (j2 = 0 ; j2 <= j1 && j2 <son1size ; j2++)
				if (data1[j1][j2] && dad[j1] == son1[j2]) 
					data1[j1+1][j2+1] = true;
			for ( j3 = 0 ; j3 <= j1 && j3 < son2size; j3++)
				if (data1[j1][j1-j3] && dad[j1] == son2[j3]) 
					data1[j1+1][j1-j3] = true;
		}
		if (data1[strlen(dad)][son1size])
			printf("Data set %d: yes\n",i+1);
		else
			printf("Data set %d: no\n",i+1);
	}
	return 0;
}
#include <stdio.h>
#include <string.h>
char names[105][20];
int dad[105];
int age[105];
int dis[105];
int find(char* name) {
	int i = 0;
	while(strcmp(names[i],name) && names[i][0] != '\0')
		i++;
	if(names[i][0] == '\0')
		sprintf(names[i],name);
	return i;
}
int main()
{
	int n,x,sdis;
	char sson[20],sdad[20];
	scanf("%d",&n);
	for( int i = 0; i < n; i++) {
		for(int k = 0; k < 105;k++)
			names[k][0] = '\0';
		memset(dad,0,sizeof(dad));
		memset(age,0,sizeof(age));
		age[0] = 100;
		sprintf(names[0],"Ted");
		scanf("%d",&x);
		for( int j = 1;j <= x;j++) {
			scanf("%s%s%d",sdad,sson,&sdis);
			dad[find(sson)] = find(sdad);
			dis[find(sson)] = sdis;
		}
		for( int i = 0;i < x;i++) {
			for( int j = 1; j <= x;j++)
				if(dad[j] == i)
					age[j] = age[i] - dis[j];
		}
		printf("DATASET %d\n",i+1);
		int maxage,maxi;
		char tname[100];
		for( int i = 1;i <= x;i++) {
			maxage = -1;
			tname ;
			for( int j = 1;j <= x;j++)
				if(maxage < age[j]) { 
					maxage = age[j];
					maxi = j;
					sprintf(tname,names[j]);
				}
				else
					if(maxage == age[j] && (strcmp(tname,names[j]) > 0)) {
						maxage = age[j];
						maxi = j;
						sprintf(tname,names[j]);
					}
			printf("%s %d\n",tname,maxage);
			age[maxi] = -1;
		}
	}
}

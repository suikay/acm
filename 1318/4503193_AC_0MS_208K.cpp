#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int compare(const void*a,const void *b)
{
	return *((char*)a) - *((char*)b);
}
typedef struct Dict {
	char ori[7];
	char uti[7];
	bool operator() (Dict a,Dict b) {
		if(strcmp(a.ori,b.ori) < 0)
			return true;
		else
			return false;
	}
} Dict;
Dict dict[101];
Dict word;
int main()
{
	char temp[7];
	int count = 0;
	bool flag;
	gets(temp);
	while(strcmp(temp,"XXXXXX")) {
		strcpy(dict[count].ori,temp);
		strcpy(dict[count].uti,temp);
		qsort(dict[count].uti,strlen(temp),sizeof(char),compare);
		count++;
		gets(temp);
	}
	sort(dict,dict + count,Dict());
	gets(temp);
	while(strcmp(temp,"XXXXXX")) {
		flag = false;
		qsort(temp,strlen(temp),sizeof(char),compare);
		for(int i = 0; i < count;i++)
			if(!strcmp(temp,dict[i].uti)) {
				printf("%s\n",dict[i].ori);
				flag = true;
			}
		if(!flag)
			printf("NOT A VALID WORD\n");
		printf("******\n");
		gets(temp);
	}
}

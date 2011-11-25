#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct Dic{
	char ori[15];
	char fo[15];
};
Dic d[100010];

int cmp(const void* a,const void* b)
{
	Dic* aa = (Dic*)a;
	Dic* bb = (Dic*)b;
	return strcmp(aa->fo,bb->fo);
	//if(!strcmp(aa->fo,bb->fo))
	//	return 0;
	//if(strcmp(aa->fo,bb->fo) > 0)
	//	return 1;
	//return -1;
}

int main()
{
	char tmp[100];
	int i(0);
	while(gets(tmp) && strlen(tmp)){
		sscanf(tmp,"%s%s",&(d[i].ori),&(d[i].fo));
		i++;
	}
	qsort(d,i,sizeof(Dic),cmp);
	Dic dtmp,*pos;
	while(gets(dtmp.fo))
	{
		pos = (Dic*)bsearch(&dtmp,d,i,sizeof(Dic),cmp);
		if(!pos)
			printf("eh\n");
		else
			printf("%s\n",pos->ori);
	}
	return 0;
}


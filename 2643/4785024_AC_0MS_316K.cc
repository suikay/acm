#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Can
{
	char name[100],pname[100];
	int votes;
};
Can c[30];

int cmp(const void* a,const void* b)
{
	Can* aa = (Can*)a;
	Can* bb = (Can*)b;
	return strcmp(aa->name ,bb->name);
}

int cmp2(const void* a,const void* b)
{
	Can* aa = (Can*)a;
	Can* bb = (Can*)b;
	return  -aa->votes+bb->votes;
}
int main()
{
	int n,m;
	scanf("%d\n",&n);
	for(int i = 0; i < n; i++){
		gets(c[i].name);
		gets(c[i].pname);
		c[i].votes = 0;
	}
	qsort(c,n,sizeof(Can),cmp);
	Can tmp,*pos;
	scanf("%d\n",&m);
	while(m--)	{
		gets(tmp.name);
		pos = (Can*)bsearch(&tmp,c,n,sizeof(Can),cmp);
		if(!pos)
			continue;
		pos->votes++;
	}
	qsort(c,n,sizeof(Can),cmp2);
	if(c[0].votes > c[1].votes)
		puts(c[0].pname);
	else
		puts("tie");
	return 0;
}
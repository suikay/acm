#include <stdio.h>
#include <string.h>
int main()
{
	char name[10],maxname[10],minname[10];
	int i,a,b,c,max,min,v,stu;
	scanf("%d",&stu);
	while ( stu > 0) {
		max  = -1;
		min = 999;
		for ( i = 0; i < stu ; i++)
		{
			scanf("%d%d%d%s",&a,&b,&c,&name);
			v = a*b*c;
			if ( v > max)
			{
				max = v;
				strcpy( maxname,name);
			}
			if ( v < min)
			{
				min = v;
				strcpy(minname,name);
			}
		}
		printf("%s took clay from %s.\n",maxname,minname);
		scanf("%d",&stu);
	}
	return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int i,j,telCount = 0,times[100000],data[26],num;
char telBook[100000][11],temp[11],c;
int mycompare(const void * elem1,const void * elem2)
{
	return (strcmp((char *)elem1,(char*)elem2));
}
int main()
{
	data[0]=data[1]=data[2]=2;
	data[3]=data[4]=data[5]=3;
	data[6]=data[7]=data[8]=4;
	data[9]=data[10]=data[11]=5;
	data[12]=data[13]=data[14]=6;
	data[15]=data[16]=data[17]=data[18]=7;
	data[19]=data[20]=data[21]=8;
	data[22]=data[23]=data[24]=data[25]=9;
	scanf("%d",&num);
	for (i = 0; i < num; i++)
	{
		for ( j = 0; j < 8; j ++) {
			if (j == 3) {
				temp[j] = '-';
				continue;
			}
			c = getchar();
			while ( c == '-' || c == '\n')
				c = getchar();
			if ( isdigit(c))
				temp[j] = c;
			else
				temp[j] ='0'+ data[c-'A'];
		}
		temp[j] = '\0';
		for ( j = 0; j  < telCount; j++)
			if (!strstr(telBook[j], temp))
				continue;
			else
			{
				telBook[j][9]++;
				break;
			}
		if ( j == telCount) {
			strcpy(telBook[telCount],temp);
			telBook[telCount][8] = ' ';
			telBook[telCount][9] = '1';
			telBook[telCount++][10] = '\0';
		}
	}
	qsort(telBook,telCount,11,mycompare);
	for(i = 0; i < telCount; i++)
		if ( telBook[i][9] > '1')
			printf("%s\n",telBook[i]);
	return 0;
}


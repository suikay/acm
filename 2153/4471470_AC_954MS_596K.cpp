#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data
{
	char names[35];
	int point;
}data;

int compare(const void *p1,const void *p2)
{
	data a=*(data *)p1;
	data b=*(data *)p2;
	if( strcmp(a.names,b.names) > 0)
		return 1;
	if( !strcmp(a.names,b.names))
		return 0;
	return -1;
}

int findPosition(data* D,int size,int mPosition)
{
	int temp = D[mPosition].point ,res = 1;
	for( int i = 0; i < size; i++)
		if( D[i].point > temp)
			res++;
	return res;
}

int main()
{
	data *Data;
	int i,j,n,m,posiMing;
	scanf("%d\n",&n);
	Data = new ( data[n]);
	for( i = 0; i < n;i++) {
		gets(Data[i].names);
		Data[i].point = 0;
	}
	qsort(Data,n,sizeof(data),compare);
	for( int i = 0; i < n;i++)
		if(!strcmp(Data[i].names ,"Li Ming")) {
			posiMing = i;
			break;
		}
	scanf("%d\n",&m);
	for( i = 0; i < m; i++) {
		data *position,temp ;
		for( j = 0; j < n; j++) {
			scanf("%d ",&temp.point);
			gets(temp.names);
			position = (data*) bsearch(&temp,Data,n,sizeof(data),compare);
			position->point += temp.point;
		}		
		printf("%d\n",findPosition(Data,n,posiMing));
	}
}
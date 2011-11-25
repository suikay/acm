#include <stdio.h>
int head[10001],end[10001];
int main()
{
	int num,i,j,temp,point,count,last,flag;
	scanf("%d",&num);
	for ( i = 0; i < num; i ++)
		scanf("%d%d",&head[i],&end[i]);
	for ( i = 0; i < num; i ++)
		for ( j = i + 1; j < num ;j ++)
			if (head[i] > head[j]) {
				temp = head[i];
				head[i] = head[j];
				head[j] = temp;
				temp = end[i];
				end[i] = end[j];
				end[j] = temp;
			}
	last = end[0];
	point = 1;
	count = 1;
	flag = false;
	while (point < num)
	{
		if(flag )
			if (head[point] == head[point - 1] )
				if ( end[point] >= end[point-1]) {
				point ++;
				continue;
			}
				else
					last = end[point++];
			else {
				flag = false;
				count ++;
			}
		if ( end[point] < last ) {
			last = end[point++];
			continue;
		}
		if ( head[point ] <last)	{
			point ++;
			continue;
		}
		if ( head[point ] == last) {
			count++;
			flag = true;
			last = end[point++] ;
			continue;
		}
		count += 2;
		last = end[point++];
	}
	printf("%d\n",count );
	return 0;
}
#include <stdio.h>
int s[1000005];
int main()
{
	int onum,num,i,temp;
	scanf("%d",&onum);
	num = onum;
	while ( num)
	{
		scanf("%d",&temp);
		scanf("%d",&s[num]);
		s[num] +=temp ;
		s[num+1] += s[num]/10;
		s[num] = s[num]%10;
		num--;
	}
	s[onum+1]?printf("%d",s[onum+1]):1;
	for ( i = onum; i > 0; i--)
		printf("%d",s[i]);
	return 0;
}


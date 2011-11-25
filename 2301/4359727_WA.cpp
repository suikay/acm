#include <stdio.h>
int main()
{
int sum,diff,i;
scanf("%d",&i);
while( i ){
scanf("%d%d",&sum,&diff);
if ( sum > diff || (sum + diff)%2 == 1)
printf("impossible\n");
else
printf("%d %d\n",(sum + diff)/2,(sum - diff)/2);
i--;
}
return 0;
}
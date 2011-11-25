#include <stdio.h>
int main()
{
int a;
scanf("%d",&a);
while(a){
int b = 0;
while( a > 9) {
b = 0;
while(a > 9) {
b += a % 10;
a = a / 10;
}
a = b;
}
printf("%d\n",a);
scanf("%d",&a);
}
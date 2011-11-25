#include <string.h>
#include <stdio.h>
char s1[1000],s2[1000];
int gcd(int x,int y)
{
	if(x % y)
		return gcd(y,x%y);
	return y;
}
int ap(char *str1,char *str2)
{
	int l1,l2,c1,res,tmp;
	l1 = strlen(str1);
	l2 = strlen(str2);
	c1 = 0;
	res = 0;
	while(c1 < l1) 
	{
		tmp = 0;
		for(int i = c1,j = 0;j < l2 && i < l1; i++,j++)
			if(str1[i] == str2[j])
				tmp++;
		if(tmp > res)
			res = tmp;
		if((l1 - c1) < res)
			break;
		c1++;
	}
	return res;
}
int max(int x,int y)
{
	if(x > y)
		return x;
	return y;
}
int main()
{
	while(scanf("%s%s",s1,s2) == 2)
	{
		int l1,l2,res;
		l1 = strlen(s1); l2 = strlen(s2);
		res = ap(s1,s2);
		res = max(res,ap(s2,s1));
		printf("appx(%s,%s) = ",s1,s2);
		if(res) {
			int g = gcd(l1+l2,res*2);
			if(g == (l1+l2))
				puts("1");
			else
				printf("%d/%d\n",res*2/g,(l1+l2)/g);
		} else
			puts("0");
	}
	return 0;
}
	
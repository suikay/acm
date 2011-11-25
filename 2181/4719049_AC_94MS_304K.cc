#include<stdio.h>
int main()
{
	int p,tmp,_neg, pos(0),neg(0);
	scanf("%d",&p);
	for(int i = 1; i <= p; i++)	{
		scanf("%d",&tmp);
		int _neg = neg;
		if(pos + tmp > neg)
			_neg = pos + tmp;
		if(neg - tmp > pos)
			pos = neg - tmp;
		neg = _neg;
	}
	printf("%d\n",neg);
	return 0;
}
		
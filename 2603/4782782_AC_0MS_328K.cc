#include<stdio.h>
int pri[2000],count[2000]={0},prin;
bool v[10010]={false};
void mPri()
{
	prin = 0;
	for(int i = 2; i < 10010; i++)
		if(!v[i]){
			pri[prin++] = i;
			for(int j = 2*i; j < 10010; j+=i)
				v[j] = true;
		}
}
void f(int x)
{
	while(x > 1)
		for(int i = 0; i < prin; i++)
			if(!(x % pri[i])){
				count[i]++;
				x /= pri[i];
				break;
			}
	return;
}
int main()
{
	int tmp;
	mPri();
	for(int i = 0; i < 10; i++){
		scanf("%d",&tmp);
		f(tmp);
	}
	int res=1;
	for(int i = 0; i < prin; i++)
		res *= (count[i]+1);
	printf("%d\n",res%10);
	return 0;
}

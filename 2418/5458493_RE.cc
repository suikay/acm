#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<string>
#include<map>
#define P1  99997
using namespace std;
char name[P1][35];
bool v[P1];
int coun[P1];
int cmp(const void* a,const void* b){
	return strcmp((char*)a,(char*)b);
}
int hash(char *word)
{
	int tmp(0);
	for(int i = strlen(word)-1; i >= 0; i--)
		tmp = (tmp*27 + (word[i]-'a'))%P1;
	while(strcmp(name[tmp],word) && v[tmp]) {
		tmp++;
		tmp %= P1;
	}
	if(!v[tmp]) {
		v[tmp] = true;
		strcpy(name[tmp],word);
		coun[tmp] = 0;
	}
	return tmp;
}
char nb[11000][35];
int main()
{
	char tmp[35];
	int sum(0);
	while(gets(tmp))
	{
		coun[hash(tmp)]++;
		sum++;
	}
	int pp(0);
	for(int i = 0; i < P1; i++)
		if(v[i])
			strcpy(nb[pp++],name[i]);
	qsort(nb,pp,sizeof(char)*35,cmp);
	for(int i = 0; i < pp; i++)
		printf("%s %.4f\n",nb[i],coun[hash(nb[i])]*100.0/sum);
	return 0;
}

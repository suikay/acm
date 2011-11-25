#include<memory.h>
#include<string.h>
#include<stdio.h>
int map[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int itime[26];
int main()
{
	int t,p,w;
	char l[1010];
	scanf("%d",&t);
	while(t--)
	{
		int res(0);
		scanf("%d%d\n",&p,&w);
		memset(itime,0,sizeof(itime));
		itime[0] = p;
		for(int i = 1; i < 26; i++)
			if(map[i]==map[i-1])
				itime[i] = p + itime[i-1];
			else
				itime[i] = p;
		gets(l);
		res += itime[l[0]-'A'];
		for(int i = 1; i < strlen(l); i++)
			if(l[i] == ' '){
				res += p;
				if(i < (strlen(l)-1))
					res += itime[l[i+1]-'A'];
				i++;
			}
			else
				if(map[l[i]-'A'] == map[l[i-1]-'A'])
					res += itime[l[i]-'A'] + w;
				else
					res += itime[l[i]-'A'];
		printf("%d\n",res);
	}
	return 0;
}
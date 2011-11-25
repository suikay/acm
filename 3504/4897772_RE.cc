#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int ascii[26]={101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
    181,191,193,197,199,211,223,227,229,233};
#define MAX 100000
/*struct sstring{
	int p;
	int hash2;
};*/
int hp[MAX],hhash2[MAX];
char p[10001][100];
//sstring st[100001];
char res[1201],chip[1001],tmp[101];
int dp[1001] = {0};
int len,hash,hash2,k,ptr(0);
int queue[1001],top(0);
int f(char *chip)
{

	return 0;
}

int main()
{
	int n,flag;
	scanf("%d\n",&n);
	while(n--)
	{
		scanf("%s",&chip);
		flag = 0,ptr = 0;
		scanf("%d\n",&k);
		memset(dp,0,sizeof(dp));
		memset(hhash2,0,sizeof(hhash2));
		for(int i = 0; i < k; i++){
			hash = 0;
			scanf("%s",&tmp);
			len = strlen(tmp);
			hash2 = 0;
			for(int j = 0; j < len; j++)
				hash2 += ascii[tmp[j]-'a'];
			hash = tmp[0]-'a'+ 29 * ( tmp[len-1]-'a' + 29 * len);
			while(hhash2[hash]){
				hash++;
				if(hash == MAX)
					hash = 0;
			}
			if(hhash2[hash] == 0){
				hp[hash] = ptr;
				hhash2[hash] = hash2;
				strcpy(p[ptr],tmp);
				ptr++;
			}
		}

		len = strlen(chip);
		dp[0] = 1;
		for(int i = 0; i < len; i++)
			if(dp[i])
				for(int j = 0; j < 100 && (i + j) < len; j++)
				{
					hash = chip[i]-'a' + 29 * (chip[i+j] - 'a' + 29 * (j+1));
					while(hhash2[hash])	{
						hash2 = 0;
						for(int z = i; z <= i+j; z++)
							hash2 += ascii[chip[z]-'a'];
						if(hhash2[hash] == hash2){
							if(dp[i+j+1])
								dp[i+j+1] = -1;
							else
								dp[i+j+1] = hash * 1000 + j + 1;
						}
						hash++;
						if(hash == MAX)
							hash = 0;
					}
				}
		if(!dp[len])
			flag =  1;
		while(len && !flag){
			if(dp[len] == -1)
				flag = 2;
			queue[top++] = dp[len]/1000;
			len -= dp[len]%1000;
		}
		res[0] = '\0';
		while(!flag && top--){
			strcat(res,p[hp[queue[top]]]);
			if(top)
				strcat(res," ");
		}
		switch(flag)
		{
		case 0:
			printf("%s\n",res);
			break;
		case 1:
			printf("impossible\n");
			break;
		default:
			printf("ambiguous\n");
		}
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int ascii[26]={101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,
    181,191,193,197,199,211,223,227,229,233};
#define MAX 5000000
int hp[MAX],hhash2[MAX];
char p[10001][110];
char res[30001],chip[1001],tmp[110];
int dp[1001] = {0};
int len,hash,hash2,k,ptr(0);
int queue[1001],top(0);
int main()
{
	//freopen("testdata.in","r",stdin);
	//freopen("testdata.out","w",stdout);
	int n,flag,maxlen;
	char ch;
	scanf("%d\n",&n);
	while(n--)
	{
		scanf("%s",&chip);
		flag = 0,ptr = 0;
		scanf("%d\n",&k);
		memset(dp,0,sizeof(dp));
		memset(hhash2,0,sizeof(hhash2));
		maxlen = 0;
		for(int i = 0; i < k; i++){
			len = 0;
			hash2 = 0;
			ch = getchar();
			while(ch != '\n')
			{
				tmp[len++] = ch;
				hash2 += ascii[ch - 'a'];
				ch = getchar();
			}
			tmp[len] = '\0';
			maxlen = maxlen > len?maxlen : len;
			hash = tmp[0]-'a'+ 26 * ( tmp[len-1] - 'a' + 7 * (hash2 + 26 * len));
			while(hhash2[hash]){
				if(hhash2[hash] == hash2)
					break;
				hash++;
				if(hash >= MAX)
					hash = 0;
			}
			if(!hhash2[hash]){
				hp[hash] = ptr;
				hhash2[hash] = hash2;
				strcpy(p[ptr],tmp);
				ptr++;
			}
		}

		len = strlen(chip);
		dp[0] = 1;
		for(int i = 0; i < len; i++)
			if(dp[i]){
				hash2 = 0;
				for(int j = 0; j < 100 && (i + j) < len; j++)
				{
					hash2 += ascii[chip[i+j]-'a'];
					hash = chip[i]-'a' + 26 * (chip[i+j] - 'a' + 7 * (hash2 + 26 * (j+1)));
					while(hhash2[hash])	{
						if(hhash2[hash] == hash2){
							if(dp[i+j+1])
								dp[i+j+1] = -1;
							else
								dp[i+j+1] = hash * 101 + j + 1;
						}
						hash++;
						if(hash >= MAX)
							hash = 0;
					}
				}
			}
		if(!dp[len])
			flag =  1;
		top = 0;
		while(len && !flag){
			if(dp[len] == -1){
				flag = 2;
				break;
			}
			queue[top++] = dp[len]/101;
			len -= dp[len]%101;
		}
		res[0] = '\0';
		//int wa;
		while(!flag && top--){
		//	wa = strlen(p[hp[queue[top]]]);
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
	//fclose(stdout);
	return 0;
}
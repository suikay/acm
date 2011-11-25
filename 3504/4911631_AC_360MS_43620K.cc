//这道题的解法有点傻...首先对字符串进行hash
//得到其在字典中的位置,然后比较两个hash值(hash2,hash3)
//是否相等,另外用dp[i]表示其位置是否能达到,0为不能
//-1为多种可能,否则就用 101*到达i位置的字符串对应的hash+字符串长度
#include<stdio.h>
#include<string.h>
#include<iostream>
#define P1 3543
#define P2 126951
using namespace std;
//hash的素数列
int ascii[26]={126951,126957,126969,126993,126997,
	127021,127023,127029,127051,127057,127069,127071,
	127101,127113,127129,127137,127161,12719,127189,
	127191,127221,127261,127263,127273,127287,127291};
#define MAX 7000000
//用于
int hp[MAX],hhash2[MAX],hhash3[MAX];
char p[10001][110];
char res[30001],chip[1001],tmp[110];
int dp[1001] = {0};
int len,hash,hash2,hash3,k,ptr(0);
int queue[1001],top(0);
int main()
{
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
		//读入字典,生成hash的字典数组
		for(int i = 0; i < k; i++){
			len = 0;
			hash2 = 0;
			hash3 = 0;
			ch = getchar();
			while(ch != '\n')
			{
				tmp[len++] = ch;
				hash2 += ascii[ch-'a'];
				hash3 += (ch-'a')*(ch-'a');
				ch = getchar();
			}
			hash2 %= P1;
			tmp[len] = '\0';
			maxlen = maxlen > len?maxlen : len;
			hash = tmp[0]-'a'+ 29 * ( tmp[len-1] - 'a' + 11 * (hash2 + 26 * len));
			while(hhash2[hash])
				hash++;
			hp[hash] = ptr;
			hhash2[hash] = hash2;
			hhash3[hash] = hash3;
			strcpy(p[ptr],tmp);
			ptr++;
		}

		len = strlen(chip);
		dp[0] = 1;
		for(int i = 0; i < len; i++)
			if(dp[i]){
				hash2 = 0;
				hash3 = 0;
				for(int j = 0; j < 100 && (i + j) < len; j++)
				{
					hash2 += ascii[chip[i+j]-'a'];
					hash2 %= P1;
					hash3 += (chip[i+j] - 'a')*(chip[i+j] - 'a');
					//找出该字符串的hash位置
					hash = chip[i]-'a' + 29 * (chip[i+j] - 'a' + 11 * (hash2 + 26 * (j+1)));
					while(hhash2[hash])	{
						//比较两个hash值是否相等
						if(hhash2[hash] == hash2  && hhash3[hash] == hash3){
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
		//使用dp值还原之前的状态
		while(len && !flag){
			if(dp[len] == -1){
				flag = 2;
				break;
			}
			queue[top++] = dp[len]/101;
			len -= dp[len]%101;
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
//suikay 3504 Accepted 43548K 375MS G++ 
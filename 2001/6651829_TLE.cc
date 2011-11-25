#include <stdio.h>
#include <string.h>
#define H 9999991
#define K 0xf0000000L
char str[1100][22];
int len[1100],finish[1100];
unsigned int hash[1100], tmp;
short rec[H];
int main()
{
	int cnt(0),maxlen(0),h,g;
	while(gets(str[cnt]))
	{
		len[cnt] = strlen(str[cnt]);
		if(len[cnt] > maxlen)
			maxlen = len[cnt];
		++cnt;
	}
	for(int i = 0; i < maxlen; i++) 
	{
		memset(rec,-1,sizeof(rec));
		for(int j = 0; j < cnt; j++) {
			if(finish[j] > 0)
				continue;
			h = (hash[j] << 4) + str[j][i];
			g = h & K;
			if(g)
				h ^= g >> 24;
			h &= ~g;
			h %= H;
			if(len[j] == (i + 1)) {
				finish[j] = i+1;
				if(rec[h] >= 0)
					finish[rec[h]] = 0;
				rec[h] = -2;
			} else {
				if(rec[h] >= 0) {
					finish[rec[h]] = 0;
					rec[h] = -2;
				} else if(rec[h] == -1) {
					finish[j] = i+1;
					rec[h] = j;
				} 
			}
			hash[j] = h;
		}
	}
	for(int i = 0; i < cnt; i++) {
		printf("%s ",str[i]);
		str[i][finish[i]] = '\0';
		puts(str[i]);
	}
		

	return 0;
}


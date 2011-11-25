#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
typedef struct work{
	int Q_number;
	int period;
	int lastTime;
} work;
work w1[1005],w2,w3[1005],*w4;
int compare(const void *p1,const void *p2)
{
	work a=*(work *)p1;
	work b=*(work *)p2;
	if(a.period > b.period )
		return 1;
	else if(a.period  == b.period  && a.Q_number  > b.Q_number )
		return 1;
	return -1;
}
int main()
{
	int wCount = 0,j,i,k;
	char s[20];
	while(gets(s) && s[0] != '#') {
		sscanf(s,"Register %d%d",&w1[wCount].Q_number,&w1[wCount].period);
		w1[wCount].lastTime = w1[wCount].period;
		wCount++;
	}
	qsort(w1,wCount,sizeof(work),compare);
	memcpy(w3,w1,wCount*sizeof(work));
	scanf("%d",&k);
	for(i = 0; i < k; i++) {
		printf("%d\n",w1[0].Q_number);
		w1[0].lastTime += w1[0].period;
		w2 = w1[0];
		for( j = 1; j < wCount; j++)
			if(	w1[j].lastTime > w1[0].lastTime || ( w1[j].lastTime == w1[0].lastTime && w1[j].Q_number > w1[0].Q_number))
				break;
		memcpy(w3,w1 + 1, (j - 1) * sizeof(work));
		w3[j-1] = w2;
		memcpy(w1,w3,wCount*sizeof(work));
	}
}
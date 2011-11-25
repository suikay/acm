#include <stdio.h>
#include <memory.h>
bool data[1000][1000];
int main()
{
	int blocks,instruction,N,i,j,k,x1,y1,x2,y2;
	char cmd;
	scanf("%d",&blocks);
	for(int a = 0; a < blocks; a++)
	{
		scanf("%d",&N);
		memset(data,0,1000000*sizeof(bool));
		scanf("%d",&instruction);
		for( int i = 0; i < instruction; i ++)
		{
			getchar();
			cmd = getchar();
			if (cmd == 'C') {
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				for (j = x1; j<= x2;j ++)
					for ( k = y1; k <= y2; k++)
						data[j][k] = !data[j][k];
			}
			else {
				scanf("%d%d",&x1,&y1);
				printf("%d\n",data[x1][y1]);
			}
		}
	}
	return 0;
}
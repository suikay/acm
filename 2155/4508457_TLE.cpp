#include<stdio.h>
typedef struct Part{
	int x1;
	int y1;
	int x2;
	int y2;
} Part;
Part part[50000];
int main() {
	int n,j;
	char s[20];
	int count = 0;
	bool flag ;
	int x,y,t;
	scanf("%d",&t);
	for(int k = 0;k < t;k++) {
		scanf("%d%d\n",&j,&n);
		count = 0;
		for(int i = 0; i < n; i++) {
			gets(s);
			if(s[0] == 'C')  {
				sscanf(s,"C %d%d%d%d",&part[count].x1,&part[count].y1,&part[count].x2,&part[count].y2);
				count++;
			}
			else {
				sscanf(s,"Q %d%d",&x,&y);
				flag = 0;
				for(j = 0; j < count;j++)
					if(part[j].x1 <= x && part[j].x2 >= x && part[j].y1 <= y && part[j].y2 >= y)
						flag = !flag;
				printf("%d\n",flag?1:0);
			}
		}
	}
}
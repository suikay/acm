#include <stdio.h>
#include <string.h>
int parent[30010];
int height[30010];
int start[30010];
void f(int x,int y) {
        while(parent[x])
                x = parent[x];
        while(parent[y])
                y = parent[y];
		parent[y] = x;
		start[y] = height[x];
		height[x] += height[y];
}
int main()
{
        int n, count=0;
        int x,y;
        char s[20];
        scanf("%d\n",&n);
		for(int i = 1; i <= n; i++)
			height[i] = 1;
        while(gets(s))
                if(s[0] == 'M') {
                        sscanf(s,"M %d%d",&x,&y);
                         f(x,y);
                }
                else {
                        count = 0;
                        sscanf(s,"C %d",&x);
                        while( parent[x]) {
                                count += start[x];
                                x = parent[x];
                        }
                        printf("%d\n",height[x] - 1 - count);
                }
        return 0;
}
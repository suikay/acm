#include <stdio.h>
#include <string.h>
int parent[30003];
int son[30003];
int under[30003];
void f(int x,int y) {
        while(son[x])
                x = son[x];
        while(parent[y])
                y = parent[y];
        son[x] = y;
        parent[y] = x;
		int count = under[y] + 1;
		do {
			under[x] = count++;
			x = parent[x];
		}while(x);
}
int main(int argc, char* argv[])
{
        int n, count=0;
        int x,y;
        char s[20];
        scanf("%d\n",&n);
        while(gets(s))
                if(s[0] == 'M') {
                        sscanf(s,"M %d%d",&x,&y);
                         {
        while(son[x])
                x = son[x];
        while(parent[y])
                y = parent[y];
        son[x] = y;
        parent[y] = x;
		int count = under[y] + 1;
		do {
			under[x] = count++;
			x = parent[x];
		}while(x);
}
                }
                else {
                        count = 0;
                        sscanf(s,"C %d",&x);
                        while( son[x]) {
                                count += under[x];
                                x = son[x];
                        }
                        printf("%d\n",count);
                }
        return 0;
}
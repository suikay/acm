#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int f,t,res,l,mod;
	char ori[100], ans[100];
	while(scanf("%s%d%d",ori,&f,&t) == 3)
	{
		res = 0;
		for(int i = 0; i < strlen(ori); i++)
		{
			res *= f;
			if(ori[i] >= 'A')
				res += 10 + ori[i] - 'A';
			else
				res += ori[i] - '0';
		}
		l = 0;
		while(res) {
			mod = res % t;
//			printf("%d\n",mod);
			if (mod >= 10)
				ans[l++] = mod-10 + 'A';
			else
				ans[l++] = mod + '0';
			res /= t;
		}
		if(l > 7) 
			puts("  ERROR");
		else {
			while(l < 7)
				ans[l++] = ' ';
			ans[l] = '\0';
			reverse(ans,ans+l);
			printf("%s\n",ans);
		}
	}
	return 0;
}

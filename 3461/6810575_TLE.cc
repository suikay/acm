#include <stdio.h>
#include <string.h>
#define D 43
#define P 2750159 
char w[10010],t[1000100];
int main()
{
	int n,i,j,k,h,res;
	int ww,tt,wl,tl;
	scanf("%d",&n);
	//gets(w);
	while(n--)
	{
		res = 0;
		scanf("%s",w);
		scanf("%s",t);
		wl = strlen(w);
		tl = strlen(t);
		ww = tt = 0;
		h = 1;
		for(i = 1; i < wl; i++)
			h = h*D%P;
		for(i = 0; i < wl; i++)
		{
			ww = (D*ww + w[i]) % P;
			tt = (D*tt + t[i]) % P;
		}
		if(ww == tt) {
			for(i = 0; i < wl; i++)
				if(w[i] != t[i])
					break;
			if(i == wl)
				res++;
		}
		for(i = wl; i < tl; i++)
		{
            int tmp = t[i-wl]*h%P;
            tt -= t[i-wl]*h;
            while(tt < 0)
                tt += P;
			tt = (D*tt + t[i]) % P;
			if(tt == ww) {
				for(j = 0,k = i-wl+1; j < wl; j++,k++)
					if(w[j] != t[k])
						break;
				if(j == wl)
					res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
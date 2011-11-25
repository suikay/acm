#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
int circle[30],cn,arr[30];
char ori[30],cha[30],oori[30];
bool v[30];
int gcd(int x,int y)
{
	if(x < y)
		swap(x,y);
	if(!y)
		return x;
	return gcd(y,x%y);
}
void change()
{
	memcpy(cha,ori,sizeof(cha));
	for(int i = 0; i < 26; i++)
		cha[arr[i]] = ori[i];
	memcpy(ori,cha,sizeof(ori));
	//cout << cha << endl;
}
int dfs(int x,int cnt)
{
	v[x] = true;
	if(!v[arr[x]]) 
		return dfs(arr[x],cnt+1);
	else
		return cnt;
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",ori);
		memset(v,false,sizeof(v));
		cn = 0;
		for(int i = 0; i < 26; i++)
			arr[i] = ori[i]-'A';
		for(int i = 0; i < 26; i++)
			if(!v[i])
				circle[cn++] = dfs(i,1);
		/*
		int res(1);
		for(int i = 0; i < cn; i++)
			res = res*circle[i]/gcd(res,circle[i]);
		memcpy(oori,ori,sizeof(ori));
		for(int i = 0; i < 26; i++)
			ori[i] = 'A'+i;
		if(res == 2) {
			puts("No");
			continue;
		} else if(res == 1){
			puts("Yes");
			continue;
		} else {
			for(int i = 0; i < res; i++)
				change();
			int i;
			if(!strcmp(oori,ori))
				puts("Yes");
			else
				puts("No");
		}
		*/
		sort(circle,circle+cn);
		int pp(0);
			//cout << circle[i] << " " ;
		//cout << endl;
		for(int i = 0; i < cn; i++) {
			int j,len(1);
			for(j = i; j+1 < cn && circle[j+1] == circle[j]; j++)
				len++;
			//cout << circle[i] << " " << len << " " << j << endl;
			i = j;
			if(circle[i] % 2 == 0 && (len % 2 != 0))
				pp = -1;
		}
		if(pp == -1)
			puts("No");
		else
			puts("Yes");
	}

	return 0;
}
/*
1
CDEFGHIJKLMNOPQRSTUVWXYZAB
*/

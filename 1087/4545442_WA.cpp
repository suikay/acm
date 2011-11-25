#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NIL 9999999
#define N 1000
int net[N][N];
int path[N];
int d[N];
int queue[N],top;
int sum;
char name[N][30];
int Hcount[N],Tcount[N];
int m,n,k;
int goodsum;
int min(int a,int b) {	return a>b?b:a; }
int find(char* s)
{
	for(int i = 0; i < sum; i++)
		if(!strcmp(s,name[i]))
			return i+1;
	return 0;
}
void input()
{
	char tmp1[30],tmp2[30];
	int i,j;
	sum = 0;
	scanf("%d",&n);
	for(i = 0; i < n; i++) {
		scanf("%s",name[sum]);
		for(j = 0; j < sum;j++)
			if(!strcmp(name[j],name[sum])) {
				Hcount[j]++;
				break;
			}
		if(j == sum)
			Hcount[sum++] = 1;
	}
	for(int i = 0; i < sum;i++)
		net[0][i+1]=Hcount[i];
	scanf("%d",&m);
	int position;
	for(int i = 0; i < m; i++) {
		scanf("%s%s",&tmp1,&tmp2);
		position = find(tmp2);
		if(position)
			Tcount[position]++;
		else {
			strcpy(name[sum],tmp2);
			Tcount[sum+1] = 1;
			sum++;
		}
	}
	for(int i = 1;i <= sum; i++) {
		goodsum+= Tcount[i];
		net[i][sum+1] = Tcount[i];
	}
	scanf("%d",&k);
	int pos1,pos2;
	for(int i = 0; i < k; i++) {
		scanf("%s%s",&tmp1,&tmp2);
		pos1=find(tmp1);
		pos2=find(tmp2);
		if(!pos1||!pos2)
			continue;
		net[pos2][pos1]=NIL;
	}
}
int find_path()
{
	int tail;
	top = tail = 0;
	int t;
	memset(path,-1,sizeof(path));
	path[0]=0;
	d[0]=NIL;
	queue[tail++] = 0;
	while(top!=tail) {
		t = queue[top++];
		if (t == (sum+1))
			break;
		for(int i = 1;i <=(sum+1);i++) 
			if(path[i]==-1&&net[t][i]) {
				d[i] = min(d[t],net[t][i]);
				path[i] = t;
				queue[tail++] = i;
			}
	}
	if(path[sum+1] == -1)
		return -1;
	return d[sum+1];
}
int FF()
{
	int step;
	int maxflow=0;
	while((step=find_path())!=-1) {
		maxflow+=step;
		int l = sum+1;
		while(l) {
			net[path[l]][l] -= step;
			net[l][path[l]] += step;
			l = path[l];
		}
	}
	return maxflow;
}
int main()
{
	input();
	printf("%d\n",goodsum - FF());
}
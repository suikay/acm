#include<memory.h>
#include<stdio.h>
#define MP 40005
//#define abs(x) (x>0)?(x):-(x)
int zx[MP],zy[MP],dis[MP],ze[MP];
int nx[MP],ny[MP],ne[MP];
bool eq[MP],mat[202][202];
int abs(int x)
{
	return x>0?x:(-x);
}
int main()
{
	int N,zeroes(0),nz(0);
	int tmp,_dis;
	memset(eq,false,sizeof(eq));
	memset(dis,0x7f,sizeof(dis));
	memset(mat,false,sizeof(mat));
	scanf("%d",&N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)	{
			scanf("%d",&tmp);
			if(!tmp)	{
				zx[zeroes] = i;
				zy[zeroes] = j;
				zeroes++;
			}
			else	{
				mat[i][j] = true;
				nx[nz] = i;
				ny[nz] = j;
				ne[nz] = tmp;
				nz++;
			}
		}
	for(int i = 0; i < nz; i++)
		for(int j = 0; j < zeroes; j++)	{
			_dis = abs(nx[i] - zx[j]) + abs(ny[i] - zy[j]);
			if(_dis == dis[j])
				eq[j] = true;
			else
				if(_dis < dis[j])	{
					dis[j] = _dis;
					ze[j] = ne[i];
					eq[j] = false;
				}
		}
	int nn(0),zz(0);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N ;j++)	{
			if(mat[i][j])
				printf("%d",ne[nn++]);
			else	{
				if(eq[zz])
					printf("0");
				else
					printf("%d",ze[zz]);
				zz++;
			}
		
			if(j == (N-1))
				printf("\n");
			else
				printf(" ");
		}
	return 0;
}

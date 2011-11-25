#include<stdio.h>
#include <string.h>
int l,c,w,ptr;
char m[1002][1002];
char word[102];
int map[10000000];
int end[10000000];
int dirx[] = {-1,-1,0,1,1,1,0,-1}, diry[] = {0,1,1,1,0,-1,-1,-1};
struct ANS{
	int x,y,dir;
};
ANS res[1001];
void input()
{
	int now,len;
	ptr = 1;
	memset(map,-1,sizeof(map));
	memset(end,-1,sizeof(end));

	scanf("%d%d%d",&l,&c,&w);
	gets(m[0]);
	for(int i = 0; i < l; i++)
		gets(m[i]);
	for(int i = 0; i < w; i++)
	{
		gets(word);
		now = 0;
		len = strlen(word);
		for(int j = 0; j < len; j++) {
			if(map[now] == -1) 
			{
				map[now] = ptr;
				ptr += 26;
			}
			now = map[now]+word[j]-'A';
		}
		end[now] = i;
	}
}
void f()
{
	int now,x,y,dx,dy;
	for(int i = 0; i < l; i++)
		for(int j = 0; j < c; j++)
			for(int k = 0; k < 8; k++) {
				now = 0;
				x = i;
				y = j;
				dx = dirx[k];
				dy = diry[k];
				while(now >= 0 && x >= 0 && x < l &&
					y >= 0 && y < c)
				{
					now = map[now]+m[x][y]-'A';
					if(now == -1)
						break;
					if(x == 4 && y == 5 && k == 2)
						x = x;
					if(end[now] >= 0)
					{
						res[end[now]].x = i;
						res[end[now]].y = j;
						res[end[now]].dir = k;
						end[now] = -1;
					}
					if(map[now] == -1)
						break;
					x += dx;
					y += dy;
				}
			}
	for(int i = 0; i < w; i++)
		printf("%d %d %c\n",res[i].x,res[i].y,res[i].dir+'A');
}
int main()
{
	input();
	f();

	return 0;
}
/*
3 3 3
ABC
DEF
GHI
EC
HEB
IFC

20 20 10
QWSPILAATIRAGRAMYKEI
AGTRCLQAXLPOIJLFVBUQ
TQTKAZXVMRWALEMAPKCW
LIEACNKAZXKPOTPIZCEO
FGKLSTCBTROPICALBLBC
JEWHJEEWSMLPOEKORORA
LUPQWRNJOAAGJKMUSJAE
KRQEIOLOAOQPRTVILCBZ
QOPUCAJSPPOUTMTSLPSF
LPOUYTRFGMMLKIUISXSW
WAHCPOIYTGAKLMNAHBVA
EIAKHPLBGSMCLOGNGJML
LDTIKENVCSWQAZUAOEAL
HOPLPGEJKMNUTIIORMNC
LOIUFTGSQACAXMOPBEIO
QOASDHOPEPNBUYUYOBXB
IONIAELOJHSWASMOUTRK
HPOIYTJPLNAQWDRIBITG
LPOINUYMRTEMPTMLMNBO
PAFCOPLHAVAIANALBPFS
MARGARITA
ALEMA
BARBECUE
TROPICAL
SUPREMA
LOUISIANA
CHEESEHAM
EUROPA
HAVAIANA
CAMPONESA

7 7 1
SAPREMA
SBPREMA
SCPREMA
SDPREMA
SEPREMA
SUPRGMA
SFPREMA
SUPREMA
*/
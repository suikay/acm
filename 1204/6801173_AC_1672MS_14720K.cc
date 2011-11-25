#include <stdio.h>
#include <string.h>
int dirx[] = {-1,-1,0,1,1,1,0,-1}, diry[] = {0,1,1,1,0,-1,-1,-1};
int l,c,w;
char m[1010][1010];
char word[1100000];
struct RES {
	int x,y,dir;
	RES() {
		x = y = dir = 0;
	}
};
RES res[1010];
struct Node {
	Node* dic[26];
	int info;
	Node() {
		memset(dic,0,sizeof(dic));
	}
};
Node* root;
void input()
{
	int now,len;
	Node *ptr;
	scanf("%d%d%d",&l,&c,&w);
	gets(m[0]);
	for(int i = 0; i < l; i++)
		gets(m[i]);
	root = new Node();
	for(int i = 0; i < w; i++)
	{
		gets(word);
		ptr = root;
		len = strlen(word);
		for(int j = 0; j < len; j++)
		{
			if(ptr->dic[word[j]-'A'] == 0) 
				ptr->dic[word[j]-'A'] = new Node();
			ptr = ptr->dic[word[j]-'A'];
		}
		ptr->info = i;
	}
}
int i,j,k;
void search(Node *ptr,int x,int y,int dir)
{
	if(!ptr)
		return;
	if(ptr->info >= 0) {
		res[ptr->info].x = i;
		res[ptr->info].y = j;
		res[ptr->info].dir = k;
		ptr->info = -1;
	}
	if(x < 0 || x >= l || y < 0 || y >= c)
		return;
	search(ptr->dic[m[x][y]-'A'],x+dirx[dir],y+diry[dir],dir);
}

void f()
{
	for(i = 0; i < l; i++)
		for(j = 0; j < c; j++)
			for(k = 0; k < 8; k++)
				search(root,i,j,k);
}

void output()
{
	for(int i = 0; i < w; i++)
		printf("%d %d %c\n",res[i].x, res[i].y, 'A'+res[i].dir);
}

int main()
{
	input();
	f();
	output();

	return 0;
}


/*
#include<stdio.h>
#include <string.h>
int l,c,w,ptr;
char m[1002][1002];
char word[2000000];
int map[3000000];
int end[3000000];
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
		if(len > 1000)
			break;
		for(int j = 0; j < len; j++) {
			if(map[now] == -1) 
			{
				map[now] = ptr;
				ptr += 26;
			}
			if(ptr > 5000000)
				while(true)
					ptr++;
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

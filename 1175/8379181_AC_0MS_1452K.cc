#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};

typedef struct Fig
{
	int w;
	char f[10001];
	bool operator<(const Fig &fig) const {
		if (w == fig.w) return (strcmp(f, fig.f) < 0);
		return w < fig.w;
	}
} Fig;
char pic[102][102];

int max(int x, int y)
{
	if (x > y) return x;
	return y;
}

int min(int x, int y)
{
	if (x < y) return x;
	return y;
}

char tc[10001];
void rotate(Fig &fig)
{
	int h = strlen(fig.f) / fig.w, w = fig.w;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			tc[j*h+h-i-1] = fig.f[i*w+j];
		}
	fig.w = h;
	tc[h*w] = '\0';
	memcpy(fig.f, tc, strlen(tc));
}
// up-down flip
void ud_flip(Fig &fig)
{
	int h = strlen(fig.f) / fig.w, w = fig.w;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			tc[(h-1-i)*w+j] = fig.f[i*w+j];
		}
	tc[h*w] = '\0';
	memcpy(fig.f, tc, strlen(tc));
}

// left-right flip
void lr_flip(Fig &fig)
{
	int h = strlen(fig.f) / fig.w, w = fig.w;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
		{
			tc[i*w+w-1-j] = fig.f[i*w+j];
		}
	tc[h*w] = '\0';
	memcpy(fig.f, tc, strlen(tc));
}

map<Fig, char> cluster;
Fig getFig(int minx, int miny, int maxx, int maxy)
{
	Fig f;
	int tmp = 0;
	f.w = maxy - miny + 1;
	for (int i = minx; i <= maxx; ++i)
		for (int j = miny; j <= maxy; ++j)
			if (pic[i][j] == 3)
				f.f[tmp++] = '1';
			else
				f.f[tmp++] = '0';
	f.f[tmp] = '\0';
	return f;
}
char rec = 'a';
int qx[10003], qy[10003], qs;
void go(int x, int y)
{
	pic[x][y] = 3;
	int minx, miny, maxx, maxy;
	int tx, ty;
	char tmp;
	minx = maxx = x;
	miny = maxy = y;
	qs = 0;
	qx[qs] = x;
	qy[qs] = y;
	qs++;
	while (qs--)
	{
		tx = qx[qs];
		ty = qy[qs];
		minx = min(minx, tx);
		miny = min(miny, ty);
		maxx = max(maxx, tx);
		maxy = max(maxy, ty);
		for (int i = 0; i < 8; ++i)
			if (pic[tx+dirx[i]][ty+diry[i]] == 2)
			{
				pic[tx+dirx[i]][ty+diry[i]] = 3;
				qx[qs] = tx+dirx[i];
				qy[qs++] = ty+diry[i];
			}
	}
	Fig fig = getFig(minx, miny, maxx, maxy);
	if (cluster.count(fig) > 0)
	{
		tmp = cluster[fig];
		for (int i = minx; i <= maxx; ++i)
			for (int j = miny; j <= maxy; ++j)
				if (pic[i][j] == 3)
					pic[i][j] = tmp;
		return;
	}
	tmp = rec++;
	for (int i = minx; i <= maxx; ++i)
		for (int j = miny; j <= maxy; ++j)
			if (pic[i][j] == 3)
				pic[i][j] = tmp;
	cluster[fig] = tmp;
	lr_flip(fig);
	cluster[fig] = tmp;
	rotate(fig);
	cluster[fig] = tmp;
	ud_flip(fig);
	cluster[fig] = tmp;
	rotate(fig);
	cluster[fig] = tmp;
	lr_flip(fig);
	cluster[fig] = tmp;
	rotate(fig);
	cluster[fig] = tmp;
	ud_flip(fig);
	cluster[fig] = tmp;
	
}

int main()
{
	int w, h;
	char tmp;
	scanf("%d%d", &w, &h);
	memset(pic, 0, sizeof(pic));
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j)
		{
			do {
				tmp = getchar();
			}while (tmp != '0' && tmp != '1');
			pic[i][j] = tmp - '0' + 1;
		}
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j)
			if (pic[i][j] == 2)
				go(i, j);
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
			if (pic[i][j] < 'a')
				putchar('0');
			else
				putchar(pic[i][j]);
		puts("");
	}

	return 0;
}
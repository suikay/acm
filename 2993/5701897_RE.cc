#include <stdio.h>
using namespace std;
char m[8][8];
void pl()
{
	puts("+---+---+---+---+---+---+---+---+");
}
void get(int x)
{
	while(x--)
		getchar();
}
void put(int x)
{
	if(x % 2)
		putchar(':');
	else
		putchar('.');
}

int main()
{
	char p1,p2,what;
	get(7);
	for(int i = 0; i < 7; i++) {
		what = getchar(); p1 = getchar(); p2 = getchar();getchar();
		p1 -= 'a';
		p2 -= '1';
		m[7-p2][p1] = what;
	}
	for(int i = 0; i < 8; i++) {
		p1 = getchar(); p2 = getchar();getchar();
		p1 -= 'a';
		p2 -= '1';
		m[7-p2][p1] = 'P';
	}
	get(7);
	for(int i = 0; i < 7; i++) {
		what = getchar(); p1 = getchar(); p2 = getchar();getchar();
		p1 -= 'a';
		p2 -= '1';
		m[7-p2][p1] = what-'A'+'a';
	}
	for(int i = 0; i < 8; i++) {
		p1 = getchar(); p2 = getchar();getchar();
		p1 -= 'a';
		p2 -= '1';
		m[7-p2][p1] = 'p';
	}
	for(int i = 0 ; i < 8; i++) {
		pl();
		for(int j = 0; j < 8; j++)
		{
			putchar('|');
			put(i+j);
			if(m[i][j])
				putchar(m[i][j]);
			else
				put(i+j);
			put(i+j);
		}
		puts("|");
	}
	pl();
		

	return 0;
}
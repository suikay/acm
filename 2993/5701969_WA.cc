#include <stdio.h>
#include <iostream>
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
bool v(int x)
{
	return (x >= 0 && x < 8);
}
int main()
{
	char p1,p2,what,x[100],d;
	cin >> x;
	for(int i = 0; i < 7; i++) {
		cin >> what >> p1 >> p2 >> d;
		p1 -= 'a';
		p2 -= '1';
		if(v(p1)&&v(p2))
			m[7-p2][p1] = what;
	}
	for(int i = 0; i < 8; i++) {
		cin >> p1 >> p2 >> d;
		p1 -= 'a';
		p2 -= '1';
		if(v(p1) && v(p2))
			m[7-p2][p1] = 'P';
	}
	cin >> x;
	for(int i = 0; i < 7; i++) {
		cin >> what >> p1 >> p2 >> d;
		p1 -= 'a';
		p2 -= '1';
		if(v(p1) && v(p2))
			m[7-p2][p1] = what-'A'+'a';
	}
	for(int i = 0; i < 8; i++) {
		cin >> p1 >> p2;
		if(i != 7)
			cin >> d;
		p1 -= 'a';
		p2 -= '1';
		if(v(p1) && v(p2))
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
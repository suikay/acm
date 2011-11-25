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
void put(int a,string x)
{
	if(x.size() == 0)
		return;
	char w,p1,p2;
	if(x.size() == 2)
		x = "P" + x;
	w = x[0]; p1 = x[1]; p2 = x[2];
	if(a) {
		p1 -= 'a';
		p2 -= '1';
		m[7-p2][p1] = w-'A'+'a';
	} else {
		p1 -= 'a';
		p2 -= '1';
		m[7-p2][p1] = w;
	}
}
bool v(int x)
{
	return (x >= 0 && x < 8);
}
int main()
{
	char p1,p2,what,x[100],d;
	string s;
	cin >> x;
	while(true) {
		s = "";
		cin >> d;
		while(d != ',' ) {
			s += d;
			cin >> d;
			if(d == 'B')
				break;
		}
		put(0,s);
		if(d == 'B')
			break;
	}
	cin >> x;
	while(!cin.eof()) {
		s = "";
		cin >> d;
		while(d != ',' )  {
			s += d;
			if(cin.eof())
				break;
			if(!(cin >> d))
				break;
		}
		put(1,s);
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
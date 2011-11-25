#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int n,w,nw,ne;
bool input()
{
	string inn,type;
	cin >> inn;
	if(inn == "END")
		return false;
	for(int i = 0; i < inn.size(); i++)
		if(inn[i] == ',' || inn[i] == '.')
			inn[i] = ' ';
	stringstream ss(inn);
	int cnt;
	while(ss >> cnt >> type) {
		//cout << " H " << cnt << " H " << type << endl;
		if(type == "N")	n += cnt;
		else if(type == "S") n -= cnt;
		else if(type == "W") w += cnt;
		else if(type == "E") w -= cnt;
		else if(type == "NW") nw += cnt;
		else if(type == "SE") nw -= cnt;
		else if(type == "NE") ne += cnt;
		else ne -= cnt;
	}
	return true;
}
int main()
{
	long double q2(sqrt(0.5));
	double a,b;
	int cnt(1);
	while(input())
	{
		a = n*1.0+q2*(nw+ne);
		b = w*1.0+q2*(nw-ne);
		b = -b;
		printf("Map #%d\n",cnt++);
		printf("The treasure is located at (%.3f,%.3f).\n",a,b);
		printf("The distance to the treasure is %.3f.\n\n",sqrt(a*a+b*b));
		n = w = nw = ne = 0;
	}

	return 0;
}
/*
Map #1
The treasure is located at (3.000,2.000).
The distance to the treasure is 3.606.
Map #1
The treasure is located at (2.000,3.000).
The distance to the treasure is 3.606.
*/

#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define E 2.718281828
void f(char type,double &H,double &T,double &D,double tmp)
{
	if(type == 'H')
		H = tmp;
	else
		if(type == 'T')
			T = tmp;
		else
			D = tmp;
}
int main()
{
	char type;
	double tmp,H,h,e,T,D;
	while(true)
	{
		H = T = D = 0.0;
		cin >> type;
		if(type == 'E')
			return 0;
		cin >> tmp;
		f(type,H,T,D,tmp);
		cin >> type >> tmp;
		f(type,H,T,D,tmp);
		if(H == 0){
			e = 6.11 * pow(E,5417.7530 * ((1/273.16) - (1/(D+273.16))));
			h = (0.5555)* (e - 10.0);
			H = T + h;
		}
		else
			if(T == 0){
				e = 6.11 * pow(E,5417.7530 * ((1/273.16) - (1/(D+273.16))));
				h = (0.5555)* (e - 10.0);
				T = H - h;
			}
			else	{
				h = H - T;
				e = h / 0.5555 + 10.0;
				D = 273.16*5417.7530/(5417.7530 - 273.16 * log(e/6.11)) - 273.16;
			}
		printf("T %.1f D %.1f H %.1f\n",T,D,H);
	}
	return 0;
}
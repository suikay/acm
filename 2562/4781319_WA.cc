#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int x1,x2,res;
	int out(0);
	while(cin >> x1 >> x2)
	{
		out = 0;
		if(!x1 && !x2)
			break;
		res = x1 + x2;
		while(res){
			if((x1%10+x2%10) > res %10)
				out++;
			x1/=10;
			x2/=10;
			res/=10;
		}
		printf("%d carry operation%s.\n",out,(out>1)?"s":"");
	}
	return 0;
}
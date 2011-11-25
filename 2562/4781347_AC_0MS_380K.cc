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
		out = res = 0;
		if(!x1 && !x2)
			break;
		while(x1 || x2){
			//cout << x1%10+x2%10 << endl;
			if((x1%10+x2%10+res) >= 10){
				out++;
				res = 1;
			}
			else
				res = 0;
			x1/=10;
			x2/=10;
		}
		if(out)
			printf("%d carry operation%s.\n",out,(out>1)?"s":"");
		else
			printf("No carry operation.\n");
	}
	return 0;
}
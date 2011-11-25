#include <string>
#include <iostream>
#include <string.h>
using namespace std;
bool v[256];
int stat[256];
int main()
{
	int n;
	string left,right,eq;
	cin >> n;
	while(n--)
	{
		for(int i = 'A'; i <= 'L'; i++)
			stat[i] = -2;
		for(int i = 0; i < 3; i++)
		{
			cin >> left >> right >> eq;
			if(eq == "up")
				swap(left,right);
			if(eq == "even") 
			{
				for(int j = 0; j < 4; j++) 
					stat[left[j]] = stat[right[j]] = 0;
			}
			else
			{
				memset(v,false,sizeof(v));
				for(int j = 0; j < 4; j++) 
				{
					v[left[j]] = true;
					v[right[j]] = true;
					if(stat[left[j]] == -2) 
						stat[left[j]] = -1;
					else if(stat[left[j]] == 1)
						stat[left[j]] = 0;
					if(stat[right[j]] == -2) 
						stat[right[j]] = 1;
					else if(stat[right[j]] == -1)
						stat[right[j]] = 0;
				}
				for(int j = 'A'; j <= 'L'; j++)
					if(!v[j])
						stat[j] = 0;
			}
		}
		for(int i = 'A'; i <= 'L'; i++)
			if(stat[i] != 0) {
				cout << (char)i << " is the counterfeit coin and it is ";
				if(stat[i] == -1)
					cout << "light." << endl;
				else
					cout << "heavy." << endl;
			}
	}
	return 0;
}


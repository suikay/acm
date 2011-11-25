#include<string.h>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map<string,int> count;
int main()
{
	char tmp[35];
	int sum(0);
	while(gets(tmp))
	{
		count[tmp]++;
		sum++;
	}
	for(map<string,int>::iterator itr = count.begin(); itr != count.end(); itr++)
		printf("%s %.4f\n",itr->first.c_str(),itr->second*100.0/sum);
	return 0;
}
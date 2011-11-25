#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	char label[210];
	gets(label);
	int len = strlen(label);
	sort(label,label+len);
	do{
		printf("%s\n",label);
	}while(next_permutation(label,label+len));
	return 0;
}
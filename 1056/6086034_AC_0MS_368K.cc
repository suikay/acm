#include <stdio.h>
#include <string.h>
char arr[1000][100];
int main()
{
	int pos,cnt;
	bool flag;
	cnt = 1;
	while(true)
	{
		pos = 0;
		do {
			if(scanf("%s",arr[pos]) != 1)
				return 0;
		}while(arr[pos++][0] != '9');
		flag = true;
		for(int i = 0;flag && i < pos; i++)
			for(int j = 0;flag && j < pos; j++)
				if(i != j && strstr(arr[i],arr[j]) == arr[i])
					flag = false;
		if(flag)
			printf("Set %d is immediately decodable\n",cnt++);
		else
			printf("Set %d is not immediately decodable\n",cnt++);
	}
	return 0;
}
	
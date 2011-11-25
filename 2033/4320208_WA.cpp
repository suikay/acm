#include <stdio.h>
#include <memory.h>
#include <string.h>
int main()
{
	char str[50000];
	int data[50000];
	int i,len;
	str[0] = getchar();
	while(str[0] != '0')
	{
		memset(data,0,sizeof(data));
		gets(&str[1]);
		len = strlen(str);
		data[0] = 1;
		if (str[0] < '2' || ( str[0] =='2' && str[1] <= '6'))
			data[1] = 1;
		for ( i = 0; i < len - 1 ; i++)
		{
			data[ i + 1] += data[i];
			if (str[i + 1] < '2' ||( str[ i + 1 ] =='2' && str[ i + 2 ] <= '6'))
				data[i + 2] += data[i];
		}
		printf("%d\n",data[len-1]);
		str[0] = getchar();
	}
	return 0;
}
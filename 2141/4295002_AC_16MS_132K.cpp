#include <stdio.h>
#include <ctype.h>
char data[257];
int main()
{
	char c;
	for (int i = 'a'; i <= 'z';i++){
		scanf ("%c",&c);
		data[i] = c;
		data[toupper(i)] = toupper(c);
	}
	getchar();
	c = getchar();
	while(c != '\n'){
		if ( isalpha(c))
			printf("%c",data[c]);
		else
			printf("%c",c);
		c = getchar();
	}
	return 0;
}


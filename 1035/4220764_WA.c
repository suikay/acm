#include<stdio.h>
#include<string.h>
int count;
void sc(char *des,char *src)
{
	int des_len=strlen(des),src_len=strlen(src);
	int i;
	for(i=0;i<src_len;i++)
		des[des_len++]=src[i];
	des[des_len]='\0';
}
int unequal(char *s1,char *s2)
{
	int s2_len=strlen(s2);
	int i,j;
	for(i=0;i<s2_len;i++)
		if(s1[i]!=s2[i])
			for (j=i;j<s2_len;j++)
				if(s1[j+1]!=s2[j])
					return 0;
			return 1;
	
}
int equal(char *s1,char *s2)
{
	int i,count=0,s2_len=strlen(s2);
	for(i=0;i<s2_len;i++)
		if(s1[i]!=s2[i])
			count++;
	if (count>1)
		return 0;
}
int compare(char *s1,char *s2)
{
	int s1_len,s2_len;
	s1_len=strlen(s1);
	s2_len=strlen(s2);
	switch (s1_len-s2_len){
		case -1:return unequal(s2,s1);
		case 1:return unequal(s1,s2);
		case 0:return equal(s1,s2);
		default:return 0;
	}
}
int main()
{
	char dir[10000][52],word[52],buffer[150],out[52][150];
	int i=0,j,dir_len=0;
	gets(dir[0]);
	while(dir[dir_len++][0]!='#')
		gets(dir[dir_len]);
	dir_len--;
	gets(word);
	while(word[0]!='#')
	{
		strcpy(buffer,word);
		sc(buffer,":");
		for(i=0;i<dir_len;i++)
			if(!strcmp(dir[i],word)){
				sc(word," is correct");
				strcpy(out[count++],word);
				break;
			}else{
				if (compare(dir[i],word)){
					sc(buffer," ");
					sc(buffer,dir[i]);
				}
			}
		if(i==dir_len)
			strcpy(out[count++],buffer);
		strcpy(buffer,"");
		gets(word);
	}
	for(i=0;i<count-1;i++)
		printf("%s\n",out[i]);
	printf("%s",out[i]);
	return 0;
}
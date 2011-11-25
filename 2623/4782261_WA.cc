#include<stdio.h>
#define null NULL
struct Tree
{
	unsigned int val,lt,rt;
	Tree *l,*r;
};

void Insert(Tree* &root,int val)
{
	if(null==root){
		root = new Tree();
		root->val = val;
		root->l = null;
		root->r = null;
		root->lt = 0;
		root->rt = 0;
		return ;
	}
	if(root->val > val){
		Insert(root->l,val);
		(root->lt)++;
	}
	else	{
		Insert(root->r,val);
		(root->rt)++;
	}
}

unsigned int Find(Tree* &ro,int in,int l,int r)
{
	int dif = (ro->lt)+l-(ro->rt)-r;
	if(dif == in)
		return ro->val;
	if(dif < in)
		return Find(ro->r,in,ro->lt+l+1,r);
	else
		return Find(ro->l,in,l,ro->rt+r+1);
}

int main()
{
	Tree *root=null;
	unsigned n,tmp;
	scanf("%u",&n);
	for(int i = 0; i < n; i++)	{
		scanf("%u",&tmp);
		Insert(root,tmp);
	}
	if(!(n%2))
		printf("%.1f\n",0.5*Find(root,1,0,0)+0.5*Find(root,-1,0,0));
	else
		printf("%u",Find(root,0,0,0));
	return 0;
}
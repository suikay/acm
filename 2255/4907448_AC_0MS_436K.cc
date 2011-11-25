#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
struct Tree{
	Tree *leftt;
	Tree *rightt;
	char alpha;
};
Tree* Root;
void f(Tree* &root,string a,string b)
{
	if(a.size()){
		root = new Tree();
		root->alpha = a[0];
		f(root->leftt,a.substr(1,b.find(a[0])),b.substr(0,b.find(a[0])));
		f(root->rightt,a.substr(b.find(a[0])+1,99),b.substr(b.find(a[0])+1,99));
	}
	else
		root = NULL;
}
void ff(Tree* root)
{
	if(root->leftt)
		ff(root->leftt);
	if(root->rightt)
		ff(root->rightt);
	cout << root->alpha;
}
int main()
{
	string a,b;
	while(cin >> a >> b)
	{
		Root = NULL;
		f(Root,a,b);
		ff(Root);
		cout << endl;
	}
	return 0;
}
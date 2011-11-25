#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000;
struct Tree
{
	int l,r,w;
	bool operator()(const Tree &a,const Tree &b) {
		return a.w < b.w;
	}
};
Tree tree[N];
int pt;
int input()
{
	int cnt;
	pt = 0;
	string tmp;
	cin >> tmp;
	if(tmp == "END")
		return 0;
	for(char i = 'A'; i <= 'Z'; i++) {
		cnt = count(tmp.begin(),tmp.end(),i);
		if(cnt) {
			tree[pt].l = tree[pt].r = -1;
			tree[pt].w = cnt;
			pt++;
		}
	}
	cnt = count(tmp.begin(),tmp.end(),'_');
	if(cnt) {
		tree[pt].l = tree[pt].r = -1;
		tree[pt].w = cnt;
		pt++;
	}
	return tmp.size();
}
void build_tree()
{
	int pt_ori = pt,i(0);
	while(pt < 2*pt_ori-1){
		sort(tree+i,tree+pt,Tree());
		tree[pt].l = i;
		tree[pt].r = i+1;
		tree[pt].w = tree[i].w + tree[i+1].w;
		pt++;
		i += 2;
	}
}
int many(int n,int deep)
{
	int sum(0);
	if(n == -1)
		return 0;
	if(tree[n].l == -1 && tree[n].r == -1) 
		return deep * tree[n].w;
	sum = many(tree[n].l,deep+1) + many(tree[n].r,deep+1);
	return sum;
}
int main()
{
	int ori,cmp;
	while(ori = input()) {
		build_tree();
		cmp = many(pt-1,0);
		printf("%d %d %.1f\n",ori*8,cmp,8.0*ori/cmp+10e-5);
	}
	return 0;
}
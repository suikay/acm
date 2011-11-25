#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Query
{
	int Q_num;
	int time;
	int interval;
	bool operator<(Query &q) {
		if(time < q.time || (time == q.time &&
			Q_num < q.Q_num))
			return true;
		return false;
	}
	bool operator>(Query &q) {
		return !(*this < q);
	}
};

void swap(Query &a, Query &b)
{
	static Query tmp;
	//cout << "SWAP " << a.Q_num << " " <<
//		b.Q_num << endl;
	tmp = a;
	a = b;
	b = tmp;
}

Query heap[10100];
char input[30];

void MinifyHeap(int k,int size)
{
	int l;
	l = k;
	if((k << 1) <= size && (heap[k<<1] < heap[l]))
		l = k<<1;
	if(((k<<1)+1) <= size && (heap[(k<<1)+1] < heap[l]))
		l = (k<<1)+1;
	if(l != k) {
		swap(heap[l],heap[k]);
		MinifyHeap(l,size);
	}

}

void HeapIncreaseKey(int k)
{
	if(k == 1)
		return;
	if(heap[k] < heap[k>>1])
	{
		swap(heap[k],heap[k>>1]);
		HeapIncreaseKey(k>>1);
	}
}

void HeapPop(int &size)
{
	swap(heap[1],heap[size]);
	size--;
	MinifyHeap(1,size);
}

int main(int argc, char *argv[])
{
	int n, k, qnum, inter;
	n = 0;
	memset(heap,0x7f,sizeof(heap));
	while(true) {
		scanf("%s",input);
		if(input[0] == '#')
			break;
		scanf("%d%d",&qnum,&inter);
		heap[++n].Q_num = qnum;
		heap[n].interval = inter;
		heap[n].time = inter;
	}
	//initial
	for(int i = n/2; i >= 1; i--)
		MinifyHeap(i,n);
	scanf("%d",&k);
	while(k--)
	{
		printf("%d\n",heap[1].Q_num);
		HeapPop(n);
		++n;
		heap[n].time += heap[n].interval;
		HeapIncreaseKey(n);
	}

	return 0;
}

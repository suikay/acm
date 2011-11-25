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

Query heap[1100];
char input[30];

void MinifyHeap(int k)
{
	if(heap[k<<1] < heap[(k<<1)+1])
	{
		if(heap[k] > heap[k<<1]) {
			swap(heap[k],heap[k<<1]);
			MinifyHeap(k<<1);
		}
	} else {
		if(heap[k] > heap[(k<<1)+1]) {
			swap(heap[k],heap[(k<<1)+1]);
			MinifyHeap((k<<1) + 1);
		}
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

void HeapPop(int n)
{
	//cout << " POP " << endl;
	swap(heap[1],heap[n]);
	MinifyHeap(1);
}
	

int main(int argc, char *argv[])
{
	int n, k, qnum, inter;
	n = 0;
	memset(heap,0x7f,sizeof(heap));
	while(true) {
		gets(input);
		if(input[0] == '#')
			break;
		sscanf(input,"Register%d%d",&qnum,&inter);
		heap[++n].Q_num = qnum;
		heap[n].interval = inter;
		heap[n].time = inter;
	}
	//initial
	for(int i = n/2; i >= 1; i--)
		MinifyHeap(i);
	scanf("%d",&k);
	while(k--)
	{
		printf("%d\n",heap[1].Q_num);
		swap(heap[1],heap[n]);
		heap[n].time += heap[n].interval;
		MinifyHeap(1);
		//cout << heap[n].Q_num << heap[n].time << endl;
		HeapIncreaseKey(n);
	}


	
	return 0;
}

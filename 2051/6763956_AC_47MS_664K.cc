#include <iostream>
#include <string.h>
#include <stdio.h>

/**
最小堆的一个实现
**/
using namespace std;

struct Query
{
	int Q_num;
	int time;
	int interval;
	//比较函数
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
	tmp = a;
	a = b;
	b = tmp;
}

Query heap[1100];
char input[30];

//从上至下使得Heap符合性质
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

//插入一个节点
void HeapIncreaseKey(int k)
{
	if(k == 1)
		return;
	//如果该节点比它的父节点小,使其"上升"
	//继续与上一层的节点比较
	if(heap[k] < heap[k>>1])
	{
		swap(heap[k],heap[k>>1]);
		HeapIncreaseKey(k>>1);
	}
}

//弹出最小节点的函数
void HeapPop(int &size)
{
	//把最小的节点和最后的节点交换
	swap(heap[1],heap[size]);
	size--;
	//由于最后的节点不是最小的
	//所以要从该节点向下递推使其保持堆的性质
	MinifyHeap(1,size);
}

int main(int argc, char *argv[])
{
	int n, k, qnum, inter;
	n = 0;
	//初始化
	memset(heap,0x7f,sizeof(heap));
	while(true) {
//		scanf("%s",input);
//		if(input[0] == '#')
//			break;
//		scanf("%d%d",&qnum,&inter);
		gets(input);
		if(input[0] == '#')
			break;
		sscanf(input,"Register%d%d",&qnum,&inter);
		heap[++n].Q_num = qnum;
		heap[n].interval = inter;
		heap[n].time = inter;
	}
	//这一步很重要,先从最后一层开始向上递推
	//才能使得整个heap都符合堆的性质
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

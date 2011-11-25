/*钉子和小球（1189）

Description
有一个三角形木板,竖直立放，上面钉着n(n+1)/2颗钉子，还有(n+1)个格子（当n=5时如图1）。每颗钉子和周围的钉子的距离都等于d，每个格子的宽度也都等于d，且除了最左端和最右端的格子外每个格子都正对着最下面一排钉子的间隙。 让一个直径略小于d的小球中心正对着最上面的钉子在板上自由滚落，小球每碰到一个钉子都可能落向左边或右边（概率各1/2），且球的中心还会正对着下一颗将要碰上的钉子。例如图2就是小球一条可能的路径。 我们知道小球落在第i个格子中的概率pi=pi=，其中i为格子的编号，从左至右依次为0,1,...,n。 现在的问题是计算拔掉某些钉子后，小球落在编号为m的格子中的概率pm。假定最下面一排钉子不会被拔掉。例如图3是某些钉子被拔掉后小球一条可能的路径。 


Input
第1行为整数n（2 <= n <= 50）和m（0 <= m <= n）。以下n行依次为木板上从上至下n行钉子的信息，每行中'*'表示钉子还在，'.'表示钉子被拔去，注意在这n行中空格符可能出现在任何位置。
Output
仅一行，是一个既约分数(0写成0/1)，为小球落在编号为m的格子中的概pm。既约分数的定义：A/B是既约分数，当且仅当A、B为正整数且A和B没有大于1的公因子。
Sample Input
5 2
    *
   * .
  * * *
 * . * *
* * * * *
Sample Output
7/16
*/
//自底向上
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
char nail[55][55];
class Pi
{
public:
	__int64 numerator;      //分子
	__int64 denominator;    //分母
	void add(Pi x);
	friend __int64 q(__int64 x,__int64 y);
};
void Pi::add(Pi x)
{
	__int64 r,t;
	r=q(denominator,x.denominator*2);
	t=x.denominator*2/r*denominator;
	numerator=numerator*(x.denominator*2/r)+x.numerator*(denominator/r);
	denominator=t;
}
Pi pi[55][55];
void FindPi(int i,int j,Pi *x,int length);
__int64 q(__int64 x,__int64 y)
{
	__int64 r;
	while((y%x)!=0)
	{
		r=x;
		x=y%x;
		y=r;
	}
	return x;
}
int main()
{
	__int64 r;
	int i,j;
	char c;
//	FILE *p;
//	if((p=fopen("input2.txt","r"))==NULL)
//		printf("Fuck!");
	int length,position;
	while(scanf("%d %d",&length,&position)!=EOF)
	{
		//初始化
		for(i=0;i<51;i++)
		{
			for(j=0;j<51;j++)
			{
				pi[i][j].denominator=1;
				pi[i][j].numerator=0;
			}
		}
		getchar();
		for(i=0;i<length;i++)
		{
			for(j=0;j<=i;)
			{
				scanf("%c",&c);
				if(c=='*' || c=='.')
				{
					nail[i][j]=c;
					j++;
				}
			}
			getchar();
		}
	/*	c=fgetc(p);
	//	int n=55;
		while(c!=EOF)
		{
			for(i=0;i<length;i++)
			{
				for(j=0;j<=i;)
				{
					if(c=='*' || c=='.')
					{
						nail[i][j]=c;
						j++;
	//					n--;
					}
					c=fgetc(p);
				}
			}
		}*/
		pi[length][position].numerator=1;
		for(i=length-1;i>=0;i--)
		{
			for(j=0;j<=i;j++)
			{
				if(nail[i][j]=='*')
				{
					if(pi[i+1][j].numerator!=0)
					{
						pi[i][j].numerator=pi[i+1][j].numerator;
						pi[i][j].denominator=pi[i+1][j].denominator*2;
						r=q(pi[i][j].numerator,pi[i][j].denominator);
						pi[i][j].numerator/=r;
						pi[i][j].denominator/=r;
					}
					if(pi[i+1][j+1].numerator!=0)
					{
						pi[i][j].add(pi[i+1][j+1]);
						r=q(pi[i][j].numerator,pi[i][j].denominator);
						pi[i][j].numerator/=r;
						pi[i][j].denominator/=r;
					}
				}
				else if(nail[i][j]=='.')
				{
					FindPi(i,j,&pi[i][j],length);
				}
			}
		}
		if((pi[0][0].numerator==0 && pi[0][0].denominator==1) || (pi[0][0].numerator==1 && pi[0][0].denominator==1))
			printf("%d/1\n",(int)pi[0][0].numerator);
		else
		{
			r=q(pi[0][0].numerator,pi[0][0].denominator);
			printf("%I64d",pi[0][0].numerator/r);
			printf("/");
			printf("%I64d\n",pi[0][0].denominator/r);
		}
	}
	return 0;
}
void FindPi(int i,int j,Pi *x,int length)
{

   for(i=i+2;i<length;i+=2)
   {
		if(nail[i][++j]=='*')
		{
			(*x).numerator=pi[i][j].numerator;
			(*x).denominator=pi[i][j].denominator;
			return ;
		}
	}
	if (pi[i][++j].numerator==1)
	{
		(*x).numerator=1;
		(*x).denominator=1;
		return ;
	}
	else
	{
		(*x).numerator=0;
		(*x).denominator=1;
		return ;
	}   
}

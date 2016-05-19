/*hash判重*/
/*
1. 直接相加, 把(总和%大质数)为key.
2. 平方和相加, 把(总和%大质数)为key.
3. 从小到大的顺序, 对v[i]<<(i*3)依次异或, 然后模一个大质数作为key.(by hust07p43)
4. 六个数中非零数的积再乘上一个大质数,然后模一个100w上下的数。
自己拿随机数据测下来110w左右的效果最好，随机情况下数据量是10w的时候hash值相同的情况只有6k多个，几乎可以忽略。(by  killertom)
5. 依次对每个数异或所得的数作为key. (by archerstarlee)
6. (a[0] + a[2] + a[4])&(a[1] + a[3] + a[5]), 再模一个大质数. 中间的&还可以改成'|' 或者'^'.非常巧妙! 我采用'^'得到最快的719ms. (只对本题适用的hash方法)

其实最关键的就是要开放式寻址解决hash冲突, 不要以为hash就能解决问题了.
最后就是用getchar和gets来进行输入转换更为快速. G++比GCC快一些.
欢迎大家补充自己更为快速的Hash方法.
*/
/*AC代码：2344ms*/
#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#define MAXN 100000
#define MOD 99991
using namespace std;
struct Node
{
	int val[7];
};
struct Node Hash[MAXN][20];//hash表
int len[MAXN];//相应hash表的长度
int N;
bool ok;
int hash(Node u)//hash函数
{
	int i,sum=0;
	for(i=1;i<=6;i++)
		sum+=u.val[i];
	return sum%MOD;
}
void Rotate(Node &u)//移动
{
	int i,t=u.val[1];
	for(i=1;i<=5;i++)
		u.val[i]=u.val[i+1];
	u.val[6]=t;
}
void Reverse(Node &u)//翻转
{
	Node v;
	int i,j;
	for(i=1,j=6;i<=6;i++,j--)
		v.val[i]=u.val[j];
	u=v;
}
bool Equal(Node u,Node v)//判断是否相等
{
	int i;
	for(i=1;i<=6;i++)
	{
		if(u.val[i]!=v.val[i])
			return false;
	}
	return true;
}
void Judge(Node u,Node v)
{
	int i;
	for(i=1;i<=6;i++)
	{
		Rotate(u);
		if(Equal(u,v)) {ok=false;return;}
	}
	Reverse(u);
	for(i=1;i<=6;i++)
	{
		Rotate(u);
		if(Equal(u,v)) {ok=false;return;}
	}
}
void Init()
{
	int i,j;
	Node u;
	ok=true;
	memset(len,0,sizeof(len));
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=6;j++)
			scanf("%d",&u.val[j]);
		if(!ok) continue;
		int pos=hash(u);
		for(j=0;j<len[pos];j++)
		{
			Judge(u,Hash[pos][j]);
			if(!ok) break;
		}
		Hash[pos][len[pos]++]=u;
	}
}
void Solve()
{
	if(ok) printf("No two snowflakes are alike.\n");
	else printf("Twin snowflakes found.\n");
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		Init();
		Solve();
	}
	return 0;
}
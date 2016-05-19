//给你一个序列，要求找出它的递增子序列，按照长度从小到大，序列元素按字典序
//然后输入前m个子序列
/*
	按照深度一层一层的搜索，如果在寻找该层中满足条件的元素时，
	要判断之前是否出现过（是指之前找该层时是否出现过相等的元素）
	如果之前出现过，continue就可以了。
	没有的话，保留当前位置的值
	比如2 3 3 4
	我们上一层找到2了，这一层先找到3，因为3没出现过所以pre=3；
	然后循环继续，有找到该层中满足情况的一个3(3>=2)，因为之前已经出现过一个3了，所以continue就可以了。
	然后继续，找到满足的一个4(4>=2)，4之前没出现过，更新pre=4;
*/
#include"stdio.h"
#include"string.h"
#include"algorithm"
using namespace std;
#define N 101

int a[N];
int n,m;
struct node 
{
	int n,pos;
}A[N];
int f;
int cnt;
int len;
int path[N];
bool cmp(node a,node b)
{
	if(a.n!=b.n)
	return a.n<b.n;
	return a.pos<b.pos;
}

void print(int len)
{
	int i;
	for(i=0;i<len-1;i++)
		printf("%d ",path[i]);
	printf("%d\n",path[i]);

}
//dep为深度,pos为搜索的位置，repos表示重复的位置
int dfs(int dep,int pos,int repos)
{
	if(dep==len)
	{
		cnt++;
		print(len);
		if(cnt==m)return 1;
		return 0;
	}
	int pre;
	int f=0;
	for(int i=pos;i<=n;i++)
	{
		//子串的下标也是递增的
		if(A[i].pos>repos)
		{
			if(f==0){f=1;pre=A[i].n;}//判重
			//如果相等的话，说明有重的，continue
			else if(pre==A[i].n)continue;//判重
			pre=A[i].n;//如果不相等的话保留当前位置的值
			path[dep]=A[i].n;
			if(dfs(dep+1,i+1,A[i].pos))return 1;
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&A[i].n);
			A[i].pos=i;
		}
		sort(A+1,A+1+n,cmp);
		cnt=0;
		for(i=1;i<n;i++)
		{
			len=i;
			if(dfs(0,1,0))break;
		}
		printf("\n");
	}
	return 0;
}
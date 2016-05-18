#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
#define MAXN 10010
int pre1[MAXN], pre2[MAXN]; //父节点
int num1, num2;

struct graph //图的子结点数目，是否为环
{
	int son;
	bool ring;
};
graph g1[MAXN], g2[MAXN];

bool cmb(const graph &g1, const graph &g2) //子结点优先+先链后环排序
{
	if(g1.son < g2.son)
		return true;
	else if(g1.son == g2.son && g1.ring < g2.ring)
		return true;
	else
		return false;
}

int find(int x, int pre[]) //查找根结点+路径压缩
{
	return x == pre[x] ? x : find(pre[x], pre);
}

void join(int x, int y, int pre[],graph g1[]) //合并
{
	int root1, root2;
	root1 = find(x, pre);
	root2 = find(y, pre);
	if(root1 == root2)
		g1[root1].ring = true; //为环
	else
	{
		if(g1[root1].son >= g1[root2].son) //结点相加
		{
			pre[root2] = root1;
			g1[root1].son += g1[root2].son;
		}
		else
		{
			pre[root1] = root2;
			g1[root2].son += g1[root1].son;
		}
	}
}

bool cmp(int num, graph g1[], graph g2[]) //判断图是否同构
{
	sort(g1 + 1, g1 + num + 1, cmb); //排序
	sort(g2 + 1, g2 + num + 1, cmb);
	for(int i = 1; i <= num; ++i)
		if(g1[i].son != g2[i].son || (g1[i].son == g2[i].son && g1[i].ring != g2[i].ring))
			return false;
	return true;
}

int main()
{
	int ncase, T = 0;
	int link1, link2;
	int hand1, hand2;
	int ans1, ans2;
	bool flag;
	scanf("%d", &ncase);
	while(ncase--)
	{
		flag = true;
		scanf("%d%d", &num1, &link1);
		for(int i = 1; i < MAXN; ++i) //初始化
		{
			pre1[i] = i;
			pre2[i] = i;
			g1[i].son = 1;
			g2[i].son = 1;
			g1[i].ring = false;
			g2[i].ring = false;
		}
		for(int i = 1; i <= link1; ++i)
		{
			scanf("%d%d", &hand1, &hand2);
			join(hand1, hand2, pre1, g1);
		}
		scanf("%d%d", &num2, &link2);
		if(link2 != link1) //边数不同跳出
			flag = false;
		for(int i = 1; i <= link2; ++i)
		{
			scanf("%d%d", &hand1, &hand2);
			if(flag == false)
				continue;
			else
				join(hand1, hand2, pre2, g2);
		}
		flag = cmp(num2, g1, g2);
		if(flag == false)
			printf("Case #%d: NO\n", ++T);
		else
		{
			if(flag)
				printf("Case #%d: YES\n", ++T);
			else
				printf("Case #%d: NO\n", ++T);
		}
	}
	return 0;
}
/* ***********************************************
Author        :kuangbin
Created Time  :2013-9-28 10:05:55
File Name     :E:\2013ACM练习\专题强化训练\图论一\LightOJ1291.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAXN = 10010;
const int MAXM = 40010;
struct Edge
{
	int to,next;
	bool cut;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN];
int Index ,top;
int block;
bool Instack[MAXN];
int bridge;
void addedge(int u,int v)
{
	edge[tot].to = v; edge[tot].next = head[u]; edge[tot].cut = false;
	head[u] = tot++;
}
void Tarjan(int u,int pre)
{
	int v;
	Low[u] = DFN[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = true;
	int pre_num = 0;
	for(int i = head[u]; i != -1;i = edge[i].next)
	{
		v = edge[i].to;
		if(v == pre && pre_num == 0){pre_num++;continue;}
		if(!DFN[v])
		{
			Tarjan(v,u);
			if(Low[u] > Low[v])Low[u] = Low[v];
			if(Low[v] > DFN[u])
			{
				bridge++;
				edge[i].cut = true;
				edge[i^1].cut = true;
			}
		}
		else if(Instack[v] && Low[u] > DFN[v])
			Low[u] = DFN[v];
	}
	if(Low[u] == DFN[u])
	{
		block++;
		do
		{
			v = Stack[--top];
			Instack[v] = false;
			Belong[v] = block;
		}
		while( v != u);
	}
}
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
}
int du[MAXN];
int solve(int n)
{
	memset(DFN,0,sizeof(DFN));
	memset(Instack,false,sizeof(Instack));
	Index = top = block = 0;
	Tarjan(0,0);
	int ans = 0;
	memset(du,0,sizeof(du));
	for(int i = 0;i < n;i++)
		for(int j = head[i];j != -1;j = edge[j].next)
			if(edge[j].cut)
				du[Belong[i]]++;
	for(int i = 1;i <= block;i++)
		if(du[i] == 1)
			ans++;
	return (ans+1)/2;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
	int iCase = 0;
	int n,m;
	scanf("%d",&T);
	int u,v;
	while(T--)
	{
		iCase++;
		init();
		scanf("%d%d",&n,&m);
		while(m--)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		printf("Case %d: %d\n",iCase,solve(n));
	}
    return 0;
}
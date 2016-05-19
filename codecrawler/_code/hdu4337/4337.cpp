/**
hdu 4339 判环
题目大意：给定n个点以及m个两两对应的路，判断是否可以构成一个环。
解题思路：dfs即可
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=1005;

struct note
{
    int v,next;
} edge[maxn*40];
int head[maxn],ip,cnt;

int k,num[maxn],n,m,flag[maxn];

void init()
{
    memset(head,-1,sizeof(head));
    ip=0;
}

void addedge(int u,int v)
{
    edge[ip].v=v,edge[ip].next=head[u],head[u]=ip++;
}

void dfs(int u)
{
    if(k==n)
    {
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            if(v==1)
            {
                cnt=1;
            }
        }
        if(cnt==1)
        {
            for(int i=0;i<n;i++)
                printf(i==k-1?"%d\n":"%d ",num[i]);
        }
        return;
    }
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(flag[v]==0&&cnt==0)
        {
            num[k++]=v;
            flag[v]=1;
            dfs(v);
            if(cnt==0)
            {
               flag[v]=0;
               k--;
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        memset(flag,0,sizeof(flag));
        k=0;
        flag[1]=1;
        num[k++]=1;
        cnt=0;
        dfs(1);
        if(cnt==0)
           puts("no solution");
    }
    return 0;
}
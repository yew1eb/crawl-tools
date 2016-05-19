// File Name: 11865.cpp
// Author: zlbing
// Created Time: 2013/2/17 22:36:04

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define MAXN 205
struct Edge{
    int from,to,dist,band;
}edges[MAXN*MAXN];
int In[MAXN];
int pre[MAXN],ID[MAXN],vis[MAXN];
bool Directed_MST(int root,int n,int m,int C,int B)
{
    long long ans=0;
    while(true)
    {
        //1、找最小入边
        for(int i=0;i<n;i++)In[i]=INF;
        for(int i=0;i<m;i++)
        {
            int u=edges[i].from;
            int v=edges[i].to;
            if(edges[i].dist<In[v]&&u!=v&&edges[i].band>=B)
            {
                pre[v]=u;
                In[v]=edges[i].dist;
            }
        }
        //2、判断是否有最小生成树
        for(int i=0;i<n;i++)
        {
            if(i==root)continue;
            if(In[i]==INF)return false;
        }
        //3、找环
        int cntnode=0;
        CL(ID,-1);
        CL(vis,-1);
        In[root]=0;
        for(int i=0;i<n;i++)
        {
            ans+=In[i];
            int v=i;
            while(vis[v]!=i&&ID[v]==-1&&v!=root)
            {
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&ID[v]==-1)
            {
                for(int u=pre[v];u!=v;u=pre[u])
                {
                    ID[u]=cntnode;
                }
                ID[v]=cntnode++;
            }
        }
        if(cntnode==0)break;
        for(int i=0;i<n;i++)
            if(ID[i]==-1)
                ID[i]=cntnode++;
        //4、缩点，重新标记
        for(int i=0;i<m;i++)
        {
            int v=edges[i].to;
            edges[i].from=ID[edges[i].from];
            edges[i].to=ID[edges[i].to];
            if(edges[i].from!=edges[i].to)
            {
                edges[i].dist-=In[v];
            }
        }
        n=cntnode;
        root=ID[root];
    }
    if(ans<=C)
    return true;
    else return false;
}
int main(){
    int T;
    scanf("%d",&T);
    int N,M,C;
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&C);
        int a,b,c,d;
        int maxn=0,minn=INF;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            edges[i].from=a;
            edges[i].to=b;
            edges[i].band=c;
            edges[i].dist=d;
            edges[i+M].from=a;
            edges[i+M].to=b;
            edges[i+M].band=c;
            edges[i+M].dist=d;
            maxn=max(maxn,c);
            minn=min(minn,c);
        }
        if(Directed_MST(0,N,M,C,minn)==false)
            printf("streaming not possible.\n");
        else{
            int L=minn,R=maxn;
            while(L<R)
            {
                int mid=L+(R-L+1)/2;
                for(int i=0;i<M;i++)
                edges[i]=edges[i+M];
                if(!Directed_MST(0,N,M,C,mid))
                    R=mid-1;
                else L=mid;
            }
            printf("%d kbps\n",L);
        }
    }
    return 0;
}
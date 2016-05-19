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
#define clear(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))
#define clearall(A, X) memset(A, X, sizeof(A))
#define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))
#define memcopy1all(A, X) memcpy(A , X ,sizeof(X))
#define max( x, y )  ( ((x) > (y)) ? (x) : (y) )
#define min( x, y )  ( ((x) < (y)) ? (x) : (y) )

using namespace std;

struct node
{
    int u,v,c,f,next;
} edge[21000];
char s[12][15];
const int inf=1<<30;
int head[210],cnt,dis[210],pre[210],n,m,cost,flow;
bool vis[210];
bool spfa()
{
    int i,u;
    clearall(pre,-1);
    clearall(dis,0x3f3f3f);
    clearall(vis,false);
    queue <int>q;
    dis[n*m*2]=0;
    vis[n*m*2]=true;
    q.push(n*m*2);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        i=head[u];
        vis[u]=false;
        while(i!=-1)
        {
            if(edge[i].f>0&&dis[edge[i].v]>dis[u]+edge[i].c)
            {
                dis[edge[i].v]=dis[u]+edge[i].c;
                pre[edge[i].v]=i;
                if(!vis[edge[i].v])
                {
                    vis[edge[i].v]=true;
                    q.push(edge[i].v);
                }
            }
            i=edge[i].next;
        }
    }
    if(pre[2*n*m+1]==-1)return false;
    else return true;
}
void does()
{
    cost=0;
    flow=0;
    while(spfa())
    {
        int max1=inf;
        int p=pre[2*n*m+1];
        while(p!=-1)
        {
            max1=min(max1,edge[p].f);
            p=pre[edge[p].u];
        }
        p=pre[2*n*m+1];
        while(p!=-1)
        {
            edge[p].f-=max1;
            edge[p^1].f+=max1;
            cost+=max1*edge[p].c;
            p=pre[edge[p].u];
        }
        flow+=max1;
    }
}
void addedge(int u,int v,int f,int c)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].f=f;
    edge[cnt].c=c;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].u=v;
    edge[cnt].v=u;
    edge[cnt].f=0;
    edge[cnt].c=-c;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
int main()
{
    int T,k,case1=1,u,v,f,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[i]);
        }
        clearall(head,-1);
        cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                u=i*m+j;
                for(int k=j+1; k<m; k++) //right
                {
                    v=i*m+k+n*m;
                    c=k-j-1;
                    c=-c;
                    if(s[i][j]==s[i][k])c+=s[i][j]-'0';
                    addedge(u,v,1,-c);
                }
                for(int k=i+1; k<n; k++) //down
                {
                    v=k*m+j+n*m;
                    c=k-i-1;
                    c=-c;
                    if(s[i][j]==s[k][j])c+=s[i][j]-'0';
                    addedge(u,v,1,-c);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                addedge(2*n*m,i*m+j,1,0);
                addedge(i*m+j+n*m,2*n*m+1,1,0);
                addedge(2*n*m+2,i*m+j+n*m,1,0);
            }
        }
        addedge(2*n*m,2*n*m+2,k,0);
        does();
        printf("Case %d : ",case1++);
        if(flow!=n*m)puts("-1");
        else printf("%d\n",-cost);
    }
    return 0;
}

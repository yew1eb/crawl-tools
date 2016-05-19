#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
#define maxn 100001
#define maxm 300001
int Start,End,pre[maxn],vis[maxn],low[maxn],Top,head[maxn];;

struct edge 
{
    int y, next;
} e[maxm];
void insert(int x, int y)
{
     e[Top].y=y;
     e[Top].next = head[x];
     head[x] = Top++;
}

void ini(int n)
{
    Top=0;
    for(int i=0;i<=n;i++)
    {
        vis[i]=low[i]=0;
        head[i]=-1;
    }
}
int Bfs1(int u)            //找最短路 
{
    int w,p;
    pre[u]=-1;
    queue<int>q;
    q.push(u);
    vis[u]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
         for (p = head[u]; p != -1; p = e[p].next)
         {
             w= e[p].y;
            if(vis[w]==0)
            {
                q.push(w);
                vis[w]=1;
                pre[w]=u;
                if(w==End)return 1;
            }
        }
    }
    return 0;
}
int Bfs2(int u)             //搜可删点 
{
    int w,res=u,p;
    queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
         for (p = head[u]; p != -1; p = e[p].next)
         {
             w= e[p].y;
            if(vis[w]==0)
            {
                vis[w]=1;
                if(low[w]==0)q.push(w);     //如果点不在最短路上，进队 
                else if(low[res]>low[w])res=w;  //在最短路上，则更新res, 
            }

        }
    }
    return res;      //最终结束得到的可删点 
}
int main()
{
    int n,m,i,j,x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ini(n);
         for ( i = 0; i < m; ++i) {
             int a, b;
             scanf("%d%d", &a, &b);
             insert(a, b);
         }
        scanf("%d%d",&Start,&End);
        if(n==0||n==1)
        {
            printf("%d\n",n);
            continue;
        }
        if(!Bfs1(Start))       //图是不联通的，则左右点都可删 
        {
            printf("%d\n",n);
            continue;
        }
        else
        {
             i=End;
             int top=1;
             while(pre[i]!=-1)     //记录找的的最短路； 
             {
                  low[i]=top++;
                   i=pre[i];
             }
             low[Start]=top;
        }
        int res=1;   
        for(i=0;i<n;i++)vis[i]=0;
        i=Start;
        vis[Start]=1;
        while(i!=End)   //从起点开始搜，没BFS2一次，得到一个可删点 
        {
            i=Bfs2(i);
            res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
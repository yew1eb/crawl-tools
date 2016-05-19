#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define inf 0x7fffffff
using namespace std;
const int nodes=10000;
const int edges=200000+500;
struct node
{
    int v,next,w;
}e[edges];
int head[nodes],cnt,max_dis[nodes];
int nz,nr;
void Init()
{
    memset(head,-1,sizeof(head));
    cnt=0;
    memset(max_dis,-1,sizeof(max_dis));
}
void add(int a,int b,int c)
{
    e[cnt].v=b;
    e[cnt].w=c;
    e[cnt].next=head[a];
    head[a]=cnt++;
}
void spfa(int s)
{
    queue<int>q;
    while(!q.empty()) q.pop();
    int dis[nodes],vis[nodes];
    for(int i=1;i<=9999;i++)
    {
        dis[i]=inf;
        vis[i]=0;
    } 
    vis[s]=1;
    dis[s]=0;
    if(max_dis[s]==-1)
    max_dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i+1;i=e[i].next)
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                if(max_dis[v]<dis[v])
                max_dis[v]=dis[v];
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&nz,&nr);
        Init();
        for(int i=1;i<=nz;i++)
        {
            int a,num;
            scanf("%d%d",&a,&num);
            while(num--)
            {
                int b;
                scanf("%d",&b);
                add(a,b,1);
                add(b,a,1);
            }
        }
        for(int i=1;i<=nr;i++)
        {
            int num;
            scanf("%d",&num);
            while(num--)
            {
                int a;
                scanf("%d",&a);
                spfa(a);
            }
        }
        int pos,val=inf;
        for(int i=1;i<=9999;i++)
        {
            if(max_dis[i]<val&&max_dis[i]!=-1)
            {
                val=max_dis[i];
                pos=i;
            }
        }
        printf("%d %d\n",val+1,pos);
    }
    return 0;
}
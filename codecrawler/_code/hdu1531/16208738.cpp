#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=110;
const int INF=1<<29;
int head[MAXN],size;
struct EDGE
{
    int v,next;
    int dis;
}edge[MAXN*4];
void init()
{
    memset(head,-1,sizeof(head));
    size=0;
}
void add_edge(int u,int v,int dis)
{
    edge[size].v=v;
    edge[size].dis=dis;
    edge[size].next=head[u];
    head[u]=size++;
}
int dis[MAXN],cnt[MAXN],n;
bool vis[MAXN];
bool spfa(int s)
{
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<=n+1;i++)
        dis[i]=INF;
    dis[s]=0;
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(dis[v]>dis[u]+edge[i].dis)
            {
                dis[v]=dis[u]+edge[i].dis;
                if(!vis[v])
                {
                    vis[v]=1;
                    cnt[v]++;
                    if(cnt[v]>n+1)
                        return 0;
                    q.push(v);
                }
            }
        }
    }
    return 1;
}
int main()
{
    char ch[3];
    int m,u,v,k,i;
    while(scanf("%d",&n)==1&&n)
    {
        scanf("%d",&m);
        init();
        while(m--)
        {
            scanf("%d%d%s%d",&u,&v,ch,&k);
            if(ch[0]=='g')
            {
                add_edge(u+v,u-1,-k-1);
            }
            else
            {
                add_edge(u-1,u+v,k-1);
            }
        }
        int st=n+1;
        for(i=0;i<=n;i++)
            add_edge(st,i,0);
        if(spfa(st))
        {
            printf("lamentable kingdom\n");
        }
        else
        {
            printf("successful conspiracy\n");
        }
    }
    return 0;
}

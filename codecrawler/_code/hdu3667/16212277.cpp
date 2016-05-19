#include<cstdio>
#include<string.h>
#include<queue>
#include<algorithm>
#define maxn 1100
#define inf 0x3f3f3f
using namespace std;
struct node
{
    int st;
    int en;
    int flow,cost;
    int next;
}E[maxn*maxn];
int num;
int p[maxn];
void init()
{
    memset(p,-1,sizeof p);
    num=0;
}
void add(int st,int en,int flow,int cost)
{
    E[num].st=st;
    E[num].en=en;
    E[num].flow=flow;
    E[num].cost=cost;
    E[num].next=p[st];
    p[st]=num++;
    E[num].st=en;
    E[num].en=st;
    E[num].flow=0;
    E[num].cost=-cost;
    E[num].next=p[en];
    p[en]=num++;
}
int pre[maxn];
int dis[maxn];
bool fg[maxn];

bool spfa(int st,int en)
{
    for(int i=0;i<=en;i++)
        fg[i]=0,dis[i]=inf,pre[i]=-1;
    queue<int>q;
    q.push(st);
    fg[st]=1;
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        fg[u]=0;
        for(int i=p[u];i+1;i=E[i].next)
        {
            int v=E[i].en;
            if(E[i].flow&&dis[v]>dis[u]+E[i].cost)
            {
                dis[v]=dis[u]+E[i].cost;
                pre[v]=i;
                if(!fg[v])
                {
                    fg[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if(dis[en]<inf)
        return 1;
    return 0;
}
int f;
int solve(int st,int en)
{
    int ans=0;
    while(spfa(st,en))
    {
        f++;
        for(int i=pre[en];i+1;i=pre[E[i].st])
        {
            E[i].flow-=1;///æ¯æ¬¡è·å®å¿ä¸º1ï¼å ä¸ºä½ çå®¹éé½æ¯1
            E[i^1].flow+=1;
            ans+=E[i].cost;
        }
    }
    return ans;
}

int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        init();
        for(int i=1;i<=m;i++)
        {
            int x,y,a,c;
            scanf("%d%d%d%d",&x,&y,&a,&c);
            for(int j=1,cnt=1;cnt<=c;j+=2,cnt++) add(x,y,1,a*j);
        }
        add(n,n+1,k,0);///å»ºä¸ä¸ªæ±ç¹ï¼éå¶å®è·kæ¬¡
        f=0;
        int ans=solve(1,n+1);
        if(f==k) printf("%d\n",ans);
        else puts("-1");
    }
    return 0;
}


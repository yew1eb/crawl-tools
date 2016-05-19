#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=10005;

int u[maxn],v[maxn]; //çºªå½æ¯æ¡è¾¹
int w[maxn],ind[maxn]; //wçºªå½æ¯ä¸ªç¹çæå¼ï¼indçºªå½æ¯ä¸ªç¹çåº¦æ°
bool vis[maxn]; //æ è®°removeæä½åè¿å©ä¸çç¹
//ååæå­å¨å¾
struct EDGE
{
    int to,nex;
}edge[maxn*20];
int head[maxn],num;
void add(int u,int v)
{
    edge[num].to=v;
    edge[num].nex=head[u];
    head[u]=num++;
}
//å¹¶æ¥é
int par[maxn],ran[maxn];
long long sum[maxn];
void Init(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        ran[i]=1;
        sum[i]=w[i];
    }
}
int Find(int x)
{
    if(par[x]!=x) return par[x]=Find(par[x]);
    return x;
}
void Union(int a,int b)
{
    int x=Find(a);
    int y=Find(b);
    if(x==y) return ;
    par[y]=x;
    ran[x]+=ran[y];
    sum[x]+=sum[y];
}

void Top_sort(int n)
{
    queue <int> que;
    for(int i=1;i<=n;i++)
      if(ind[i]<=1)
      {
          vis[i]=false;
          que.push(i);
      }
    while(!que.empty())
    {
        int cnt=que.front();
        que.pop();
        for(int i=head[cnt];i!=-1;i=edge[i].nex)
        {
            int x=edge[i].to;
            if(vis[x])
            {
                ind[x]--;
                if(ind[x]==1)
                {
                    vis[x]=false;
                    que.push(x);
                }
            }
        }
    }
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,true,sizeof(vis));
        memset(head,-1,sizeof(head));
        memset(ind,0,sizeof(ind));
        num=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
          scanf("%d",&w[i]);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            add(u[i],v[i]);
            add(v[i],u[i]);
            ind[ u[i] ]++,ind[ v[i] ]++;
        }
        Top_sort(n);
        Init(n);
        for(int i=0;i<m;i++)
        {
            if(vis[ u[i] ]&&vis[ v[i] ])
              Union(u[i],v[i]);
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
          if(i==par[i]&&vis[i]&&(ran[i]&1))
            ans+=sum[i];
        printf("%I64d\n",ans);
    }
    return 0;
}

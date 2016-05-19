#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN=1005;
const int MAXM=20005;
struct node
{
    int u,v,w;
};
node edge[MAXM];
int first[MAXN],next[MAXM];
int cc,n,m,s,k;
inline void add_edge(int u,int v,int w)
{
    edge[cc].u=u;
    edge[cc].v=v;
    edge[cc].w=w;
    next[cc]=first[u];
    first[u]=cc;
    cc++;
}
char tag[MAXN];
int dis[MAXN][MAXN];
int res,z;
void dfs(int u,int cur_d)
{
    int i;
    if(tag[u]=='P'&&cur_d%k==0&&(cur_d<res||(cur_d==res&&u<z)))
    {
        res=cur_d;
        z=u;
        return ;
    }
    for(i=first[u];i!=-1;i=next[i])
    {
        int v=edge[i].v;
        int d=cur_d+edge[i].w;
        if(dis[v][d%k]==-1||dis[v][d%k]>d)
        {
            dis[v][d%k]=d;
            dfs(v,d);
        }

    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        cas++;
        scanf("%d%d%d%d",&n,&m,&s,&k);
        int i;
        getchar();
        for(i=1;i<=n;i++)
            scanf("%c",&tag[i]);
        memset(first,-1,sizeof(first));
        memset(next,-1,sizeof(next));
        cc=0;
        memset(dis,-1,sizeof(dis));
        for(i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
        }
        res=INF;
        z=0;
        dfs(s,0);
        printf("Case %d:",cas);
        if(res==INF)
            printf(" -1 -1\n");
        else
            printf(" %d %d\n",res,z);
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define NMAX 1317
#define MMAX 13525
#define oo 1000000000000000LL
struct node
{
    int to,next,w;
} e[MMAX<<1];
int n,m;
int head[NMAX<<2],edge;
bool vis[NMAX<<2];
long long dis[NMAX<<2];
int ds[NMAX<<2];
queue<int>q;
int L[4];
void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}
inline int f(char a)
{
    if(a=='L') return 0;
    if(a=='O') return 1;
    if(a=='V') return 2;
    return 3;
}
void add(int u,int v,int c)
{
    e[edge].to=v,e[edge].w=c,e[edge].next=head[u],head[u]=edge++;
}
bool spfa()
{
    int v,i;
    while(!q.empty()) q.pop();
    for(i=0; i<4*n; i++)
        {
            dis[i]=(i==0?0:oo);
            ds[i]=(i==0?0:MMAX);
        }
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    q.push(0);
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(i=head[tmp]; i!=-1; i=e[i].next)
        {
            if(dis[tmp]+e[i].w<=dis[v=e[i].to])
            {
                if(dis[tmp]+e[i].w<dis[v])
                {
                    dis[v]=dis[tmp]+e[i].w;
                    ds[v]=ds[tmp]+1;
                }
                else
                    ds[v]=max(ds[tmp]+1,ds[v]);
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        vis[tmp]=false;
    }
    return true;
}
int main()
{
    int t,u,v,l;
    char ch[5];
    scanf("%d",&t);
    for(int ca=1; ca<=t; ca++)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=0;i<4;i++) L[i]=100000000;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%s",&u,&v,&l,ch);
            int t1=f(ch[0]);
            int t2=t1+1>3?0:t1+1;
            L[t1]=min(L[t1],l);
            add(4*(u-1)+t1,4*(v-1)+t2,l);
            add(4*(v-1)+t1,4*(u-1)+t2,l);
        }
        spfa();
        printf("Case %d: ",ca);
        if(n>1)
        {
            if(dis[4*(n-1)]<oo)
            printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",dis[4*(n-1)],ds[4*(n-1)]/4);
        else puts("Binbin you disappoint Sangsang again, damn it!");
        }
        else {
        int ans=0;
        for(int i=0;i<4;i++)
        ans+=L[i];
        if(ans>100000000) puts("Binbin you disappoint Sangsang again, damn it!");
        else printf("Cute Sangsang, Binbin will come with a donkey after travelling %d meters and finding 1 LOVE strings at last.\n",ans);
        }
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#define N 100010
#define LL long long
#pragma comment(linker, "/STACK:16777216")
LL cnt;
int n,k;
int head[N],next[2*N][2],vis[N];
void add(int u,int v)
{
    next[k][1]=v;
    next[k][0]=head[u];
    head[u]=k++;
}
int dfs(int cur,int fa)
{
    int count=1;
    LL s=0;
    for(int i=head[cur]; i!=-1; i=next[i][0])
    {
        int v=next[i][1];
        if(v==fa) continue;
        count+=dfs(v,cur);
    }
    for(int i=head[cur]; i!=-1; i=next[i][0])
    {
        int v=next[i][1];
        if(v==fa) continue;
        s=s+(LL)(count-vis[v]-1)*vis[v];
    }
    cnt=cnt+(LL)(count-1)*(n-count)+s/2;
    return vis[cur]=count;
}
int main()
{
  //  freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(head,-1,sizeof(int)*(n+1));
        k=0,cnt=0;
        int u,v;
        for(int i=1; i<n; ++i)
        {
            scanf("%d%d",&u,&v);
            add(u-1,v-1);
            add(v-1,u-1);
        }
        dfs(0,-1);
        printf("%I64d\n",(LL)n*(n-1)*(n-2)/6-cnt);
    }
    return 0;
}
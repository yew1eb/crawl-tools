#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 100000000
using namespace std;
int map[1005][1005];
int d[1005];
int vis[1005];
void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            map[i][j]=INF;
        d[i]=INF;
    }
    memset(vis,0,sizeof(vis));
}
struct cmp
{
    bool operator()(int lhs,int rhs)
    {
        return d[lhs]>d[rhs];
    }
};
int main()
{
    int n,m,s;
    while(scanf("%d%d%d",&n,&m,&s)!=EOF)
    {
        init(n);
        int i;
        int a,b,c;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<map[a][b])
                map[a][b]=c;
        }
        int w;
        scanf("%d",&w);
        for(i=0;i<w;i++)
        {
            scanf("%d",&a);
            map[0][a]=0;    ///æ­¤å¤å°æå·§ï¼ækikiçä½0èµ·å§ç¹å°0å¤ï¼è·ç¦»ä¸º0
        }
        priority_queue<int,vector<int>,cmp> q;
        d[0]=0;
        q.push(0);
        while(!q.empty())
        {
            int t=q.top();
            q.pop();
            if(vis[t])
                continue;
            vis[t]=1;
            for(i=0;i<=n;i++)
            {
                if(!vis[i]&&d[i]>d[t]+map[t][i])
                {
                    d[i]=d[t]+map[t][i];
                    q.push(i);
                }
            }
        }
        if(d[s]==INF)
            printf("-1\n");
        else
            printf("%d\n",d[s]);
    }
    return 0;
}

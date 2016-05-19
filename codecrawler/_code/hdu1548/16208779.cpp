#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 222222222
using namespace std;
int map[205][205];
int d[205];
int vis[205];
void init(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        d[i]=INF;
    }
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
}
void BFS(int n,int a,int b)
{
    d[a]=0;
    vis[a]=1;
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        int i;
        for(i=1;i<=n;i++)
        {
            if(!vis[i]&&map[t][i])
            {
                vis[i]=1;
                d[i]=d[t]+1;
                q.push(i);
            }
        }
    }
}
int main()
{
    int n,a,b;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&a,&b);
        init(n);
        int i,t;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            if(i+t<=n&&t+i>=1)
                map[i][i+t]=1;
            if(i-t>=1&&i-t<=n)
                map[i][i-t]=1;
        }
        BFS(n,a,b);
        if(d[b]>=INF||a>n||b>n||a<1||b<1)
            printf("-1\n");
        else if(a==b)
            printf("0\n");
        else
            printf("%d\n",d[b]);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define INF 1000010010
using namespace std;
int d[1005];
int vis[1005];
int w[1005][1005];
int s[1005];
void init(int n)
{
    memset(s,0,sizeof(s));
    memset(vis,0,sizeof(vis));
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            w[i][j]=INF;
            if(i==j)
                w[i][j]=0;
        }
        d[i]=INF;
    }
}
int DFS(int k,int n)
{
    if(s[k])
        return s[k];
     if(k == 2)
        return 1;
    for(int i=1; i<=n; i++)
     {
         if(w[k][i]!=INF && d[k]>d[i])
            s[k]+=DFS(i,n);
   }
    return s[k];
}
struct cmp
{
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
int main()
{
    int n,m;
    while(scanf("%d",&n),n!=0)
    {
        init(n);
        scanf("%d",&m);
        int i,a,b,d1;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&d1);
            if(d1<w[a][b])
                w[a][b]=w[b][a]=d1;
        }

        d[2]=0;
        //priority_queue<int,vector<int>,cmp> q;
        typedef pair<int,int> pii;
        priority_queue<pii,vector<pii>,greater<pii> > q;
        q.push(make_pair(d[2],2));
        while(!q.empty())
        {
            pii t1=q.top();
            q.pop();
            int t=t1.second;
            if(vis[t])
                continue;
            vis[t]=1;
            for(i=1;i<=n;i++)
            {
                if(!vis[i]&&d[i]>d[t]+w[t][i])
                {
                    d[i]=d[t]+w[t][i];
                    q.push(make_pair(d[i],i));
                }
            }
        }

        printf("%d\n",DFS(1,n));

    }
    return 0;
}

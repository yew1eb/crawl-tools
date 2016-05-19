#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
/*
类似 poj 3229 http://blog.csdn.net/azheng51714/article/details/8166632
有n个城市，规定m个城市必须去,求最短时间花费
每到一个城市要休息a[i]时间 ,先dij求得各点的最短距离，然后状态压缩DP 求一个类似汉密尔顿回路
*/
using namespace std;
const int INF=1e9;
int tre[232][232];
int n,m,u,v,cnt,node[32],cos[32];
int dp[20][1<<16],a[30],K,map[202][202],g[32][32];
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
int dis[210*210],vis[210*210],sum;
struct Node
{
    int v,w;
    Node() {};
    Node(int v1,int w1)
    {
        v=v1,w=w1;
    };
    bool operator < (const Node &a) const
    {
        return w > a.w;
    }
} Edge[2000002],t1,t2;
void dijstra(int  st,int pos)
{
    int i,j;
    memset(vis,0,sizeof(vis));
    priority_queue<Node>q;
    for(i=0; i<sum; i++)
    {
        dis[i]=INF;
    }
    dis[st]=0;//此句没加错了2次，囧~~~
    q.push(Node(st,0));
    while(!q.empty())
    {
        t1 = q.top();
        q.pop();
        int u = t1.v;
        if(vis[u]) continue;
        vis[u] = 1;
        int x=u/m,y=u%m;
        if(tre[x][y]!=-1)
        {
            g[pos][tre[x][y]]=dis[u];
        }
        if(x==0||x==n-1||y==0||y==m-1)
        {
            cos[pos]=min(cos[pos],dis[u]);
        }
        for(i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(map[nx][ny]==-1) continue;
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            int nu=nx*m+ny;
            if(dis[nu]>dis[u]+map[nx][ny])
            {
                dis[nu]=dis[u]+map[nx][ny];
                q.push(Node(nu,dis[nu]));
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int i,j,k;
        cnt=0,sum=n*m;
        memset(tre,-1,sizeof(tre));
        memset(dp,0x7f,sizeof(dp));
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>map[i][j];
            }
        }
        cin>>K;
        for(i=0; i<K; i++)
        {
            scanf("%d%d",&u,&v);
            tre[u][v]=i;
            node[i]=u*m+v;
        }
        memset(g,0x7f,sizeof(g));
        for(i=0; i<K; i++)
        {
            g[i][i]=0;
            cos[i]=INF;
            dijstra(node[i],i);
        }
        for(i=0; i<K; i++)
        {

            int x=node[i]/m;
            int y=node[i]%m;
            dp[i][1<<i]=map[x][y]+cos[i];
        }
        for(j=0; j<(1<<K); j++)
        {
            for(i=0; i<K; i++)
            {
                if(j&(1<<i)&&j!=(1<<i))
                {
                    for(k=0; k<K; k++)
                    {
                        if(j&(1<<k)&&i!=k&&j!=(1<<k))
                        {
                            dp[i][j]=min(dp[i][j],dp[k][j-(1<<i)]+g[k][i]);
                        }
                    }
                }
            }
        }
        int ans=INF;
        for(i=0; i<K; i++)
        {
            ans=min(ans,dp[i][(1<<K)-1]+cos[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

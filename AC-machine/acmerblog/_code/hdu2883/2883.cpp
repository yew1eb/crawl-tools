#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 2139062143
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
const int maxn=1000+10;
const int N=1000000+10;
struct Edge
{
    int from,to,cap,flow;
};
struct Query
{
    int S,ni,E,ti;
};
struct Dinic
{
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn];
    int d[maxn],cur[maxn];
    int n,m,s,t;
    void Init(int n)
    {
        for(int i=0;i<=n;++i) G[i].clear();
        edges.clear();
    }
    void AddEdges(int from,int to,int cap)
    {
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS()
    {
        queue<int>q;
        memset(vis,0,sizeof(vis));
        vis[s]=true;
        d[s]=0;
        q.push(s);
        while(!q.empty())
        {
            int x=q.front();q.pop();
            for(int i=0;i<G[x].size();++i)
            {
                Edge e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow)
                {
                    d[e.to]=d[x]+1;
                    vis[e.to]=true;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow=0,f;
        for(int & i=cur[x];i<G[x].size();++i)
        {
            Edge & e=edges[G[x][i]];
            if(d[e.to]==d[x]+1&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                flow+=f;
                edges[G[x][i]].flow+=f;
                edges[G[x][i]^1].flow-=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t)
    {
        this->s=s;this->t=t;
        int flow=0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,inf);
        }
        return flow;
    }
}dinic;
Query query[300];
int convert[N],dd[500],val[maxn];
int getCon(int sz)
{
    sort(dd+1,dd+sz);
    int u=1;
    int i=1,j=1;
    for(i=2;i<sz;++i)
    {
        if(dd[i]==dd[j]) continue;
        dd[++j]=dd[i];
    }
    for(i=1;i<j;++i)
    {
        convert[dd[i]]=u;
        val[u]=dd[i+1]-dd[i];
        u++;
    }
    convert[dd[i]]=u;
    val[u]=0;
    return u;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int sum=0;
        int sz=1;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d%d%d",&query[i].S,&query[i].ni,&query[i].E,&query[i].ti);
            sum+=query[i].ni*query[i].ti;
            dd[sz++]=query[i].S;
            dd[sz++]=query[i].E;
        }
        sz=getCon(sz);
        int N=n+sz+1;
        dinic.Init(N);
        for(int i=1;i<=n;++i)
        {
            dinic.AddEdges(0,i,query[i].ni*query[i].ti);
            int t=convert[query[i].S];
            while(t!=convert[query[i].E])
            {
                dinic.AddEdges(i,n+t,inf);
                t++;
            }
        }
        for(int i=1;i<sz;++i)
            dinic.AddEdges(n+i,N,m*val[i]);
        int res=dinic.Maxflow(0,N);
        if(res==sum)
           printf("Yes\n");
        else
           printf("No\n");
    }
    return 0;
}
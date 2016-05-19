#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<stack>
#include<iostream>
#include<stdlib.h>
using namespace std;

#define INF 500100
typedef long long ll;
const int maxn=300+10;

struct Edge
{
    int from,to,dist;
    Edge(int f,int t,int d):from(f),to(t),dist(d){}
};

struct BF
{
    int n,m;
    vector<Edge>edge;
    vector<int>g[maxn];
    bool inq[maxn];
    int d[maxn];
    int p[maxn];
    int cnt[maxn];
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)g[i].clear();
        edge.clear();
    }

    void addedge(int from,int to,int dist)
    {
        edge.push_back(Edge(from,to,dist));
        m=edge.size();
        g[from].push_back(m-1);
    }
    bool nc(int s)
    {
        queue<int>q;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)d[i]=INF;
        d[s]=0;
        q.push(s);
        inq[s]=true;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            inq[u]=false;
            for(int i=0;i<g[u].size();i++)
            {
                Edge& e=edge[g[u][i]];
                if(d[e.to]>d[u]+e.dist&&d[u]<INF)
                {
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=g[u][i];
                    if(!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to]=true;
                        if(++cnt[e.to]>n)return true;
                    }
                }
            }
        }
        return false;
    }

}bf;

struct pe
{
    int c,v;
    double time;
}P[maxn];


int main()
{
    int n,m,k;
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        bf.init(n);
        for(int i=0;i<k;i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            u--,v--;
            bf.addedge(v,u,w);
        }
        int p;
        scanf("%d",&p);
        p--;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&P[i].c);
            P[i].c--;
        }
        for(int i=0;i<m;i++)
            scanf("%d",&P[i].v);
        double ans_time=1.0*INF;
        int ans_num,ans_dis;
        if(!bf.nc(p))
        {
            for(int i=0;i<m;i++)
            {
                if(bf.d[P[i].c]<INF)
                {
                    P[i].time=bf.d[P[i].c]*1.0/P[i].v;
                    if(ans_time>P[i].time)
                    {
                        ans_time=P[i].time;
                        ans_dis=bf.d[P[i].c];
                        ans_num=i;
                    }
                    else if(ans_time==P[i].time&&ans_dis<bf.d[P[i].c])
                    {
                        ans_dis=bf.d[P[i].c];ans_num=i;
                    }
                    else if(ans_time==P[i].time&&ans_dis==bf.d[P[i].c]&&ans_num<i)
                    {
                        ans_num=i;
                    }
                }
            }
            if(ans_time<1.0*INF)
                printf("%d\n",ans_num+1);
                else puts("No one");
        }
        else puts("No one");
    }

    return 0;
}

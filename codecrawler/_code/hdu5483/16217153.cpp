#define N 3072
#define PII pair<int,int>
#include <bits/stdc++.h>
using namespace std;

vector<int> g[N];
vector<PII> edge,v[N];
int T,n,x,cnt,res,p[N],dfn[N],low[N];

int find(int x)
{
    return p[x]==x?p[x]:p[x]=find(p[x]);
}

void dfs(int u,int fa)
{
    dfn[u]=low[u]=++cnt;
    for(int i=0;i<g[u].size();i++)
    {
        int id=g[u][i];
        if(id!=fa)
        {
            int v=edge[id].first==u?edge[id].second:edge[id].first;
            if(!dfn[v])
            {
                dfs(v,id),low[u]=min(low[u],low[v]);
                if(low[v]>dfn[u]) res++;
            }
            else
                low[u]=min(low[u],dfn[v]);
        }
    }
}

int main()
{
    for(cin>>T;T--;)
    {
        cin>>n;
        for(int i=1;i<N;i++)
            v[i].clear(),p[i]=i;

        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                scanf("%d",&x),v[x].push_back(PII(i,j));

        res=0;
        for(int i=1;i<N;i++)
        {
            edge.clear();
            memset(dfn,0,sizeof(dfn));
            memset(low,0,sizeof(low));

            for(int j=1;j<=n;j++)
                g[j].clear();
            for(int j=0;j<v[i].size();j++)
            {
                int x=find(v[i][j].first),y=find(v[i][j].second);
                if(x!=y)
                    edge.push_back(PII(x,y)),g[x].push_back(edge.size()-1),g[y].push_back(edge.size()-1);
            }

            for(int j=1;j<=n;j++)
                if(!dfn[j]) cnt=0,dfs(j,-1);
            for(int j=0;j<v[i].size();j++)
            {
                int x=find(v[i][j].first),y=find(v[i][j].second);
                if(x!=y) p[x]=y;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

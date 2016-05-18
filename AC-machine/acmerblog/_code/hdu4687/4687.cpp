#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <cstdlib>
#define L(rt) (rt<<1)
#define R(rt) (rt<<1|1)
#define ll long long
using namespace std;

const int MAXN=50;
deque<int> Q;
//g[i][j]存放关系图：i,j是否有边,match[i]存放i所匹配的点
bool g[MAXN][MAXN],inque[MAXN],inblossom[MAXN],vis[150];
int match[MAXN],pre[MAXN],base[MAXN];
int n,m,mmg;
vector<int>res;
struct node
{
    int u,v;
}com[150];
//找公共祖先
int findancestor(int u,int v){
    bool inpath[MAXN]={false};
    while(1){
        u=base[u];
        inpath[u]=true;
        if(match[u]==-1)break;
        u=pre[match[u]];
    }
    while(1){
        v=base[v];
        if(inpath[v])return v;
        v=pre[match[v]];
    }
}

//压缩花
void reset(int u,int anc){
    while(u!=anc){
        int v=match[u];
        inblossom[base[u]]=1;
        inblossom[base[v]]=1;
        v=pre[v];
        if(base[v]!=anc)pre[v]=match[u];
        u=v;
    }
}

void contract(int u,int v,int n){
    int anc=findancestor(u,v);
    memset(inblossom,0,sizeof(inblossom));
    reset(u,anc);reset(v,anc);
    if(base[u]!=anc)pre[u]=v;
    if(base[v]!=anc)pre[v]=u;
    for(int i=1;i<=n;i++)
        if(inblossom[base[i]]){
            base[i]=anc;
            if(!inque[i]){
                Q.push_back(i);
                inque[i]=1;
            }
        }
}

bool dfs(int S,int n){
    for(int i=0;i<=n;i++)pre[i]=-1,inque[i]=0,base[i]=i;
    Q.clear();Q.push_back(S);inque[S]=1;
    while(!Q.empty()){
        int u=Q.front();Q.pop_front();
        for(int v=1;v<=n;v++){
            if(g[u][v]&&base[v]!=base[u]&&match[u]!=v){
                if(v==S||(match[v]!=-1&&pre[match[v]]!=-1))contract(u,v,n);
                else if(pre[v]==-1){
                    pre[v]=u;
                    if(match[v]!=-1)Q.push_back(match[v]),inque[match[v]]=1;
                    else{
                        u=v;
                        while(u!=-1){
                            v=pre[u];
                            int w=match[v];
                            match[u]=v;
                            match[v]=u;
                            u=w;
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int MMG()
{
    int ans=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=n;i++)
        if(match[i]==-1&&dfs(i,n)) ans++;
    return ans;
}
int main()
{
    int a,b;
    while(~scanf("%d%d",&n,&m))
    {
        memset(g,false,sizeof(g));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a][b]=g[b][a]=true;
            com[i].u=a;
            com[i].v=b;
        }
        mmg=MMG();
        res.clear();
        for(int i=1;i<=m;i++)
        {
            a=com[i].u;
            b=com[i].v;
            memset(g,false,sizeof(g));
            for(int j=1;j<=m;j++)
            if(j!=i)
            {
                int x=com[j].u,y=com[j].v;
                if(x==a||x==b||y==a||y==b) continue;
                g[x][y]=g[y][x]=true;
            }
            int t=MMG();
            if(t!=mmg-1) res.push_back(i);
        }
        printf("%d\n",res.size());
        if(res.size())
        printf("%d",res[0]);
        for(int i=1;i<res.size();i++)
        printf(" %d",res[i]);
        printf("\n");
    }
    return 0;
}

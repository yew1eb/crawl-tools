#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 99999999
using namespace std;
int map[205][205];
struct node
{
    int u,v,f;
};
node e[1000000];
int first[50000],next[1000000],cc;
int d[50000],gap[50000],curedge[50000],pre[50000];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
inline void add_edge(int u,int v,int f)
{
    e[cc].u=u;
    e[cc].v=v;
    e[cc].f=f;
    next[cc]=first[u];
    first[u]=cc;
    cc++;

    e[cc].u=v;
    e[cc].v=u;
    e[cc].f=0;
    next[cc]=first[v];
    first[v]=cc;
    cc++;
};
int sap_max_flow(int s,int t,int n)
{
    int cur_flow=0,flow_ans=0,i,u,neck,tmp;
    memset(d,0,sizeof(d));
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    for(i=0;i<=n;i++)
        curedge[i]=first[i];
    gap[0]=n+1;
    u=s;
    while(d[s]<n+1)
    {

        if(u==t)
        {
            cur_flow=inf;
            for(i=s;i!=t;i=e[curedge[i]].v)
            {
                if(cur_flow>e[curedge[i]].f)
                    cur_flow=e[curedge[i]].f,neck=i;
            }
            for(i=s;i!=t;i=e[curedge[i]].v)
            {
                tmp=curedge[i];
                e[tmp].f-=cur_flow;
                e[tmp^1].f+=cur_flow;
            }
            flow_ans+=cur_flow;
            u=neck;
        }
        for(i=curedge[u];i!=-1;i=next[i])
            if(e[i].f&&d[u]==d[e[i].v]+1)
                break;

        if(i!=-1)
        {
            curedge[u]=i;
            pre[e[i].v]=u;
            u=e[i].v;
        }
        else
        {
            if(0==--gap[d[u]])
                break;
            curedge[u]=first[u];
            for(tmp=n+5,i=first[u];i!=-1;i=next[i])
                if(e[i].f)
                    tmp=min(tmp,d[e[i].v]);
            d[u]=tmp+1;
            ++gap[d[u]];
            if(u!=s)
                u=pre[u];
        }
    }
    return flow_ans;

}
int main()
{
    int n,m;
    int tt=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        memset(map,0,sizeof(map));
        memset(e,0,sizeof(e));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&map[i][j]);
        cc=0;
        int s=n*m;
        int t=n*m+1;
        memset(first,-1,sizeof(first));
        memset(next,-1,sizeof(next));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int k;
                for(k=0;k<4;k++)
                {
                    int tx=i+xx[k];
                    int ty=j+yy[k];
                    if(tx<0||tx>=n||ty<0||ty>=m)
                        continue;
                    add_edge(i*m+j,tx*m+ty,1);
                }
                if(map[i][j]==1)
                    add_edge(i*m+j,t,inf);
                if(map[i][j]==2)
                    add_edge(s,i*m+j,inf);
            }
        }
        printf("Case %d:\n",++tt);
        printf("%d\n",sap_max_flow(s,t,t));
    }
    return 0;
}
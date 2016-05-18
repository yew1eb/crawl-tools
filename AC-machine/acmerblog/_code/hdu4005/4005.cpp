#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#define N 20100
#define M 200100
#define inf 100000000
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int head1[N],head2[N],cnt,scc,Min;
int dfn[N],low[N],belong[N];
int dp[N];
stack<int>sta;
struct Edge{
    int v,w,next;
}edge[M*4];

void addedge(int u,int v,int w,int *head){
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].w=w;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
void init(int n){
    memset(head1,-1,sizeof(head1));
    memset(head2,-1,sizeof(head2));
    memset(dfn,0,sizeof(dfn));
    for(int i=1;i<=n;i++)dp[i]=inf;
    cnt=scc=0;
}
void DP(int u,int fa){
    int i;
    for(i=head2[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v!=fa){
            DP(v,u);
            dp[v]=min(dp[v],edge[i].w);
            if(dp[u]>dp[v]){
                Min=min(Min,dp[u]);
                dp[u]=dp[v];
            }
            else
                Min=min(Min,dp[v]);
        }
    }
}
void tarjan(int u,int fa){
    int i,flag=1;
    dfn[u]=low[u]=dfn[fa]+1;
    sta.push(u);
    for(i=head1[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==fa && flag){
            flag=0;
            continue;
        }
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        scc++;
        while(1){
            int tem=sta.top();
            sta.pop();
            belong[tem]=scc;
            if(tem==u)break;
        }
    }
}
int main(){
    int i,n,m;
    int u,v,w;
    while(scanf("%d %d",&n,&m)==2){
        init(n);
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&u,&v,&w);
            addedge(u,v,w,head1);
        }
        for(i=1;i<=n;i++)
            if(dfn[i]==0)
                tarjan(1,0);
        if(scc==1){
            printf("-1\n");
            continue;
        }
        int last=cnt,whi;
        Min=inf;
        for(i=0;i<last;i+=2){
            if(belong[edge[i].v]!=belong[edge[i^1].v]){
                addedge(belong[edge[i].v],belong[edge[i^1].v],edge[i].w,head2);
                if(edge[i].w<Min){
                    whi=i;
                    Min=edge[i].w;
                }
            }
        }
        Min=inf;
        DP(belong[edge[whi].v],belong[edge[whi^1].v]);
        DP(belong[edge[whi^1].v],belong[edge[whi].v]);
        if(Min==inf)printf("-1\n");
        else printf("%d\n",Min);
    }
    return 0;
}

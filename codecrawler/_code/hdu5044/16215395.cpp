//å»å¹´å­¦é¿åçæ¶åè¿è½è¿ï¼è®°å¾æ¯G++è·è¿çï¼ç°å¨åå°±è¦c++ç¶åæå¨å¼æ æè·äº3000+msï¼ä¸ç¥éæ¯ä¸æ¯æ°å äºæ°æ®ã
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<cmath>
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 1<<29
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
#define EPS 1e-8
#define MID int mid=(l+r)>>1; int ls=o<<1; int rs=o<<1|1;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N=100005;
int father[N];
bool vis[N];
int op[N];
int a[N],b[N],lca[N];
long long v[N];
long long dis[N];
long long dis2[N];
int faa[N];
int out[N];
struct Edge{
    int v,next,id;
}e[N*4];
int head[N],ask[N];
int cnt;
void add1(int u,int v,int id)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    e[cnt].id=id;
    head[u]=cnt++;
}
void add2(int u,int v,int id)
{
    e[cnt].v=v;
    e[cnt].next=ask[u];
    e[cnt].id=id;
    ask[u]=cnt++;
}
int Find(int x)
{
    if(father[x]==x)return x;
    return father[x]=Find(father[x]);
}
void LCA(int now,int fa)
{
    faa[now]=fa;
    father[now]=now;
    vis[now]=true;
    for(int i=ask[now];i!=-1;i=e[i].next){
        int v=e[i].v;
        int id=e[i].id;
        if(vis[v])
            lca[id]=Find(v);
    }
    for(int i=head[now];i!=-1;i=e[i].next){
        int v=e[i].v;
        int id=e[i].id;
        if(v==fa) continue;
        out[id]=v;
        LCA(v,now);
        father[v]=now;
    }
}
void dfs(int now,int fa)
{
    long long ret=0;
    long long ret2=0;
    for(int i=head[now];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==fa)continue;
        dfs(v,now);
        ret+=dis[v];
        ret2+=dis2[v];
    }
    dis[now]+=ret;
    dis2[now]+=ret2;
}
int main()
{
    int T;
    int n,m;
    int x,y;
    char str[5];
    int Case=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        memset(dis2,0,sizeof(dis2));
        memset(head,-1,sizeof(head));
        memset(ask,-1,sizeof(ask));
        cnt=0;
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&x,&y);
            add1(x,y,i);
            add1(y,x,i);
        }
        for(int i=0;i<m;i++){
            scanf("%s%d%d%I64d",str,&x,&y,&v[i]);
            if(str[3]=='1')op[i]=1;
            else op[i]=2;
            a[i]=x;b[i]=y;
            add2(x,y,i);
            add2(y,x,i);
        }
        LCA(1,-1);
        faa[1]=0;
        for(int i=0;i<m;i++){
            if(op[i]==2){
                dis[a[i]]+=v[i];
                dis[b[i]]+=v[i];
                dis[lca[i]]-=v[i]*2;
            }else {
                dis2[a[i]]+=v[i];
                    dis2[b[i]]+=v[i];
                dis2[lca[i]]-=v[i];
                dis2[faa[lca[i]]]-=v[i];
            }
        }
        dfs(1,-1);
        printf("Case #%d:\n",Case++);
         printf("%I64d",dis2[1]);
        for(int i=2;i<=n;i++){
            printf(" %I64d",dis2[i]);
        }printf("\n");
        if(n==1)
            {printf("\n");continue;}
        printf("%I64d",dis[out[0]]);
        for(int i=1;i<n-1;i++){
            printf(" %I64d",dis[out[i]]);
        }printf("\n");
    }
    return 0;
}
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define INF 0x7fffffff
#define M 100005
#define N 10005
#include<queue>
using namespace std;
int head[N],cnt,nv,s,t;
struct edge{
    int to,next,cap,flow;
}e[M];
void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap){
    e[cnt].to=v;e[cnt].cap=cap;e[cnt].next=head[u];head[u]=cnt++;
    e[cnt].to=u;e[cnt].cap=0;e[cnt].next=head[v];head[v]=cnt++;
}
int gap[N],dist[N],pre[N],curedge[N];
int ISAP(){
    int cur_flow,u,tmp,neck,i,max_flow;
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    memset(dist,0,sizeof(dist));
    for(i=1;i<=nv;i++)
    curedge[i]=head[i];
    gap[nv]=nv;
    max_flow=0;
    u=s;
    while(dist[s]<nv){
        if(u==t){
            cur_flow=INF;
            for(i=s;i!=t;i=e[curedge[i]].to){
                if(cur_flow>e[curedge[i]].cap){
                    neck=i;
                    cur_flow=e[curedge[i]].cap;
                }
            }
            for(i=s;i!=t;i=e[curedge[i]].to){
                tmp=curedge[i];
                e[tmp].cap-=cur_flow;
                e[tmp].flow+=cur_flow;
                tmp^=1;
                e[tmp].cap+=cur_flow;
                e[tmp].flow-=cur_flow;
        }
        max_flow+=cur_flow;
        u=neck;
    }
    for(i=curedge[u];i!=-1;i=e[i].next)
    if(e[i].cap>0&&dist[u]==dist[e[i].to]+1)
    break;
    if(i!=-1){
        curedge[u]=i;
        pre[e[i].to]=u;
        u=e[i].to;
    }else {
        if(0==--gap[dist[u]])
        break;
        curedge[u]=head[u];
        for(tmp=nv,i=head[u];i!=-1;i=e[i].next)
        if(e[i].cap>0)
        tmp=tmp<dist[e[i].to]?tmp:dist[e[i].to];
        dist[u]=tmp+1;
        ++gap[dist[u]];
        if(u!=s)
        u=pre[u];
    }
    }
    return max_flow;
}
int main()
{
    int T,mp[50][50],ics=0,n,m;
    char str[50];
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&n,&m);
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=n;i++){
            scanf("%s",str);
            for(int j=1;j<=m;j++){
               if(str[j-1]=='.'){
                    mp[i][j]=1;
               } else if(str[j-1]=='E'){
                    mp[i][j]=2;
               }
            }
        }
        n+=2;
        m+=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+j)&1){
                    if(mp[i][j]<2){
                        mp[i][j]=1-mp[i][j];
                    }
                }
            }
        }
        int id;
        s=n*m,t=n*m+1;
        nv=t+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                id=i*m+j;
                if(mp[i][j]==0){
                    addedge(s,id,INF);
                    if(i+1<n&&mp[i+1][j]!=0)
                    addedge(id,(i+1)*m+j,1);
                    if(j+1<m&&mp[i][j+1]!=0)
                    addedge(id,i*m+j+1,1);
                }else if(mp[i][j]==1){
                    addedge(id,t,INF);
                    if(i+1<n&&mp[i+1][j]!=1)
                    addedge((i+1)*m+j,id,1);
                    if(j+1<m&&mp[i][j+1]!=1)
                    addedge(i*m+j+1,id,1);

                }else {

                    if(i+1<n&&mp[i+1][j]!=0)
                    addedge(id,(i+1)*m+j,1);
                    if(j+1<m&&mp[i][j+1]!=0)
                    addedge(id,i*m+j+1,1);
                    if(i+1<n&&mp[i+1][j]!=1)
                    addedge((i+1)*m+j,id,1);
                    if(j+1<m&&mp[i][j+1]!=1)
                    addedge(i*m+j+1,id,1);

                }
            }
        }
        int ans=n*(m-1)+m*(n-1)-ISAP();
        printf("Case %d: %d\n",++ics,ans);
    }
    return 0;
}
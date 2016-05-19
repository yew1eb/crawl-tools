#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 100010

int head[N],to[2*N],nextedge[2*N],id[2*N];
int head2[N],to2[2*N],nextedge2[2*N];
int w[N];
int edge[N][2];
int ans[N][2];
int cou;
int dp[N][2];
int timemark[N];
int minfro[N];
int fa[N];
int dp2[N];
int bl[N];
int time;
int num;
int maxnum;

void add(int a,int b,int tempid){
    to[cou]=b;nextedge[cou]=head[a];id[cou]=tempid;head[a]=cou++;
}

void add2(int a,int b){
    to2[cou]=b;nextedge2[cou]=head2[a];head2[a]=cou++;
}

void dfs(int u,int tempfa,int faedge){
    timemark[u]=++time;
    minfro[u]=time;
    dp[u][0]=0;
    dp[u][1]=0;
    fa[u]=tempfa;

    for(int i=head[u];i!=-1;i=nextedge[i]){
        int v=to[i];

        if(v==tempfa){
            continue;
        }
        else if(dp[v][0]!=-1){
            minfro[u]=minfro[u]>timemark[v]?timemark[v]:minfro[u];
            ans[id[i]][0]=0;
            ans[id[i]][1]=0;
        }
        else{
            dfs(v,u,id[i]);
            int tempdpv=v>dp[v][0]?v:dp[v][0];

            if(tempdpv>dp[u][0]){
                dp[u][1]=dp[u][0];
                dp[u][0]=tempdpv;
            }
            else if(tempdpv>dp[u][1]){
                dp[u][1]=tempdpv;
            }

            minfro[u]=minfro[u]>minfro[v]?minfro[v]:minfro[u];
        }
    }

    if(minfro[u]<timemark[u]){
        ans[faedge][0]=0;
        ans[faedge][1]=0;
    }

    return;
}

void dfs2(int u,int fa){
    bl[u]=num;
    maxnum=maxnum>u?maxnum:u;

    for(int i=head[u];i!=-1;i=nextedge[i]){
        int v=to[i];

        if(v==fa){
            continue;
        }
        else if(ans[id[i]][0]){
            continue;
        }
        else if(bl[v]==-1){
            dfs2(v,u);
        }
    }

    return;
}

void dfs3(int u,int fa){
    //printf("wo shi da hao ren");
    dp2[u]=w[u];
    //printf("%d %d\n",u,w[u]);

    for(int i=head2[u];i!=-1;i=nextedge2[i]){
        int v=to2[i];

        if(v==fa){
            continue;
        }
        else{
            dfs3(v,u);
            dp2[u]=(dp2[u]>dp2[v]?dp2[u]:dp2[v]);
        }
    }

    return;
}

int main(){
    int t;
    int n,m;
    int a,b;

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(head,-1,sizeof(head));
        memset(ans,-1,sizeof(ans));
        memset(dp,-1,sizeof(dp));
        cou=0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            add(a,b,i);
            add(b,a,i);
            edge[i][0]=a;
            edge[i][1]=b;
        }

        time=0;
        dfs(1,-1,-1);
        num=0;
        memset(bl,-1,sizeof(bl));
        for(int i=1;i<=n;i++){
            if(bl[i]==-1){
                num++;
                maxnum=i;
                dfs2(i,-1);
                w[num]=maxnum;
            }
        }

        cou=0;
        memset(head2,-1,sizeof(head2));
        for(int i=0;i<m;i++){
            if(ans[i][0]){
                int u=bl[edge[i][0]];
                int v=bl[edge[i][1]];

                add2(u,v);
                add2(v,u);
            }
        }

        for(int i=1;i<=num;i++){
            if(w[i]==n){
                dfs3(i,-1);
                break;
            }
        }

        /*for(int i=1;i<=num;i++){
            printf("%d %d %d\n",i,w[i],dp2[i]);
        }*/

        for(int i=0;i<m;i++){
            if(ans[i][0]){
                int u=bl[edge[i][0]];
                int v=bl[edge[i][1]];
                int temp=dp2[u]>dp2[v]?dp2[v]:dp2[u];
                ans[i][0]=temp;
                ans[i][1]=temp+1;
            }
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }

    return 0;
}

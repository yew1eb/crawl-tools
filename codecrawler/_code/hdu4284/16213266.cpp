#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#define inf 1<<28
#define N 105
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,money,h;
int path[N][N];
int dp[20][1<<16];
int work[20],c[20],d[20];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&money);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                path[i][j]=inf;
            path[i][i]=0;
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            path[u][v]=Min(path[u][v],w);
            path[v][u]=path[u][v];
        }
        //Floydé¢å¤ç
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(i!=k&&i!=j&&j!=k)
                        path[i][j]=Min(path[i][k]+path[k][j],path[i][j]);
        scanf("%d",&h);
        int pos=-1;
        for(int i=0;i<h;i++){
            scanf("%d%d%d",&work[i],&c[i],&d[i]);
            work[i]--;
            if(work[i]==0) pos=i;   //è¯´æå¿éç¹ä¸­åå«äºèµ·ç¹1
        }
        //å¦æä¸åå«ï¼æä»¬å å¥åä½ç¹ï¼ä¾¿äºåé¢å¤çï¼cådé½ä¸º0
        if(pos==-1){
            work[h]=0;c[h]=0;d[h]=0;
            pos=h++;
        }
        memset(dp,-1,sizeof(dp));
        if(money-d[pos]>=0) dp[pos][1<<pos]=money-d[pos]+c[pos];dp[pos][0]=money;
        for(int i=0;i<(1<<h);i++){
            for(int j=0;j<h;j++){
                if(dp[j][i]==-1) continue;
                for(int k=0;k<h;k++){
                    if(k==j||((1<<k)&i)) continue;
                    //é±å¤å¨ä¸¤ä¸ªåå¸ä¹é´ç§»å¨ï¼èä¸å¤ä¹°è¯
                    if(dp[j][i]>=path[work[j]][work[k]]+d[k])
                        dp[k][i|(1<<k)]=Max(dp[k][i|(1<<k)],dp[j][i]-path[work[j]][work[k]]-d[k]+c[k]);
                }
            }
        }
        bool ans=false;
        for(int i=0;i<h;i++)
            //æåå¤æ­è½ä¸è½è¿åèµ·ç¹
            if(dp[i][(1<<h)-1]>=path[work[i]][0]){
                ans=true;
                break;
            }
        puts(ans?"YES":"NO");
    }
    return 0;
}
            
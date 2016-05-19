#include <iostream>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int dis[105][105],vis[105];
int n,m,t,ans;
void dfs(int num,int sum,int st){               //æç´¢åå«ä»£è¡¨æç´¢å°ç¬¬å ä¸ªï¼è·ç¦»åï¼åèµ·å§ç¹
    int i;
    if(num==t){
        ans=min(ans,sum);
        return;
    }
    for(i=1;i<=n;i++)
    if(vis[i]){
        vis[i]=0;
        dfs(num+1,sum+dis[st][i],i);
        vis[i]=1;
    }
}
int main(){
    int i,j,k;
    while(scanf("%d",&n)!=EOF&&n){              //è¿ä¸ªé¢çè·¯å¾åªè½ç»è¿ç»åºçå ä¸ªç¹ï¼ä¸è½å«æå«çç¹
        ans=INT_MAX;t=0;                        //å æ­¤ä¸è½æ±æç­è·¯ï¼æä»¥éç¨æ´æï¼ä¹å¯ä»¥ç¨STLéå¨æ
        memset(vis,0,sizeof(vis));              //åç´æ¥æ´åæ±è§£
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&dis[i][j]);
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d",&k);
            if(!vis[k+1]){
            t++;
            vis[k+1]=1;
            }
        }
        dfs(0,0,1);
        printf("%d\n",ans);
    }
    return 0;
}

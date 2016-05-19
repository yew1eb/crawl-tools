#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e5+10;
long long inf=1e15;
const int MOD=1e9+7;
int T,n,m,k,x,y,z,l,tot,t;
int cas=1;
int son[N];
bool ok;
vector<int> G[N];
long long A[N];
long long dp[N];/*dp[i] è¡¨ç¤ºä»¥iä¸ºæ ¹ï¼ä¸æ ¹å¨å­æ ä¸­æå¨æå·¦è¾¹çåéæ°ç®*/
void dfs(int x,int fa){
    son[x]=1;
    int num=0;/*ææå¿å­æ°*/
    int cnt=0;/*æèªå·±çå¿å­çå¿å­æ°*/
    long long res=1;
    for(int i=0;i<G[x].size();i++){
            int u=G[x][i];
            if(u==fa) continue;
            num++;
            dfs(u,x);
            son[x]+=son[u];
            if(son[u]>1){
                cnt++;
                res=(res*dp[u])%MOD;
            }
    }
    if(cnt>2){
        ok=true;
        return;
    }else if(cnt==2 || cnt==1){/*ä¸¤ä¸ªå¤§å¿å­ä¸­é´å¤¹çä¸æå¶å­å¿å­  æè ä¸ä¸ªå¤§å¿å­æè¾¹ä¸æå¶å­å¿å­ï¼å¤§å¿å­å¯ä»¥å·¦å³æ¢ä¸ä¸ï¼æä»¥*2 */
        res=(res*2*A[num-cnt])%MOD;
    }else if(cnt==0){/*å¿å­å¨æ¯å¶å­èç¹*/
       res=(res*A[num-cnt])%MOD;
    }
    dp[x]=res;
}
int main()
{
#ifndef  ONLINE_JUDGE
 freopen("aaa","r",stdin);
#endif
    int T;
    A[0]=1;
    for(int i=1;i<N;i++) A[i]=(A[i-1]*i)%MOD;
    scanf("%d",&T);
   while(T--){
     scanf("%d",&n);
     for(int i=1;i<=n;i++) G[i].clear();
     for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
     }
     ok=false;
     dfs(1,-1);
     long long ans=(dp[1]*2)%MOD;/*æ ¹åå°æå°å¼åæå¤§å¼ä¸¤ç§æåµ*/
     if(ok) ans=0;/*ä¸å¯è½çæåµ*/
     if(n==1) ans=1;/*n=1çæåµå¦å¤èè*/
     printf("Case #%d: %I64d\n",cas++,ans);

   }

    return 0;
}

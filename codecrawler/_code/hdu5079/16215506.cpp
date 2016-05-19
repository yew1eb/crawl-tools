#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#define MAXN 12
#define MAXM 120000
#define MOD 1000000007

using namespace std;

int n,m,k; //n*nå¤§å°çæ£çï¼m=2^(å¯ä»¥å¡«é¢è²çæ ¼å­ä¸ªæ°),k=æå¤§ç½è²æ­£æ¹å½¢è¾¹é¿ä¸è¶è¿szçæåµä¸
char s[MAXN];
int a[MAXN]; //a[i]=ç¬¬iè¡ä¸è½å¡«é¢è²çæ ¼å­ç¶æ
int ans[MAXN]; //ans[sz]=ç½è²æ­£æ¹å½¢è¾¹é¿æå°ä¸ºszçæ¹æ¡æ°
int powsz[MAXN];
int dp[MAXN][MAXM]; //dp[i][j]=å¨ç¬¬iè¡ï¼ç¶æä¸ºjçæ¹æ¡æ°
int flag[MAXN]; //flag[i]=1è¡¨ç¤ºå½åè¡ä¸­

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        m=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            //cout<<"m: "<<m<<endl;
            scanf("%s",s);
            for(int j=0;j<n;j++)
            {
                if(s[j]=='o')
                    m=m*2%MOD;
                else
                    a[i]|=1<<j;
            }
        }
        //cout<<"ddm: "<<m<<endl;
        ans[0]=1; //æå°ç½è²æ­£æ¹å½¢è¾¹é¿ä¸º0ï¼å³å¨é»æ£ççæ¹æ¡æ°ä¸º1
        ans[1]=(m-1+MOD)%MOD; //æå°ç½è²æ­£æ¹å½¢è¾¹é¿ä¸º1çæ¹æ¡æ°ä¸º2^(å¯ä»¥å¡«é¢è²çæ ¼å­ä¸ªæ°)-1(ç¸å½äºä¸ä¸ªéåçææå­éä¸ªæ°)
        for(int sz=2;sz<=n;sz++) //æ±æå°æ­£æ¹å½¢ä¸ºszçæ¹æ¡æ°
        {
            powsz[0]=1; //powsz[i]=sz^i
            k=n+1-sz;
            for(int i=1;i<=k;i++)
                powsz[i]=powsz[i-1]*sz;
            dp[0][0]=1;
            for(int st=1;st<powsz[k];st++) //æ¸é¶
                dp[0][st]=0;
            for(int i=1;i<=n;i++) //DPå°ç¬¬iè¡
            {
                for(int st=0;st<powsz[k];st++) //!!!!!æ¸é¶
                    dp[i][st]=0;
                for(int cur=0;cur<(1<<n);cur++) //æ´åæä¸¾æéåcurä¸­çæ ¼å­é½ææé»è²
                {
                    if(cur&a[i]) continue; //æä¸è½æè²çæ ¼å­å¨éåcurä¸­ï¼ä¸åæ³
                    for(int j=0;j<k;j++)
                        flag[j]=0;
                    for(int bit=0;bit<n;bit++) //æä¸¾è¯¥è¡çç¬¬bitåçæ ¼å­
                    {
                        if(cur&(1<<bit)) continue; //è¿ä¸ªæ ¼å­æ¯ä¸è½è¢«æè²ç
                        for(int j=0;j<k;j++)
                            if(bit>=j&&bit<j+sz)
                                flag[j]=1;
                    }
                    for(int st=0;st<powsz[k];st++) //æä¸¾ç¬¬iè¡çç¶æst
                    {
                        if(!dp[i-1][st]) continue; //ä¸åæ³çç¶æ
                        int newst=0; //newst=ç±ç¬¬i-1è¡æ¨åºçç¬¬iè¡çç¶æ
                        for(int j=0;j<k;j++)
                        {
                            int t=st/powsz[j]%sz; //tæ¯szè¿å¶æ°stä¸­çç¬¬jä½æ°å­
                            if(flag[j]) t=0;
                            else if(t!=sz-1) t++;
                            else
                            {
                                newst=-1;
                                break;
                            }
                            newst+=t*powsz[j];
                        }
                        if(newst==-1) continue; //ç±f[i-1][st]æ¨åºçf[i][st]ä¸ºéæ³ç¶æ
                        dp[i][newst]=(dp[i][newst]+dp[i-1][st])%MOD;
                    }
                }
            }
            ans[sz]=0;
            for(int st=0;st<powsz[k];st++)
                ans[sz]=(ans[sz]+dp[n][st])%MOD;
            ans[sz]=(m-ans[sz]+MOD)%MOD; //æ±ans[sz]çè¡¥éåï¼æ­¤æ¶ans[sz]=æå°ç½è²æ­£æ¹å½¢è¾¹é¿å¤§äºç­äºszçæ¹æ¡æ°
            ans[sz-1]=(ans[sz-1]-ans[sz]+MOD)%MOD;
        }
        for(int sz=0;sz<=n;sz++)
            printf("%d\n",ans[sz]);
    }
    return 0;
}

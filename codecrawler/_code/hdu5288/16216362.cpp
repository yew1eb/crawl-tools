#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9+7;
#define ll long long
#define N 111111

int l[N],r[N];//å­å¨å·¦è¾¹å å­ãå³è¾¹å å­çä½ç½®
int n,m;
int pre[N],last[N];
int a[N];
vector<int>g[N];

int main() {
    while(scanf("%d",&n)==1) {
        for (int i=101;i<=10000;i++)
        g[i].clear();
        for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            if(a[i]>100)
            g[a[i]].push_back(i);
            l[i]=0;
            r[i]=n+1;//åå§åæå·¦è¾¹çå å­åæå³è¾¹çå å­é½æ¯æ¬èº«
        }
        memset(pre,0,sizeof(pre));
        memset(last,0,sizeof(last));

        int  tmp;
        for (int j=1; j<=100; j++) {
            tmp=0;
            for (int i=1; i<=n; i++) {
                if (a[i]%j==0) l[i]=max(l[i],tmp);
                if (a[i]==j)
                    tmp=i;
            }

            tmp=n+1;
            for (int i=n; i>=1; i--) {
                if (a[i]%j==0) r[i]=min(r[i],tmp);
                if (a[i]==j)
                    tmp=i;
            }
        }

        for (int i=101; i<=10000; i++)
            pre[i]=0;//ræ°ç»ä»å°å°å¤§å¯»æ¾ä½ç½®
        for (int i=1; i<=n; i++)
            if (a[i]>100) {
                for (int j=a[i]; j<=10000; j=j+a[i])
                    while ((pre[j]<g[j].size())&&(g[j][pre[j]]<i)) //å½ä¸æ å°äºiçæ¶åï¼è¿ä¸ªä¸æ æå­å¨æ°çå³å å­æå¯è½æ¯i
                    {
                        r[g[j][pre[j]]]=min(r[g[j][pre[j]]],i);
                        if ((pre[j]<g[j].size()-1)&&(g[j][pre[j]+1]<i))//å¦ææåæ¾å°äºï¼é£ä¹ç»§ç»­åä¸æ¾è¿å»
                            pre[j]++;
                        else
                            break;
                    }
            }

        for (int i=101; i<=10000; i++)
            last[i]=g[i].size()-1;//læ°ç»ä»å¤§å°å°å¯»æ¾ä½ç½®

        for (int i=n; i>=1; i--)
            if (a[i]>100) {
                for (int j=a[i]; j<=10000; j=j+a[i])
                    while ((last[j]>=0)&&(g[j][last[j]]>i)) {
                        l[g[j][last[j]]]=max(l[g[j][last[j]]],i);
                        if ((last[j]>0)&&(g[j][last[j]-1]>i))
                            last[j]--;
                        else
                            break;
                    }
            }
        /*
        for(int i=1;i<=n;i++){
            printf("%d %d %d\n",i,l[i],r[i]);
        }
         */
        ll ans = 0;
        for(int i=1; i<=n; i++) {
            ans = (ans%mod+(ll)(i-l[i])*(r[i]-i)%mod)%mod;
        }
        printf("%I64d\n",ans);
    }

}

//æ¯å¦çº³æ 
//hdu 4085
/*å¤æåº¦ï¼O(n^2*2^k+n*3^k)
æä¸¾å­æ çå½¢æï¼f[ i ][ j ]=min{ f[ i ][ j ]ï¼f[ k ][ j ]+f[ l ][ j ] }ï¼å¶ä¸­kålæ¯å¯¹içä¸ä¸ªååãk^l==iå­éæä¸¾
æç§è¾¹è¿è¡æ¾å¼ï¼f[ i ][ j ]=min{ f[ i ][ j ]ï¼f[ i ][ j' ]+w[ j ][ j' ] }ï¼å¶ä¸­jåj'ä¹é´æè¾¹ç¸è¿ã
f[i][j]è¡¨ç¤ºåå«éåiå¯¹åºçç¹ï¼å¹¶åå«jç¹çæå°çææ 
dp[i]=min{dp[k]+dp[k^i]} è¡¨ç¤ºåå«éåiå¹¶æ»¡è¶³çæå°æ£®æ
*/
#include<iostream>
#include<stdio.h>
#include<set>
#include<string.h>
#include<math.h>
#include<string>
#include<queue>
#include<algorithm>
#define N 55
using namespace std;
const int inf=(int)1e8;
int f[1<<11][N],dp[1<<11],n,m,h,g[N][N],vis[N];
bool ok(int state)
{
    int num=0;
    for(int i=0;i<h;i++) if((state>>i)&1) num++;
    for(int i=0;i<h;i++) if((state>>i+h)&1) num--;
//    cout<<state<<" num="<<num<<endl;
    return num==0;
}
void calc()//è®¡ç®æ¯å¦çº³æ 
{
    memset(vis,0,sizeof vis);
    for(int i=1;i<(1<<h+h);i++)
    {
        for(int j=1;j<=n;j++)
            for(int k=(i-1)&i;k;k=(k-1)&i)
                f[i][j]=min(f[k][j]+f[i^k][j],f[i][j]);

        for(int k=1;k<=n;k++)
        {
            int best=-1;
            for(int j=1;j<=n;j++) if(vis[j]!=i&&(best==-1||f[i][best]>f[i][j])) best=j;
            if(k==1) dp[i]=f[i][best];
            vis[best]=i;
//            cout<<best<<endl;
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][best]+g[best][j]);
        }
//        cout<<"i="<<i<<" h="<<h<<endl;
//        for(int j=1;j<=n;j++) cout<<f[i][j]<<' '; puts("");
        if(ok(i))
            for(int k=i&(i-1);k;k=(k-1)&i) dp[i]=min(dp[k]+dp[k^i],dp[i]);
        else
            dp[i]=inf;
//        cout<<"h="<<h<<endl;
    }
    h=(1<<h*2)-1;
    if(dp[h]>=inf) puts("No solution");
    else printf("%d\n",dp[h]);
}
void solve()
{
    scanf("%d%d%d",&n,&m,&h);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) g[i][j]=(i==j?0:inf);
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<g[u][v]) g[u][v]=g[v][u]=w;
    }
    for(int i=0;i<(1<<h*2);i++)
        for(int j=0;j<=n;j++) f[i][j]=inf;
    for(int i=0;i<h;i++) f[1<<i][i+1]=0;
    for(int i=0;i<h;i++) f[1<<i+h][n-i]=0;
    calc();
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}


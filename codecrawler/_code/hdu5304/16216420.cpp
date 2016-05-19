#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = (1<<16)+10;
ll ans;
int f[N],dp[20][N];
bool d[20][20];
int n,m;

ll exgcd(ll a,ll b,ll &x,ll &y)//ä¹æ³éåè¿åçdæ¯a,bçå¬çº¦æ°ï¼xæ¯a mod bçéå
{
    if(b==0)
    {
        x=1ll;y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

ll Gauss(int C[][20],int n)//è®¡ç®né¶è¡åå¼çç»å¯¹å¼ % mod
{
    ll ans=1ll;
    int flag=1;//è¡åäº¤æ¢çæ¬¡æ°
    int i,j,k;
    for(i=0;i<n;i++)
    {
        if(C[i][i]==0)
        {
            for(j=i+1;j<n;j++)
                if(C[j][i])break;
            if(j==n)return 0;//æåçå¼å¨æ¯0çans=0ï¼
            flag=!flag;
            for(int k=i;k<n;k++)
                swap(C[i][k],C[j][k]);//iåjè¡äº¤æ¢
        }
      ans=ans*C[i][i]%mod;//å¯¹è§çº¿ç¸ä¹
      ll x,y;
      int tp=exgcd(C[i][i],mod,x,y);//xä¸ºéå


      for(k=i+1;k<n;k++)
        C[i][k]=C[i][k]*x%mod;


      for(int j=i+1;j<n;j++)
      for(int k=i+1;k<n;k++)
      {
          C[j][k]=(C[j][k]-(ll)C[j][i]*C[i][k])%mod;
          if(j==k)
          C[j][k]=(C[j][k]+mod)%mod;
      }
      for(k=i+1;k<n;k++)
        C[i][k]=(ll)C[i][k]*C[i][i]%mod;

    }


    ans=(ans%mod+mod)%mod;
    if(flag) return ans;
    else  return mod-ans;
}

ll solve(int s){
    int Kir[20][20];
    int vis[20],col[20];
    memset(Kir,0,sizeof(Kir));
    memset(vis,0,sizeof(vis));
    memset(col,-1,sizeof(col));
    for(int i=0;i<n;i++)
        if((1<<i)&s) vis[i]=1;
    int num=0;
    for(int i=0;i<n;i++)if(!vis[i])
        col[i]=num++;
    for(int i=0;i<n;i++)if(vis[i])
        col[i]=num;
    num++;

    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)if(i!=j && col[i]!=col[j])
        Kir[col[i]][col[j]] -= d[i][j];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)if(col[i]!=col[j])
        Kir[col[i]][col[i]] += d[i][j];

    return Gauss(Kir,num-1);
}

int main(){
//    freopen("e.in","r",stdin);
//    freopen("my05.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF){
        ans = 0;
        memset(d,0,sizeof(d));
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            d[u][v] = d[v][u] = 1;
        }

        memset(f,0,sizeof(f));
        for(int st=0;st<n;st++){
            memset(dp,0,sizeof(dp));
            dp[st][(1<<st)] = 1;
            for(int s=1;s<(1<<n);s++)if((1<<st)&s){
                for(int i=0;i<n;i++)if(i>=st)
                if(dp[i][s]){
                    for(int j=st+1;j<n;j++)
                    if( (s&(1<<j))==0 && d[i][j] )
                        dp[j][s|(1<<j)] = ( dp[i][s] + dp[j][s|(1<<j)])%mod;
                    if(d[i][st])
                        f[s] = ( dp[i][s] + f[s] )%mod;
                }
            }
        }

        ll inv2 = (mod+1)/2;
        for(int i=1;i<(1<<n);i++){
            if(f[i]){
                int co = 0;
                for(int j=0;j<n;j++)if((1<<j)&i) co++;
                if(co<=2) continue;
                f[i] = ((ll)f[i]*inv2)%mod;
                ans = (ans + (ll)f[i]*solve(i)%mod )%mod;
            }
        }

        printf("%I64d\n",ans);

    }

    return 0;
}

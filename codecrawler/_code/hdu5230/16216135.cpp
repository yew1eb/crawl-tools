#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#define scnaf scanf
#define cahr char
#define bug puts("bugbugbug");
using namespace std;
typedef  long long ll;
const int maxn=100005;
ll mod=998244353;
ll dp[2][maxn], ans[maxn];
void init()
{
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    int N=100000;
    dp[1][1]=1;
    for(int i=1;i<=450;i++)
    {
        int now=i%2;
        int next=!now;
        for(int j=0;j<=N;j++) dp[next][j]=0;
        for(int j=1;j<=N;j++)
        {
            ans[j] = (ans[j]+dp[now][j])%mod;
            if(j+i<=N)
            dp[now][j+i] =(dp[now][j+i]+dp[now][j])%mod;
            if(i+j+1<=N)
            dp[next][j+i+1] =(dp[next][j+i+1]+dp[now][j])%mod;
        }
    }
    for(int i=1;i<=N;i++)
        ans[i]=(ans[i]+ans[i-1])%mod;
}
int main()
{
    init();
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
      int n,C,l,r;
      scanf("%d%d%d%d",&n,&C,&l,&r);
      l-=C; r-=C;
      if(l==0)
         cout<<(ans[r]+1)%mod;
      else
        cout<<(ans[r]-ans[l-1]+mod)%mod;
        puts("");
    }

}
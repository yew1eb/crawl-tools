#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=500000+10;
typedef long long ll;
ll dp[maxn],num[maxn];
ll max(ll a,ll b)
{
 return a>b?a:b;
}
int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
 int N,T,PD,PN,t,tcase=0;
 scanf("%d",&t);
 while(t--)
 {
 tcase++;
 scanf("%d%d%d%d",&N,&T,&PD,&PN);
 memset(dp,0,sizeof(dp));
 int a,b,m=0,u=0;
 ll ans=0;
 for(int i=0;i<N;++i)
 {
 scanf("%d%d",&a,&b);
 ll k;
 if(a>2*T) k=(a-2*T)/T;
 else k=0;
 ans+=k*PD;
 for(int j=0;j<a-k*T;++j)
 num[++m]=PD;
 if(b>2*T) k=(b-2*T)/T;
 else k=0;
 ans+=k*PN;
 for(int j=0;j<b-k*T;++j)
 num[++m]=PN;
 }
 // for(int i=1;i<=u;++i)
 //{
 for(int j=1;j<=m;++j)
 {
 if(j<=T)
 {
 dp[j]=max(num[j],dp[j-1]);
 continue;
 }
 dp[j]=max(dp[j-1],dp[j-T]+num[j]);
 }
 //}
 printf("Case %d: %I64d\n",tcase,ans+dp[m]);
 }
 return 0;
}
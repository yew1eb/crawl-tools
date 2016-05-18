#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 305
#define inf 0x0f0f0f0f
#define MOD 1000000003LL

using namespace std;
long long F[55][55],Num[55];
int main()
{
 int n,k,i,j,t,tot;
 long long ans,now;
 while (scanf("%d%d",&n,&k),n)
 {
 for (i=1;i<=n;i++)
 scanf("%I64d",&Num[i]);
 for (ans=0,t=30;t>=0;t--)
 {
 memset(F,0,sizeof(F));
 for (tot=0,now=1<<t,F[0][0]=i=1;i<=n;i++)
 {
 if (now&Num[i]) {
 for (tot++,j=0;j<tot;j++)
 F[i][j]=(F[i-1][j]*(Num[i]-now+1))%MOD;
 F[i][1]=(F[i][1]+F[i-1][0])%MOD;
 for (j=2;j<=tot;j++)
 F[i][j]=(F[i-1][j-1]*(now)+F[i][j])%MOD;
 Num[i]-=now;
 }
 else {
 for (j=0;j<=tot;j++)
 F[i][j]=(F[i-1][j]*(Num[i]+1))%MOD;
 }
 }
 for (j=1;j<=tot;j++)
 if (((tot-j)&1)==((k>>t)&1))
 ans=(ans+F[n][j])%MOD;
 if (((k>>t)&1)!=(tot&1)) break;
 }
 if (t==-1) ans=(ans+1)%MOD;
 printf("%I64d\n",ans);
 }
 return 0;
}
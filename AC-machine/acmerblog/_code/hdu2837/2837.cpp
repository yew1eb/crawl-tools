#include<stdio.h>
#include<math.h>
#include<string.h>
#define LL long long
const int M=100000+10;
int vis[M],pri[M];
LL oula(LL s)
{
 LL ss=s,tmp=sqrt(s+0.5);
 for(int i=0;pri[i]<=tmp;i++)
 if(s%pri[i]==0)
 {
 ss=ss/pri[i]*(pri[i]-1);
 while(s%pri[i]==0)
 s/=pri[i];
 if(s==1)break;
 }
 if(s>1)ss=ss/s*(s-1);
 return ss;
}
LL powmod(LL a,LL p,LL mod)
{
 LL ans=1;
 while(p)
 {
 if(p&1)
 {
 ans=ans*a;
 if(ans>mod)
 ans=ans%mod+mod;
 }
 a=a*a;
 if(a>mod)
 a=a%mod+mod;
 p>>=1;
 }
 return ans;
}
LL solve(LL n,LL m)
{
 if(n<10)return n;
 LL mm=oula(m);
 LL poi=solve(n/10,mm);
 return powmod(n%10,poi,m);
}
int main()
{
 int i,j,k=0,t;
 LL n,m;
 for(i=2;i*i<M;i++)if(!vis[i])
 for(j=i*i;j<M;j+=i)
 vis[j]=1;
 for(i=2;i<M;i++)if(!vis[i])
 pri[k++]=i;
 scanf("%d",&t);
 while(t--)
 {
 scanf("%I64d%I64d",&n,&m);
 printf("%I64d\n",solve(n,m)%m);
 }
 return 0;
}
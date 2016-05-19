#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll unsigned __int64
#define go(x) ret=max(ret,dfs(p-1,d||i>l[p],u||i<r[p],i,sm+i,x))
int c=0,T,l[20],r[20],len,dp[20][10][150][7],ma[20][2][2][10][7];
ll A,B;
int dfs(int p,int d,int u,int ls,int sm,int s)
{
 if(p<0)return (s==6)?sm:0;
 int &ans=dp[p][ls][sm][s];
 if(d&&u&&ans!=-1)return ans;
 int ret=0;
 int i=d?0:l[p],ed=u?9:r[p];
 for(;i<=ed;i++)
 {
 if(s==0)go(i==0?0:1);
 else if(s==1&&i>ls)go(2);
 else if(s==2&&i!=ls)go(i<ls?3:2);
 else if(s==3){if(i<ls)go(3);if(i>0)go(4);}
 else if(s==4&&i>ls)go(5);
 else if(s==5&&i!=ls)go(i<ls?6:5);
 else if(s==6&&i<ls)go(6);
 }
 if(u&&d)ans=ret;
 return ret;
}
void sol(ll x,int *a)
{
 for(int i=0;i<20;i++)a[i]=0;
 int t=0;
 for(;x;x/=10)a[t++]=x%10;
 if(t>len)len=t;
}
int main()
{
 memset(dp,-1,sizeof(dp));
 scanf("%d",&T);
 while(T--)
 {
 scanf("%I64u%I64u",&A,&B);
 len=0;
 sol(A,l);sol(B,r);
 printf("Case %d: %d\n",++c,dfs(len-1,0,0,0,0,0));
 }
}
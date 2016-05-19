#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll __int64
int T;
ll n;
double x[700],y[700],p[1400],pi=acos(-1.0);
int main()
{
 scanf("%d",&T);
 while(T--)
 {
 scanf("%I64d",&n);
 for(int i=0;i<n;i++)scanf("%lf%lf",x+i,y+i);
 ll ans=n*(n-1)*(n-2)*(n-3)/24,C=(n-1)*(n-2)*(n-3)/6;
 for(int i=0;i<n;i++)
 {
 int t=0,top=0;
 for(int j=0;j<n;j++)
 if(j^i)p[t++]=atan2(y[j]-y[i],x[j]-x[i]);
 sort(p,p+t);
 for(int j=0;j<n-1;j++)p[t++]=p[j]+pi*2;
 //for(int j=0;j<t;j++)printf("%f ",p[j]/pi*180.0);puts("");
 ll sum=0;
 for(int j=0;j<n-1;j++)
 {
 while(p[top+1]-p[j]<pi-1e-10/*fuck eps*/)++top;
 int cnt=top-j;
 if(cnt>=2)sum+=cnt*(cnt-1)/2;
 //printf("j=%d,cnt=%d\n",j,cnt);
 }
 //printf("%lld %lld\n",C,sum);
 ans-=C-sum;
 }
 printf("%I64d\n",ans);
 }
}
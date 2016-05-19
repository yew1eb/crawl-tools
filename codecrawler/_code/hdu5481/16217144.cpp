#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 LL;
#define maxn 100005
#define mod 1000000007
struct P{
    int x,y;
}a[maxn<<1];
LL ans,sum[maxn],p[maxn];
bool cmp(P x,P y) {return x.x<y.x;}
int main()
{
    int T,i,n;
    scanf("%d",&T);
    p[0]=1;
    for(i=1;i<maxn;++i) p[i]=p[i-1]*2%mod;
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n+n;i+=2){
            scanf("%d%d",&a[i].x,&a[i+1].x);
            a[i].y=1,a[i+1].y=-1;
        }
        sum[1]=p[n-1];
        for(i=2;i<=n;++i) sum[i]=(sum[i-1]+p[n-i])%mod;
        sort(a+1,a+n+n+1,cmp);
        int ans=0,cnt=0;
        for(i=1;i<n+n;++i){
            cnt+=a[i].y;
            ans=(ans+sum[cnt]*(a[i+1].x-a[i].x)%mod)%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//树状数组 + 简单DP
//同hdu 3450，dp的求和操作由树状数组来求执行
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 500010;
const int mod = 1000000007;
__int64 c[maxn],a[maxn],val[maxn],b[maxn];
int tot;
int lowbit(int x){
    return x&-x;
}
void update(int x,__int64 d){
    for(;x<maxn;x+=lowbit(x)){
        c[x]+=d;
        if(c[x]>=mod) c[x]%=mod;
    }
}
__int64 sum(int x){
    __int64 ans=0;
    for(;x>0;x-=lowbit(x)){
            ans+=c[x];
            if(ans>=mod)
                ans-=mod;
    }
    return ans;
}
int main()
{
    int t,cases=1,n,m,i,j;
    __int64 X,Y,Z;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%I64d%I64d%I64d",&n,&m,&X,&Y,&Z);
        for(i=0;i<m;i++)
            scanf("%I64d",&a[i]);
        for(i=0;i<n;i++){
            b[i+1]=a[i%m];
            val[i+1]=b[i+1];
            a[i%m]=(X*a[i%m]+Y*(i+1))%Z;
        }
        sort(b+1,b+n+1);
        tot=unique(b+1,b+n+1)-b;
        memset(c,0,sizeof(c));
        __int64 ans=0;
        for(i=1;i<=n;i++){
            int id=lower_bound(b+1,b+tot+1,val[i])-b;
            __int64 num=sum(id-1);
            ans+=num+1;
            ans%=mod;
            update(id,num+1);
        }
        printf("Case #%d: %I64d\n",cases++,ans);
    }
    return 0;
}
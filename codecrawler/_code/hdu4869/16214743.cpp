#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

#define LL __int64
const int maxn=1e5+10;
const int mod=1e9+9;
LL c[maxn];
LL pow_mod(LL a,int b)
{
    LL s=1;
    while(b)
    {
        if(b&1)s=s*a%mod;
        a=a*a%mod;
        b=b>>1;
    }
    return s;
}
int main()
{
    int n,m;
    //freopen("C:\\Documents and Settings\\Administrator\\æ¡é¢\\in.txt","r",stdin);
    //freopen("C:\\Documents and Settings\\Administrator\\æ¡é¢\\out.txt","w",stdout);
    //printf("%I64d\n",pow_mod(2,10));
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j,k,x,p,q;
        i=j=0;
        for(k=0;k<n;k++)
        {
            scanf("%d",&x);
            //æ±æå°1çä¸ªæ°i
            if(i>=x)p=i-x;
            else if(j>=x)p=((i&1)==(x&1)?0:1);
            else p=x-j;
            //æ±æå¤§1çä¸ªæ°j
            if(j+x<=m)q=j+x;
            else if(i+x<=m)q=(((i+x)&1)==(m&1)?m:m-1);
            else q=2*m-(i+x);
            i=p;j=q;
            //printf("**%d %d\n",i,j);
        }

        LL ans=0;
        c[0]=1;
        if(i==0)ans+=c[0];
        for(k=1;k<=j;k++)
        {
            if(m-k<k)c[k]=c[m-k];
            else c[k]=c[k-1]*(m-k+1)%mod*pow_mod(k,mod-2)%mod;
            if(k>=i&&(k&1)==(i&1))ans+=c[k];
        }
        printf("%I64d\n",ans%mod);
    }
    return 0;
}

#include <stdio.h>
#define maxn 301000
#define max 9999999999999
#define ll long long               //è¿éè¦æ³¨æææ°æ®èå´æ¹æ¹ï¼å ä¸º50000*50000è²ä¼¼ä¼çint
int b[maxn];
ll sum[maxn];
int n,h,w;
ll min(ll a,ll b)
{
    return a<b?a:b;
}
int main()
{
    while(scanf("%d%d%d",&n,&w,&h)!=EOF)
    {
        int i;
        ll j,k;
        ll ans=max;
        for(i=0;i<w;i++) sum[i]=b[i]=0;
        for(i=w;i<n+w;i++)
        {
            scanf("%d",&b[i]);
            sum[i]=sum[i-1]+b[i];
        }
        for(i=n+w;i<n+w+w;i++) sum[i]=sum[i-1],b[i]=0;
        j=k=0;
        k=(w*h);
        for(i=1;i<n+w;i++)
        {
            int tmp=b[i-1]-h;
            if(tmp>0) j-=tmp;
            else k+=tmp;
            tmp=b[i+w-1]-h;
            if(tmp>0) j+=tmp;
            else k-=tmp;
            ll res=sum[i-1]+sum[n+w+w-1]-sum[i+w-1];
            if(j>=k) ans=min(ans,j);
            else
            {
                if(res>=(k-j)) ans=min(ans,k);
                else continue;
            }
            //printf("%lld  %lld  %lld\n",j,k,res);
        }
        printf("%lld\n",ans==max?-1:ans);
    }
    return 0;
}
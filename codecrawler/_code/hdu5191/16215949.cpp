#include <stdio.h>
int h[200010];
long long n,W,H,ans;
long long mmin(long long a,long long b)
{
    return a>b?b:a;
}
long long mmax(long long a,long long b)
{
    return a>b?a:b;
}
int main()
{
    while(scanf("%lld%lld%lld",&n,&W,&H)!=EOF){
        long long tsum=0;
        int i;
        for(i=W+1;i<=W+n;i++){
            scanf("%d",h+i);
            tsum+=h[i];
        }
        if(tsum<W*H) {printf("-1\n");continue;}

        for(i=1;i<=W;i++)
            h[i]=h[W+n+i]=0;
        long long d=0,s=0;
        ans=0;
        for(i=1;i<=W;i++){
            if(h[i]>H) d+=h[i]-H;
            else s+=H-h[i];
        }
        ans=mmax(d,s);
        n+=W+1;
        for(i=2;i<=n;i++){
            int a=h[i-1],b=h[i+W-1];
            if(a>H) d-=a-H;
            else s-=H-a;
            
            if(b>H) d+=b-H;
            else s+=H-b;

            ans=mmin(ans,mmax(d,s));
            if(!ans) break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
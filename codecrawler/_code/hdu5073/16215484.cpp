#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long s[50050];
//å¯¹æç¨åºï¼è¯·å¿½ç¥
void solve(int n,int k)
{
    double sum=0;
    for(int i=1;i<=k;i++)
    {
        sum+=s[i];
    }
    int l=1,r=k;
    double ans=-1;
    for(int i=k;i<=n;i++)
    {
        double avg=sum/k,t=0;
        for(int j=l;j<=r;j++)
        {
            t+=(s[j]-avg)*(s[j]-avg);
        }
        l++,r++;
        sum=sum-s[l-1]+s[r];
        if(i==k||ans>t) ans=t;
    }
    printf("%.12lf\n",ans);
}

int main()
{

    int cas,n,k;
    scanf("%d",&cas);
    while(cas--)
    {
        long long suml=0,sumr=0,ans=-1,t=0;
        scanf("%d%d",&n,&k);
        k=n-k;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&s[i]);
        }
        if(k==0||k==1)
        {
            printf("0.000000000000\n");
            continue;
        }
        s[n+1]=0;
        sort(s+1,s+n+1);
        for(int i=1;i<=k;i++)
        {
            suml=suml+s[i],sumr=sumr+s[i]*s[i];
        }
        for(int i=k;i<=n;i++)
        {
            t=sumr*k-suml*suml;
            if(i==k||ans>t) ans=t;
            suml=suml-s[i-k+1]+s[i+1];
            sumr=sumr-s[i-k+1]*s[i-k+1]+s[i+1]*s[i+1];
        }
        //solve(n,k);
        printf("%.12lf\n",(double)ans/(double)k);
    }
    return 0;
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ll long long
using namespace std;
ll dp[100010],sum[100010];
int Po[100010];
long long GCD(long long a,long long b)
{
    if(b==0)
    return a;
    return GCD(b,a%b);
}
ll getans(ll x)
{
    if(x>0)
    return x;
    return -x;
}
int main()
{
    //freopen("dd.txt","r",stdin);
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        ll n,a,b;
        cin>>n>>a>>b;
        if(a<b)
        swap(a,b);
        if(a==b)
        printf("0\n");
        else
        {
            ll tmp=GCD(a,b);
            ll tt=tmp;
            tmp=a*b/tmp;
            dp[1]=0;
            sum[1]=0;
            ll po=b+1;
            Po[1]=1;
            Po[2]=b+1;
            for(int i=2;i<=a/tt;i++)
            {
                if(po+b-1<=a)
                {
                    dp[i]=(po-1)*b;
                    po=po+b;
                    if(po>a)
                    po-=a;
                }
                else
                {
                    dp[i]=(po-1)*(a-po+1);
                    int tt=a-po+2;
                    dp[i]+=(tt-1)*(b-tt+1);
                    po=b-tt+2;
                    if(po>a)
                    po-=a;
                }
                Po[i+1]=po;
                sum[i]=sum[i-1]+dp[i];
            }

            ll ans=0;
            ans=sum[a/tt]*(n/tmp);
            n%=tmp;
           // cout<<n<<endl;
            ll x=n/b;
            ans+=sum[x];
            n%=b;
            if(n)
            {
                ll PO=Po[x+1];
                for(int i=1;i<=n;i++)
                {
                    ans+=getans(PO-i);
                    PO++;
                    if(PO>a)
                    PO-=a;
                }
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}
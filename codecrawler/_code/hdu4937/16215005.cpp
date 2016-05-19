#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n;

void solve()
{
    LL ans=0;
    for(LL i=3;i<=6;i++)
        for(LL j=3;j<=6;j++)
            if((n-j)%i==0&&(n-j)/i>max(i,j))ans++;

    for(LL i=3;i<=6;i++)
        for(LL j=3;j<=6;j++)
            for(LL k=3;k<=6;k++)
            {
                LL tmp=(LL)sqrt(j*j+4*i*(n-k)+0.5);
                if(tmp*tmp!=j*j+4*i*(n-k))continue;
                tmp-=j;
                if(tmp>0&&tmp%(2*i)==0)
                {
                    LL x=tmp/(2*i);
                    if(x>max(i,max(j,k)))ans++;
                }
            }

    for(LL i=2;i*i*i<=n;i++)
    {
        LL t=n;
        while(t)
        {
            if(t%i<3||t%i>6) break;
            t/=i;
        }
        if(!t) ans++;
    }
    cout<<ans<<endl;
}

int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        printf("Case #%d: ",cas++);
        if(n==3||n==4||n==5||n==6){printf("-1\n");continue;}
        solve();
    }
    return 0;
}

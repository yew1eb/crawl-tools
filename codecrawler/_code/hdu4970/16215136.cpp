#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define up(i,x,y) for(i=x;i<=y;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define w(x) while(x)
#define ll __int64
ll n,m,k,l,r,d,a[100005],i,ans;

int main()
{
    w((scanf("%I64d",&n),n))
    {
        scanf("%I64d",&k);
        mem(a,0);
        w(k--)
        {
            scanf("%I64d%I64d%I64d",&l,&r,&d);
            a[l]+=d,a[r+1]+=-d;
        }
        up(i,1,n)
        a[i]+=a[i-1];
        up(i,1,n)
        a[i]+=a[i-1];
        scanf("%I64d",&m);
        ans=0;
        w(m--)
        {
            scanf("%I64d%I64d",&l,&d);
            if(a[n]-a[d-1]<l)
                ans++;
        }
        printf("%I64d\n",ans);
    }

    return 0;
}

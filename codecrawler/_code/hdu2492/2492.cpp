#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
typedef __int64 ll;
const int maxn=200010;
int tr[maxn];
int n,m,p,q,k,mxn;
struct BIT
{
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int c=1)
    {
        for (int i=x; i<=mxn; i+=lowbit(i))
        {
            tr[i]+=c;
        }
    }
    ll sum(int x)
    {
        ll res=0;
        for (int i=x; i>0; i-=lowbit(i))
        res+=tr[i];
        return res;
    }
}bit;
int tt;
ll a[maxn],c[maxn];
int dt[maxn];
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&tt);
    while(tt--)
    {
        memset(tr,0,sizeof tr);
        scanf("%d",&n);
        mxn=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&dt[i]);
            mxn=max(mxn,dt[i]);
        }
        for (int i=1; i<=n; i++)
        {
          m=dt[i];
          bit.add(m,1);
          a[i]=bit.sum(m);
          c[i]=ll(i-a[i]);
        }
//        for (int i=1; i<=n; i++)
//        cout<<a[i]<<" "<<c[i]<<endl;
        ll ans=0;
        ll x1,x2,y1,y2;
        for (int i=2; i<n; i++)
        {
            x1=a[i]-1;
            x2=bit.sum(dt[i])-a[i];
            y1=(i-a[i]);
            y2=n-bit.sum(dt[i])-y1;
//            cout<<x1<<" "<<y2<<" | "<<x1<<" "<<x2<<endl;
            ans+=x1*y2;
            ans+=y1*x2;
        }
        printf("%I64d\n",ans);

    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,b) memset(a,b,sizeof(a))
#define w(x) while(x)
#define l 100005
#define ll __int64
#define s(a) scanf("%I64d",&a)
ll vis[l],a[l],b[l],c[l],n,i,j,ans;

int main()
{
    w((s(n),n))
    {
        up(i,1,n)
        s(a[i]);
        mem(vis,0);
        up(i,1,n)
        {
            if(vis[a[i]])
                b[i]=a[vis[a[i]]];
            else
                b[i]=a[i];
            up(j,1,sqrt(a[i]*1.0)+1)
            {
                if(a[i]%j==0)
                    vis[j]=vis[a[i]/j]=i;
            }
        }
        mem(vis,0);
        down(i,n,1)
        {
            if(vis[a[i]])
                c[i]=a[vis[a[i]]];
            else
                c[i]=a[i];
            up(j,1,sqrt(a[i]*1.0)+1)
            {
                if(a[i]%j==0)
                    vis[j]=vis[a[i]/j]=i;
            }
        }
        ans=0;
        up(i,1,n)
        ans+=b[i]*c[i];
        printf("%I64d\n",ans);
    }

    return 0;
}

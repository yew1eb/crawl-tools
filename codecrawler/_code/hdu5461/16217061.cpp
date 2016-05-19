#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
#define ll long long
#define CL(a) memset(a,0,sizeof(a))

ll T,n,a,b;
ll t[1000010];
ll min1,min2,max1,max2,k;//åå«å­æå°çæ°ãç¬¬äºå°çæ°ãæå¤§çæ°ãç¬¬äºå¤§çæ°åææ¥è¿0çæ°

int main ()
{
    scanf ("%lld",&T);
    for (int cas=1; cas<=T; cas++)
    {
        scanf ("%lld%lld%lld",&n,&a,&b);
        k=INF;
        for (int i=0; i<n; i++)
        {
            scanf ("%lld",&t[i]);
        }
        cout<<"Case #"<<cas<<": ";
        sort(t, t+n);
        for (int i=0; i<n; i++)
        {
            if (t[i]<=0&&t[i+1]>=0)
                k=min(-t[i], t[i+1]);
        }
        min1=t[0]; min2=t[1];
        max1=t[n-1]; max2=t[n-2];//æ¾åºè¿äºä¸ªæ°
        if (a<0&&b<0)//ç¶åå°±æ¯è¦é¼çæ¾æå¤§è§£äºï¼æ³¨æè´æ°çå¹³æ¹ä¸ºæ­£æ°
        {
            printf ("%lld\n",a*k*k+b*min1);
        }
        else if (a<0&&b>0)
        {
            printf ("%lld\n",a*k*k+b*max1);
        }
        else if (a>0&&b<0)
        {
            printf ("%lld\n",max(max(a*max1*max1+b*min1, a*min1*min1+b*min2), a*min2*min2+b*min1));
        }
        else if (a>0&&b>0)
        {
            printf ("%lld\n",max(max(a*max1*max1+b*max2, a*max2*max2+b*max1), a*min1*min1+b*max1));
        }
        else printf ("0\n");
    }
    return 0;
}

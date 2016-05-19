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

struct node
{
    ll r,e,l;
}s[100005];

ll cmp(node a, node b)
{
    return a.e<b.e;
}

int main ()
{
    int T,n,ii=1;
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d",&n);
        bool flag=false;
        for (int i=0; i<n; i++)
        {
            scanf ("%lld%lld%lld",&s[i].r,&s[i].e,&s[i].l);
            if (s[i].r > s[i].e)//ç´æ¥å¤æ­æ¯å¦æéè¦å¤ä¹ æ¶é´å¨èè¯å¼å§æ¶é´ä¹åå°±è¡
            {
                flag = true;
            }
        }
        /*sort(s, s+n, cmp);//è¿æ¯æä¹åçWAä»£ç 
        ll sum=0;

        for (int i=0; i<n; i++)
        {
            if (s[i].e<sum+s[i].r || s[i].r>s[i].e)
            {
                flag = true;
                break;
            }
            else sum += (s[i].r+s[i].e+s[i].l);
        }*/
        printf ("Case #%d: ",ii++);
        if (flag)
            printf ("NO\n");
        else
            printf ("YES\n");
    }
    return 0;
}

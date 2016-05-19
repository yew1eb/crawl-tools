#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;

#define fst first
#define scd second
const int maxn=1000000+123;
ll w[maxn];
ll dp[maxn];
pll queue[maxn];

ll calc(pll v, ll x)
{
    return x*v.fst+v.scd;
}
/// dp[i]=min(dp[j-1]+(x[i]-x[j])^2)
/// ==> dp[i]=x[i]^2+min(dp[j-1]-2*x[i]*x[j]+x[j]^2);
/// made b=dp[j-1]+x[j]*x[j];

bool good(pll x, pll x1, int y)
{
    return calc(x, w[y])>calc(x1, w[y]);
}

/// å¨x1æ¯xæ´ä¼åï¼ yå·²ç»æ¯x1æ´ä¼ï¼ æ­¤æ¶x1ç´æ¥ä»å°¾é¨å¼¹åºéåã
/// ç±äºç´çº¿çæçæ¯åè°éåç,æä»¥å½2æ¡ç´çº¿ç¸äº¤åï¼ åä¸æ¡ä¸å®æ¯åä¸æ¡æ´ä¼ï¼æ±åºäº¤ç¹
bool bad(pll x, pll x1, pll y)
{
    //cout << (dp[x1-1]-dp[x-1])/(w[x]-w[x1]) << " " << (dp[x1-1]-dp[y-1])/(w[y]-w[x1]) << endl;
    //return (dp[x1-1]+w[x1]*w[x1]-dp[x-1]-w[x]*w[x])/(w[x]-w[x1])<(dp[x1-1]+w[x1]*w[x1]-dp[y-1]-w[y]*w[y])/(w[y]-w[x1]);
    return (x1.scd-x.scd)/(x.fst-x1.fst)>(x1.scd-y.scd)/(y.fst-x1.fst);
}

int main ()
{
    ll c;
    int n;
    while (cin >> n >> c && (n || c))
    {
        for (int i=1; i<=n; ++i)
            scanf("%I64d", w+i);
        dp[0]=0; dp[1]=c;
        int head=0, rear=-1;
        queue[++rear]=make_pair(-2*w[1], w[1]*w[1]);
        for (int i=2; i<=n; ++i)
        {
            pll tt=make_pair(-2*w[i], dp[i-1]+w[i]*w[i]);
            while (head<rear && bad(queue[rear], queue[rear-1], tt))rear--;
            queue[++rear]=tt;
            while (head<rear && good(queue[head], queue[head+1], i))head++;
            dp[i]=c+w[i]*w[i]+calc(queue[head], w[i]);
//            for (int j=head+1; j<=rear; ++j)
//            {
//                ll tmp=dp[queue[j]-1]+calc(queue[j], i)+c;
//                if(dp[i]>tmp){dp[i]=tmp; head=j;}
//            }
//            printf("r=%d t=%d  dp[%d]=%I64d\n", head, rear,  i, dp[i]);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
/*
10 1000000000
1000
23000
450000
6700000
10100000
12400000
56000000
78900000
99000000
101900000
6 4
1 2 5 6 7 8
10 5000
1
23
45
67
101
124
560
789
990
1019
0 0
*/

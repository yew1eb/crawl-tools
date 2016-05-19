#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 505;

int mp[N][N], dp[N];

struct point
{
    int a, b;
} p[N];

bool cmp(point x, point y)
{
    if(x.b!=y.b) return x.b<y.b;
    else return x.a < y.a;
}

int main()
{
    int n, a, b;
    while(scanf("%d", &n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &a, &b);
            p[i].a = a+1;
            p[i].b = n-b;
        }
        sort(p, p+n, cmp);
        memset(mp, 0, sizeof(mp));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++)
        {
            a = p[i].a, b = p[i].b;
            if(a>b) 
                continue;
            if(mp[a][b]>=b-a+1) 
                continue;
            mp[a][b]++;
            dp[b] = max(dp[b], dp[a-1]+mp[a][b]);
            for(int j=b+1; j<=n; j++)
                dp[j] = dp[b];
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}

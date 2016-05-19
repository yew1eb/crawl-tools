#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 205;
int dp[N],a[N],b[N];
bool doit(int t,const int x,const int y,const int n)
{
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int ni = 1; ni <= n; ++ni)
    {
        if(dp[x] >= y) return true;
        int len = min(x, t/a[ni]);
        for(int i = x; i >= 0; --i)
        {
            for(int j = 0; j <= min(len, i); ++j)
            {
                if(dp[i-j] < 0) continue;
                dp[i] = max(dp[i],dp[i-j] + (t - j*a[ni])/b[ni]);
            }
        }
    }
    return dp[x] >= y;
}
int main()
{
    int cas;
    int n,x,y;
    scanf("%d",&cas);
    for(int cc = 1;cc <= cas;++cc){
        scanf("%d %d %d",&n,&x,&y);
        for(int i = 1; i <= n; ++i){
            scanf("%d %d",&a[i],&b[i]);
        }
        int ll = 1, rr = x*a[1] + y*b[1],mid = (ll + rr)/2;
        int ans;
        while(ll <= rr){
            if(doit(mid,x,y,n)){
                ans = mid;
                rr = mid - 1;
            }
            else
                ll = mid + 1;
            mid = (ll + rr)/2;
        }
        printf("Case %d: %d\n",cc,ans);
    }
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,-1,sizeof(x))
#define eps 1e-9
const double pi = acos(-1.0);
typedef long long LL;
typedef unsigned long long ULL;
const int modo = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int inf = 0x3fffffff;
const LL _inf = 1e18;
const int maxn = 2005,maxm = 10005;
int dp[maxn],s[maxn],cnt[maxn];
int main()
{
    int _;RD(_);
    int n;
    while(_--){
        RD(n);
        for(int i = 1;i <= n;++i)
            RD(s[i]),dp[i] = cnt[i] = 1;
        int ans = 0,_cnt = 0;
        for(int i = 2;i <= n;++i){
            for(int j = 1;j < i;++j){
                if(s[i] > s[j]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }else if(dp[i] == dp[j] + 1){
                        cnt[i] += cnt[j];
                    }
                }
            }
            ans = max(ans,dp[i]);
        }
        for(int i = 1;i <= n;++i)
            if(ans == dp[i])
                _cnt += cnt[i];
        printf("%d\n",ans - (_cnt == 1));
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 2000005;
int n, m, M;
int a[maxn];
ll dp[2][maxn];

int main(){
    int T;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ++ca){
        scanf("%d%d", &n, &m);
        M = 0;
        for(int i=0; i<n; ++i){
               scanf("%d", &a[i]);
            if(a[i]>M) M = a[i];
        }
        M *= 2;
        memset(dp, 0, sizeof dp );
        dp[0][0] = 1;
        int f = 0;
        for(int i=0; i<n; ++i){
            f = 1-f;
            for(int j=M; j>=0; --j){
                dp[f][j^a[i]] += dp[1-f][j];
                dp[f][j] += dp[1-f][j];
            }
            memset(dp[1-f], 0, sizeof dp[1-f] );
        }
        ll ans = 0;
        for(int i=m; i<=M; ++i) ans += dp[f][i];
        printf("Case #%d: %I64d\n", ca, ans);
    }
    return 0;
}
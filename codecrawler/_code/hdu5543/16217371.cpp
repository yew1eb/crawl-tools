#include <bits/stdc++.h>

using namespace std;
#define N 2000 + 10
#define M 4000 + 10
#define LL long long
const int mod = 1000000000 + 7;

int n, T, L;
struct Stick{
    int a; LL v;
}S[N];


LL dp[2][M][3];

int main(){
    int kase = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &L);
        L *= 2;
        LL ans = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d%I64d", &S[i].a, &S[i].v);
            S[i].a *= 2;
            ans = max(ans, S[i].v);
        }

        memset(dp, 0, sizeof dp);
        int t = 0;
        for(int i = 1; i <= n; i++){
            t ^= 1;
            for(int j = 0; j <= L; j++)
                for(int k = 0; k < 3; k++)
                    dp[t][j][k] = dp[t^1][j][k];

            for(int j = S[i].a/2; j <= L; j++)
                for(int k = 0; k < 3; k++){
                    if(j >= S[i].a)
                    dp[t][j][k] = max(dp[t][j][k], dp[t^1][j-S[i].a][k]+S[i].v);
                if(k){
                    dp[t][j][k] = max(dp[t][j][k], dp[t^1][j-S[i].a/2][k-1] + S[i].v);
                }
            }
        }
        
        for(int i = 0; i < 2; i++)
            for(int k = 0; k < 3; k++)
                ans = max(ans, dp[i][L][k]);

        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}

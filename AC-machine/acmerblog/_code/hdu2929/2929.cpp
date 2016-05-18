#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const int MAXM = 3010;
const int used[10] = {6,2,5,5,4,5,6,3,7,6};

int dp[MAXN][MAXM],next[MAXN][MAXM];
int n,m,maxlen;

int main(){
    int cas = 0;
    while (scanf("%d",&n) != EOF && n){
        scanf("%d",&m);
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0,maxlen = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dp[i][j] >= 0)
                    for (int k = 9; k >= 0; k--)
                        if (i + used[k] <= n){
                            int newi = i+used[k],newj = (j*10+k)%m;
                            if (dp[i][j] + 1 > dp[newi][newj]){
                                dp[newi][newj] = dp[i][j] + 1;
                                if (dp[newi][newj] > maxlen && newj == 0)
                                    maxlen = dp[newi][newj];
                            }
                        }
        memset(next,-1,sizeof(next));
        for (int i = n; i >= 0; i--)
            for (int j = 0; j < m; j++)
                if (dp[i][j] >= 0){
                    if (dp[i][j] == maxlen && j == 0){
                        next[i][j] = 10;
                        continue;
                    }
                    for (int k = 9; k >= 0; k--){
                        if (i + used[k] <= n){
                            int newi = i + used[k];
                            int newj = (j*10+k)%m;
                            if (dp[newi][newj] == dp[i][j] + 1 && next[newi][newj] >= 0){
                                next[i][j] = k;
                                break;
                            }
                        }
                    }
                }
        printf("Case %d: ",++cas);
        int i,j,u,v;
        if (maxlen > 0){
            i = 0,j = 0;
            while (next[i][j] != 10){
                u = i + used[next[i][j]];
                v = (j*10+next[i][j]) % m;
                printf("%d",next[i][j]);
                i = u,j = v;
            }
            printf("\n");
        }
        else if (n >= used[0])
                printf("0\n");
             else printf("-1\n");
    }
    return 0;
}
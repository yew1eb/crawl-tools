#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 110;
int dp[N][N];//times, postion

int main(){
    int n, p, m, t;
    while(cin >> n >> p >> m >> t){
        int i, j;
        memset(dp, 0, sizeof(dp));
        dp[0][p] = 1;
        for(i = 1;i <= m;i++)
            for(j = 1;j <= n;j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        cout << dp[m][t] << endl;
    }
    return 0;
}
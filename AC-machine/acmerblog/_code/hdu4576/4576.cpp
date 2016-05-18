#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 220;
const double eps = 0.0;
double dp[N][2];

int main(){
    int n, m, l, r;    
    while(cin >> n >> m >> l >> r){
        if(n == 0 && m == 0 && l == 0 && r == 0)
            break;
        int w, i, j;
        for(i = 0;i < n;i++)
            dp[i][0] = dp[i][1] = eps;
        dp[0][0] = 1.0;
        for(j = 1;j <= m;j++){
            scanf("%d", &w);
            for(i = 0;i < n;i++){
                dp[(i + w) % n][j&1] += dp[i][!(j&1)] * 0.5;
                int x = i - w;
                while(x < 0)
                	x += n;
                 dp[x][j&1] += dp[i][!(j&1)] * 0.5;    
            }
            for(i = 0;i < n;i++)
                dp[i][!(j&1)] = eps;
        }
        double res = 0.0;
        l--, r--;
        for(i = l;i <= r;i++)
            res += dp[i][m&1];
        printf("%.4lf\n", res);
    }    
    return 0;
}
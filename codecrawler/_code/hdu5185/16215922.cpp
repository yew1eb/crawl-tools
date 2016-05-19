/* ***********************************************
     Author        : Napoleon
     Mail          : tyfdream@163.com
     Created Time  : 2015-03-14 10:55:36
    Problem       : BC_32_D.cpp
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 
#define N 50005
int n, t, m, dp[360][N]; 

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
    scanf("%d", &t); 
    int ti = 0; 
    while(t--) {
        scanf("%d%d", &n, &m); 
        int M = 0; 
        while(M*(M+1) <= 2*n) M++; 
        M--; 
        dp[0][0] = 1; 
        for(int i = 1;i <= M; i++) {
            for(int j = i; j <= n; j++) {
                dp[i][j] = (dp[i][j-i] + dp[i-1][j-i]) % m; 
            }
        }
        int ans = 0; 
        for(int i = 1; i <= M; i++) {
            ans = (ans + dp[i][n]) % m; 
        }
        printf("Case #%d: %d\n", ++ti, ans); 
    }
    return 0; 
}
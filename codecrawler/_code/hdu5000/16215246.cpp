#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define N 2005
typedef long long ll;
const ll mod = 1000000007LL;


int n;
ll dp[N][N];
int a[N],sum;
ll solve(){
    if(n == 1)return 1LL;
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= a[1]; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= sum; j++) {
            for(int k = 0; k + j <= sum && k <= a[i]; k++)
            {
                dp[i][k+j] = (dp[i][k+j] + dp[i-1][j]) % mod;
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        sum = 0;
        for(int i = 1; i <= n; i++)
            sum += a[i];
        sum /= 2;

        cout<<solve()<<endl;
    }
    return 0;
}
/*
99
1
5
2
8 6
3
3 2 2  
3
2 2 2



*/
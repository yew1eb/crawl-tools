#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAX_ = 50;

int dp[MAX_];

int dfs(int n){
    if(dp[n])return dp[n];
    if(n == 1)return dp[n] = 1;
    if(n == 2)return dp[n] = 3;
    int cnt = 0;
    cnt +=  2*dfs(n-2) + dfs(n-1);
    return dp[n] = cnt;
}

int main()
{
    memset(dp,0,sizeof(dp));
    dfs(30);
    int n, Case;
    scanf("%d",&Case);
    while(Case--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}

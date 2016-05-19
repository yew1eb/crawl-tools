#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define eps 10e-8

const int MAX_ = 2010;
const int N = 100010;
const int INF = 0x7fffffff;

int t[MAX_], interval[MAX_];

int dp[MAX_][2];

int main(){
    int n, T;
    scanf("%d",&T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", & t[i]);
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i = 2; i <= n; ++i){
            scanf("%d", &interval[i]);
        }
        interval[1] = t[1];

        for(int i = 1; i <= n; ++i){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + t[i];
            if(i > 1){
                dp[i][1] = min(dp[i-2][0], dp[i-2][1]) + interval[i];
            }
            else dp[i][1] = t[i];
        }
        int ans = min(dp[n][1], dp[n][0]);
        int h, m, s;
        h = 8 + ans/3600;
        ans %= 3600;
        m = ans/60;
        ans %= 60;
        s = ans;
        if(h > 12){
            h %= 12;
            printf("%02d:%02d:%02d pm\n",h, m, s);
        }
        else{
            printf("%02d:%02d:%02d am\n",h, m, s);
        }

    }
    return 0;
}

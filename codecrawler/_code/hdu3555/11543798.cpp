#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int maxn = 21;

LL dp[maxn][3], num[maxn];
/*
s=
0 ²»º¬ ¡°49¡±
1 Ç°Ò»Î»Îª¡°4¡±
2 º¬¡°49¡±
*/
inline int new_s(int s, int d) {
    if(s==2 ||(s==1&&d==9)) {
        return 2;
    } else if(d==4) {
        return 1;
    } else
        return 0;
}
LL dfs(int i, int s, int e) {
    if(i==-1) return s==2;
    if(!e && ~dp[i][s]) return dp[i][s];
    LL res = 0;
    int u = e?num[i]:9;
    for(int d=0; d<=u; ++d) {
        res += dfs(i-1, new_s(s,d), e&&d==u);
    }
    return e?res:dp[i][s]=res;
}

LL solve(LL n) {
    int cnt = 0;
    while(n) {
        num[cnt++] = n % 10;
        n /= 10;
    }
    return dfs(cnt-1, 0, 1);
}

int main() {
    int t;
    LL n;
    memset(dp, -1, sizeof dp );
    scanf("%d", &t);
    while(t--) {
        scanf("%I64d", &n);
        printf("%I64d\n", solve(n) );
    }
    return 0;
}

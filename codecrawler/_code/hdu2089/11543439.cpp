#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[10][10];
///s=
///0 ±íÊ¾²»º¬¡°62¡± £¬¡°4¡±
///1 ±íÊ¾Ç°Ò»Î»Îª"6"

int num[10];

int dfs(int i, int s, int e){
    if(i==-1) return 1;
    if(!e && ~dp[i][s]) return dp[i][s];
    int res = 0;
    int u = e?num[i]:9;
    for(int d=0; d<=u; ++d){
        if(d==4) continue;
        if(s&&(d==2)) continue;
        res += dfs(i-1, d==6, e&&d==u);
    }
    return e?res:dp[i][s] = res;
}
int solve(int n)
{
    int cnt = 0;
    while(n)
    {
        num[cnt++] = n% 10;
        n /= 10;
    }
    return dfs(cnt-1, 0, 1);
}
int main() {
    int n, m;
    memset(dp, -1, sizeof dp );
    while(~scanf("%d%d", &n, &m)) {
        if(n==0 && m==0 ) break;
        printf("%d\n", solve(m) - solve(n-1) );
    }
    return 0;
}


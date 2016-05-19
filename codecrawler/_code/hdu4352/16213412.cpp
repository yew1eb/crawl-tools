#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 66;
int siz[1 << 10], nex[1 << 10][10]; // nex[i][j]è¡¨ç¤ºå·²ç»ç¨äºiç¶æçåºåï¼åå å¥æ°å­jä¸ä½¿å¾åºåç¶æä¸åä¼åæçç¶æ
int bit[20], K;
//å ä¸ºKåªæ10ï¼æä»¥ææè¿ä¸ªåºåçæé¿ä¹å°±æ¯0~9,æä»¥ç¨ä¸ä¸ªäºè¿å¶è¡¨ç¤º0~9ä¸­åªäºå·²ç»ç¨è¿äº
ll dp[N][1<<10][11];//dp[len][high][state][lis];é¿åº¦ä¸ºlenï¼æé«ä½ä¸ºhighï¼å·²ä½¿ç¨è¿çææå­åºåçç¶æä¸ºstate,æé¿ä¸åå­åºåä¸ºlis
ll dfs(int len, int state, bool zero, bool flag){
    if (len == 0)return siz[state] == K;
    if (!flag && dp[len][state][K] != -1)return dp[len][state][K];

    ll ans = 0;
    int end = flag ? bit[len] : 9;
    for (int i = 0; i <= end; i++)
        ans += dfs(len - 1, (zero&&i == 0) ? 0 : nex[state][i], zero&&i == 0, flag&&i == end);

    if (!flag)dp[len][state][K] = ans;
    return ans;
}

ll solve(ll x){
    int len = 0;
    for (ll tmp = x; tmp; tmp /= 10)bit[++len] = tmp % 10;
    return dfs(len, 0, 1, 1);
}
int find_nex(int status, int num){
    for (int i = num; i < 10; i++)
    if (status&(1 << i))return(status ^ (1 << i)) | (1 << num);
    return status | (1 << num);
}

int main() {
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 1 << 10; i++){
        siz[i] = 0;
        for (int j = 0; j < 10; j++)
        {
            if (i&(1 << j))siz[i]++;
            nex[i][j] = find_nex(i, j);
        }
    }
    int T, Cas = 1; scanf("%d", &T);
    while (T-- > 0){
        ll l, r;
        cin >> l >> r >> K;
        printf("Case #%d: %I64d\n", Cas++, solve(r) - solve(l - 1));
    }
    return 0;
}
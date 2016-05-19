#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100005;
const long long MOD = 1e9 + 7;
vector<int> g[N];
long long A[N], res;

int dfs(int u, int fa) {
    int tot = 1, ns = 0, nt = 0;//åå«æ ¹èç¹çææèç¹ï¼ç´æ¥å­©å­èç¹ï¼å­æ ä¸ªæ°
    int n = g[u].size();
    for (int i = 0; i < n; i++) {
        int v = g[u][i];
        if (v == fa)
            continue;
        ns++;   
        int num = dfs(v, u);
        if (num > 1)
            nt++;
        tot += num;
    }
    if (nt > 2)//æå¤§äºä¸¤ä¸ªå­æ æ æ³ä¿è¯åå²åè¿ç»­
        return res = 0;
    if (nt)//æä¸ä¸ªæä¸¤ä¸ªå­æ åå²æ¹æ³æ°é½åªæä¸¤ä¸ª
        res = res * 2 % MOD;
    res = res * A[ns - nt] % MOD;//å½ä¸ªèç¹å¯èªç±æåº
    return tot;
}

int main() {
    A[0] = 1;
    for (int i = 1; i < N; i++)
        A[i] = A[i - 1] * i % MOD;
    int t, cas = 1, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
            g[i].clear();
        int a, b;
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);  
        }
        if (n == 1) {
            printf("Case #%d: 1\n", cas++);
            continue;   
        }
        res = 1;
        dfs(1, 0);
        printf("Case #%d: %lld\n", cas++, res * 2 % MOD);//æ ¹èç¹å·¦å³ä¸¤ç§åæ³
    }
    return 0;
}
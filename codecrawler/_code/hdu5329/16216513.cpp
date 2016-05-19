/*hdu 5329 Question for the Leader
  é¢æï¼
  ç»åºä¸ä¸ªænä¸ªç¹çå¾ï¼è¿ä¸ªå¾æ¯ç±ä¸ä¸ªåºç¯ + è¥å¹²å¤åæ ç»æï¼é®è½å¦æè¿ä¸ªå¾åæ kä¸ª å¤§å°ä¸ºn/k ç è¿éçå­å¾ï¼é®kæå¤å°ç§ã
  éå¶ï¼
  1 <= n <= 1e5
  æè·¯ï¼
  ä¸»è¦æ¯ä¸ä¸ªæ§è´¨ï¼
  å¯¹äºä¸æ£µæ ï¼å¦æå¯ä»¥æè¿æ£µæ åæå¤§å°é½ä¸ºkçn/kä»½ï¼é£å­æ å¤§å°æ¯kçåæ°çèç¹æ°å¥½æn/kä¸ªã(ä»»æéå®ä¸ä¸ªæ ¹)
  è¯¦ç»è§å¤æ ¡å®æ¹é¢è§£
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define PB push_back
const int N = 1e5 + 5;
int a[N];

int cir[N], cir_tot;
bool in_cir[N];

int tree_sz[N];
int cnt[N];

vector<int> G[N];

int fa[N];
void init_bcj(int n) {
    for(int i = 0; i <= n; ++i)
        fa[i] = i;
}
int get_fa(int x) {
    if(x != fa[x]) return fa[x] = get_fa(fa[x]);
    return x;
}

int dfs(int u, int fa) {
    tree_sz[u] = 1;
    for(int i = 0; i < G[u].size(); ++i) {
        int ch = G[u][i];
        if(ch == fa || in_cir[ch]) continue;
        tree_sz[u] += dfs(ch, u);
    }
    return tree_sz[u];
}

int sum[N], sum_cnt[N];
bool ok(int bei, int have, int n) {
    for(int i = 0; i < bei; ++i)
        sum_cnt[i] = 0;
    sum[0] = tree_sz[cir[0]] % bei;
    ++sum_cnt[sum[0]];
    for(int i = 1; i < cir_tot; ++i) {
        sum[i] = (sum[i - 1] + tree_sz[cir[i]]) % bei;
        ++sum_cnt[sum[i]];
    }
    if(sum_cnt[0] + have == n / bei) return true;
    int last = cir_tot - 1;
    for(int i = 0; i < cir_tot - 1; ++i) {
        --sum_cnt[sum[i]];
        int tmp = sum[i];
        sum[i] = (sum[last] + tree_sz[cir[i]]) % bei;
        ++sum_cnt[sum[i]];
        if(sum_cnt[tmp] + have == n / bei) return true;
        last = i;
    }
    return false;
}

void gao(int n) {
    cir_tot = 0;
    for(int i = 1; i <= n; ++i) {
        G[i].PB(a[i]);
        G[a[i]].PB(i);
        int fx = get_fa(i);
        int fy = get_fa(a[i]);
        if(fx != fy) fa[fy] = fx;
        else if(cir_tot == 0){
            cir[cir_tot++] = i;
            in_cir[i] = 1;
        }
    }

    int nxt = a[cir[0]];
    while(nxt != cir[0]) {
        cir[cir_tot++] = nxt;
        in_cir[nxt] = 1;
        nxt = a[nxt];
    }
    
    for(int i = 1; i <= n; ++i) {
        if(in_cir[i]) dfs(i, -1);
    }

    for(int i = 1; i <= n; ++i)
        if(!in_cir[i]) ++cnt[tree_sz[i]];

    for(int i = 1; i <= n; ++i) {
        for(int j = 2 * i; j <= n; j += i) {
            cnt[i] += cnt[j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(n % i) continue;
        if(ok(i, cnt[i], n)){
            ++ans;
        }
    }
    printf("%d\n", ans);
}

void init(int n) {
    init_bcj(n);
    memset(in_cir, 0, sizeof(in_cir));
    memset(tree_sz, 0, sizeof(tree_sz));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i <= n; ++i)
        G[i].clear();
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        init(n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        gao(n);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int MOD = 1000000007;
typedef long long LL;

int n, m;
char ch[N][15];

struct PP {
    int tp[N][N];
}a;

PP mul(const PP &a, const PP &b) {
    PP c;
    memset(c.tp, 0, sizeof(c.tp));
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= n; j++)
            for(int k = 1;k <= n; k++) {
                c.tp[i][j] += (LL)a.tp[i][k]*b.tp[k][j]%MOD;
                c.tp[i][j] %= MOD;
            }
    return c;
}

bool check(int x, int y) {
    int lenx = strlen(ch[x]), leny = strlen(ch[y]);
    if(lenx == 1 || leny == 1) return false;
    for(int i = lenx-2;i >= 0; i--) {
        int j = 0, ti = i;
        while(ti < lenx && j < leny && ch[x][ti] == ch[y][j]) ti++, j++;
        if(ti == lenx) return true;
    }
    return false;
}
            
void solve() {
    memset(a.tp, 0, sizeof(a.tp));
    for(int i = 1;i <= n; i++) 
        for(int j = 1;j <= n; j++)
            if(check(i, j)) a.tp[i][j] = 1;
    
    int tm = m;
    PP tmp = a, res;
    memset(res.tp, 0, sizeof(res.tp));
    for(int i = 1;i <= n; i++) res.tp[1][i] = 1;
    tm--;
    while(tm) {
        if(tm&1) {
            res = mul(res, tmp);
        }
        tmp = mul(tmp, tmp);
        tm >>= 1;
    }
    int ans = 0;
    for(int i = 1;i <= n; i++) ans = (ans+res.tp[1][i])%MOD;
    printf("%d\n", ans);
}
    
set <string> st;
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        st.clear();
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= n; i++) {
            scanf("%s", ch[i]);
            st.insert(ch[i]);
        }
        int tn = 0;
        for(auto &it:st) strcpy(ch[++tn], it.c_str());
        n = tn;
        solve();
    }
    return 0;
}
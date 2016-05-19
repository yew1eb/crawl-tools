#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000020
struct node {
    int pre, mod;
    char c;
} q[N];
int n, m;
bool v[10010];
void print(int x) {
    if (x == 0) return ;
    print(q[x].pre);
    putchar(q[x].c);
}
int main() {
    int cas = 1, t, a[10];
    bool vis[10];
    while (scanf("%d%d", &n, &m) == 2) {
        memset(vis, false, sizeof(vis));
        for (int i=0; i<m; i++) {
            scanf("%d", &t); vis[t] = true;
        }
        m = 0;
        for (int i=0; i<10; i++) if (!vis[i]) a[m++] = i;
        printf("Case %d: ", cas++);

        if (m == 0) {
            puts("-1"); continue;
        }
        memset(v, false, sizeof(v));
        int l = 1, r = 1, ans = -1;
        for (int i=0; i<m; i++) if (a[i]) {
            q[r].pre = 0;
            v[q[r].mod = a[i] % n] = true;
            q[r].c = a[i] + '0';
            if (q[r].mod == 0) { ans = r; break; }
            r++;
        }

        while (l < r && ans == -1) {
            for (int i=0; i<m; i++) {
                q[r].mod = (q[l].mod*10 + a[i])%n;
                if (!v[q[r].mod]) {
                    v[q[r].mod] = true;
                    q[r].pre = l;
                    q[r].c = a[i] + '0';
                    if (q[r].mod == 0) { ans = r; break; }
                    r++;
                }
            }
            l++;
        }

        if (ans == -1) puts("-1");
        else {
            print(ans); printf("\n");
        }
    }


    return 0;
}
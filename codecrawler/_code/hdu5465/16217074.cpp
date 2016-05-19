#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 505;
int n, m, q;

struct BIT {
    int c[N][N];

    void clear() { memset(c, 0, sizeof(c)); }

    inline int lowbit(int x) { return x & (-x); }

    int query(int x, int y) {
        int res = 0;
        for(int i = x; i > 0; i -= lowbit(i)) {
            for(int j = y; j > 0; j -= lowbit(j)) {
                res ^= c[i][j];
            }
        }
        return res;
    }

    int query(int x1, int y1, int x2, int y2) {
        x1--, y1--;
        int area[2][2] = {0};
        area[0][0] = query(x1, y1); area[1][1] = query(x2, y2);
        area[0][1] = query(x1, y2); area[1][0] = query(x2, y1);
        int res = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                res ^= area[i][j];
        return res;
    }

    void add(int x, int y, int val) {
        for(int i = x; i <= n; i += lowbit(i))
            for(int j = y; j <= m; j += lowbit(j))
                c[i][j] ^= val;
    }

    void modify(int x, int y, int val) {
        add(x, y, query(x, y, x, y));
        add(x, y, val);
    }
} bit;

int main() {
    int op, x1, x2, y1, y2, val;

    int T;
    scanf("%d", &T);

    while(T--) {
        scanf("%d%d%d", &n, &m, &q);

        bit.clear();
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &val);
                bit.add(i, j, val);
            }
        }
        while(q--) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                int ans = bit.query(x1, y1, x2, y2);
                puts(ans != 0 ? "Yes" : "No");
            }else {
                scanf("%d%d%d", &x1, &y1, &val);
                bit.modify(x1, y1, val);
            }
        }
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 1000006;
const int inf  = 1e9+6;
using namespace std;
#define L ch[x][0]
#define R ch[x][1]
#define KT ch[ ch[root][1]][0]
int cur, size;
struct splaytree {
    int sz[maxn], ch[maxn][2], pre[maxn];
    int tot, root;
    int sum[maxn], val[maxn], ans[maxn];
    int sta[maxn], top;

    void rotate(int &x, int f) {
        int y = pre[x], z = pre[y];
        ch[y][!f] = ch[x][f];
        pre[ch[x][f]] = y;
        pre[x] = pre[y];
        if(z) ch[z][ch[z][1] == y] = x;
        ch[x][f] = y;
        pre[y] = x;
        up(y);
    }
    void splay(int &x, int g) {
        while(pre[x] != g) {
            int y = pre[x], z = pre[y];
            if(z == g) rotate(x, ch[y][0] == x);
            else {
                int f = (ch[z][0] == y);
                ch[y][!f] == x ? rotate(y, f) : rotate(x, !f);
                rotate(x, f);
            }
        }
        if(!g) root = x;
        up(x);
    }
    void rto(int k, int g) {
        int x = root;
        while(sz[L] != k) {
            if(sz[L] > k) x = L;
            else {
                k -= sz[L]+1;
                x = R;
            }
        }

        splay(x, g);
    }
    void newNode(int &x, int v, int fa) {
        if(top) x = sta[top--];
        else x = ++tot;
        sz[x] = 1;
        pre[x] = fa;
        L = R = 0;
        sum[x] = ans[x] = val[x] = v;
    }
    void init() {
        top = tot = 0;
        cur = size = 0;

        newNode(root, -inf, 0);
        newNode(ch[root][1], -inf, root);
    }
    void insert(int k, int v) {
        rto(k, 0);
//debug();
        int x;
        newNode(x, v, root);
        ch[x][1] = ch[root][1];
        if(ch[x][1])pre[ch[x][1]] = x;
        ch[root][1] = x;
        up(x);
        up(root);
    }
    void erase(int k) {
        rto(k, 0);
        rto(k-1, root);
        sta[++top] = root;
        int l = ch[root][0], r = ch[root][1];
        root = l;
        pre[l] = 0;
        ch[l][1] = r;
        if(r)pre[r] = l;
        up(l);
    }
    void query(int k) {
        rto(0, 0);
        rto(k+1, root);
        printf("%d\n", ans[KT]);
    }
    void up(int x) {
        sz[x] = sz[L] + sz[R] + 1;
        sum[x] = sum[L] + sum[R] + val[x];
        if(!sz[L]) {
            ans[x] = max(val[x], val[x]+ans[R]);
        }
        else {
            ans[x] = max(ans[L], sum[L] + max(val[x], 0));
            ans[x] = max(ans[x], sum[L]+ val[x]+max(0, ans[R]));
        }
    }
    void print(int x) {

        printf("node %d, left %d, right %d, pre %d, sum %d, ans %d, val %d\n", x, L, R, pre[x], sum[x], ans[x], val[x]);
        if(L) print(L);
        if(R) print(R);
    }
    void debug() {
        printf("root = %d cur = %d size = %d\n", root, cur, size);
        print(root);
    }
    void down(int x) {

    }
}spt;
int main() {
    int m, x;
    char op[3];
    while( ~scanf("%d", &m)) {
        spt.init();
        while(m--) {
            scanf("%s", op);
            if(op[0] == 'L') {
                if(cur)cur--;
            }
            else if(op[0] == 'R') {
                if(cur < size)cur++;
            }
            else if(op[0] == 'D') spt.erase(cur--), size--;
            else {
                scanf("%d", &x);
                if(op[0] == 'I') spt.insert(cur++, x), size++;
                else spt.query(x);
            }
        //    spt.debug();
        }
    }
    return 0;
}

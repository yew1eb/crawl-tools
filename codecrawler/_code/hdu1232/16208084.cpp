#include <cstdio>
#include <cstring>

#define LEN 1001

int p[LEN];

void init(int len) {
    for(int i = 0; i <= len; i++) {
        p[i] = i;
    }
}

int find(int x) {
    return p[x] == x ? x : (p[x] = find(p[x]));
}

int main() {
    int n, m, a, b;
    int i, j;
    int sum;
    while(scanf("%d%d", &n, &m), n != 0) {
        sum = 0;
        init(n);
        for(i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            int t1 = find(p[a]);
            int t2 = find(p[b]);
            if(t1 != t2) {
                p[t1] = t2;
            }
        }
        for(i = 1; i <= n; i++) {
            if(p[i] == i) {
                ++sum;
            }
        }
        printf("%d\n", sum-1);
    }
    return 0;
}

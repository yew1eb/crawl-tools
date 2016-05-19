#include <cstdio>
#include <iostream>

using namespace std;

#define LEN 1001

int p[LEN];

void init() {
    int i;
    for(i = 0; i < LEN; i++) {
        p[i] = i;
    }
}

int find(int x) {
    return x == p[x] ? x : (p[x] = find(p[x]));
}

int main() {
    int n, m;
    int i, j;
    while(scanf("%d%d", &n, &m) != EOF) {
        int a, b, sum;
        sum = 0;
        init();
        for(i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            int t1 = find(a);
            int t2 = find(b);
            if(t1 == t2) {
                sum++;
            }
            else {
                p[t2] = t1;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

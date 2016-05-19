#include <cstdio>
#include <cstring>
typedef long long ll;
#define N 1002
bool vis[N];
int sg[N];
int a[] = {4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7};
int SG(int x) {
    if (sg[x] != -1) return sg[x];
    if (x == 0) return 0;
    if (x == 1) return 0;
    if (x == 2) return 1;
    if (x == 3) return 1;
    memset(vis, false, sizeof(vis));
    for (int i=0; i<x-1; i++) vis[SG(i)^SG(x-i-2)] = true;
    for (int i=0; ;i++) if (!vis[i]) return i;
}
int get_sg(int x) {
    if (x <= 100) return sg[x];
    return a[x%34];
}
int main() {
    memset(sg, -1, sizeof(sg));
    for (int i=0; i<=100; i++) sg[i] = SG(i);

    int T, n, x; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans = 0;
        while (n--) { scanf("%d", &x); ans ^= get_sg(x); }
        puts(ans ? "Carol" : "Dave");
    }
    return 0;
}

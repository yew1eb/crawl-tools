#include <cstdio>
#include <cmath>
int SG(int s, int c) {
    int t = sqrt(s);
    while (t*t + t >= s) t--;
    if (c > t) return s-c;
    else return SG(t, c);
}
int main() {
    int cas = 1, ans, c, s, n;
    while(scanf("%d", &n)==1 && n) {
        ans = 0;
        while(n--) { scanf("%d%d", &s, &c); ans ^= SG(s, c); }
        printf("Case %d:\n", cas++); puts(ans?"Yes":"No");
    }
    return 0;
}

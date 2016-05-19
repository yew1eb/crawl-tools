#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        int d = n / gcd(a, b);
        printf("Case #%d: %s\n", kcas, d&1 ? "Yuwgna" : "Iaka");
    }
    return 0;
}
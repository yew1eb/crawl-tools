#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        ll n, k;
        scanf("%llu%llu", &n, &k);
        printf("Case #%d:\n", kcas);
        ll d = (1LL << k) - n;
        for (int i = 1; i < k; i++) {
            if (d&(1LL<<i)) printf("%llu -\n", 1LL << (i-1));
            else printf("%llu +\n", 1LL << (i-1));
        }
        printf("%llu +\n", (1LL << (k-1)) + (d&1 ? 0 : 1));
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
using namespace std;
typedef long long ll;

ll f[50];
inline void init() {
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= 45; i++) {
        f[i] = f[i-1] + f[i-2];
    }
}
bool dfs(ll n, int x) {
    if(n <= 3) {
        return true;
    }
    for(int i = 3; i <= x; i++) {
        if(n % f[i] == 0) {
            if(dfs(n / f[i], i)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    init();
    int T;
    ll n;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld",&n);
        if(dfs(n, 45)) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;

char str[maxn];

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        scanf("%s", str);
        int n = strlen(str), ans = inf;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) if (str[i] == str[j])
                ans = min(ans, j - i);
        if (ans == inf) ans = -1;
        printf("Case #%d: %d\n", kcas, ans);
    }
    return 0;
}
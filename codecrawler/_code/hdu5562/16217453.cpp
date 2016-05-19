#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int N, W[maxn], V;

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &N, &V);
        for (int i = 1; i <= N; i++) scanf("%d", &W[i]);
        sort(W + 1, W + 1 + N);

        int ans = 0;
        for (int i = 1; i <= N && W[i] <= V; i++) {
            ans++;
            V -= W[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
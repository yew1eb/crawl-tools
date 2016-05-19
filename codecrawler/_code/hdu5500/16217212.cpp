#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 30;

int N, A[maxn];

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
        int ans = N;
        for (int i = N; i; i--) if (ans == A[i]) ans--;
        printf("%d\n", ans);
    }
    return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M, DP[2010] = {0};
        scanf("%d%d", &M, &N);
        for (int r = 1; r <= N; r++) {
            int W, A, B;
            scanf("%d%d%d", &W, &A, &B);
            for (int i = M; i >= W; i--)
                DP[i] = max(DP[i], DP[i-W] + A + B);
            for (int i = W; i <= M; i++)
                DP[i] = max(DP[i], DP[i-W] + A);
        }
        printf("%d\n", DP[M]);
    }
    return 0;
}
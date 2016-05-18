#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

int N, A[maxn], B[maxn], C[maxn], P[maxn];

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &B[i]);
        for (int i = 0; i < N; i++) A[i] = C[i] = P[i] = i;

        for (int i = 0; i < N; i++) {
            int u = i;
            while ((A[u] + B[u]) % N != C[u]) {
                int v = P[(C[u] - B[u] + N) % N];
                swap(A[u], A[v]);
                swap(P[A[u]], P[A[v]]);

                if (v > i) break;
                swap(C[i+1], C[v]);
                u = v;
            }
        }
        for (int i = 0; i < N; i++) printf("%d%c", A[i], i == N-1 ? '\n' : ' ');
        for (int i = 0; i < N; i++) printf("%d%c", C[i], i == N-1 ? '\n' : ' ');
    }
    return 0;
}
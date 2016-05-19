#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long Long;

const int N = 10;
const int M = N * (N - 1) / 2;
const int MOD = (int)1e9 + 7;

Long two[M + 1];
bool graph[N][N];

unsigned char cut[1 << N][1 << N];
Long connected[1 << N], biconnected[1 << N], go[1 << N][1 << N];

int main()
{
    two[0] = 1;
    for (int i = 1; i <= M; ++ i) {
        two[i] = two[i - 1] << 1;
    }
    int test_count;
    scanf("%d", &test_count);
    while (test_count --) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(graph, true, sizeof(graph));
        for (int i = 0; i < n; ++ i) {
            graph[i][i] = false;
        }
        for (int i = 0; i < m; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            graph[a][b] = graph[b][a] = false;
        }
        for (int a = 0; a < 1 << n; ++ a) {
            for (int b = 0; b < 1 << n; ++ b) {
                if (a == b || !(a & b)) {
                    unsigned char &ref = cut[a][b];
                    ref = 0;
                    for (int i = 0; i < n; ++ i) {
                        if (a >> i & 1) {
                            for (int j = a == b ? i + 1 : 0; j < n; ++ j) {
                                ref += (b >> j & 1) && graph[i][j];
                            }
                        }
                    }
                }
            }
        }
        connected[0] = biconnected[0] = 1;
        for (int mask = 1; mask < 1 << n; ++ mask) {
            int lowbit = mask & -mask;
            {
                Long &ref = connected[mask];
                ref = two[cut[mask][mask]];
                for (int subset = mask ^ lowbit; subset > 0; subset = subset - 1 & (mask ^ lowbit)) {
                    ref -= connected[mask ^ subset] * two[cut[subset][subset]];
                }
            }
            {
                for (int target = mask ^ lowbit; target > 0; target = target - 1 & (mask ^ lowbit)) {
                    int source = mask ^ target;
                    Long &ref = go[mask][source];
                    ref = 0;
                    int lowbit = target & -target;
                    for (int subset = target ^ lowbit; ; subset = subset - 1 & (target ^ lowbit)) {
                        int set = target ^ subset;
                        ref += cut[source][set] * connected[set] * go[mask ^ set][source];
                        if (subset == 0) {
                            break;
                        }
                    }
                }
                go[mask][mask] = 1;
            }
            {
                Long &ref = biconnected[mask];
                ref = connected[mask];
                for (int subset = mask ^ lowbit; subset > 0; subset = subset - 1 & (mask ^ lowbit)) {
                    ref -= biconnected[mask ^ subset] * go[mask][mask ^ subset];
                }
            }
        }
        int result = biconnected[(1 << n) - 1] % MOD;
        std::cout << result << std::endl;
    }
    return 0;
}
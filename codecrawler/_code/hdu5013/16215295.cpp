/**************************************************
 *        Problem:  HDU 5013
 *         Author:  clavichord93
 *          State:  Accepted
 **************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

const int MAX_N = 16;
const int MAX_S = 1 << MAX_N;

int n, m;
double p[MAX_N];
int happiness[MAX_N][MAX_N];

int cntState;
int cnt[MAX_S];
double P[MAX_S];
double Q[MAX_S];
int sum[MAX_S][MAX_N];
double f[MAX_S];
double g[MAX_S];
double h[MAX_S];

int main() {
    #ifdef LOCAL_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    while (scanf("%d %d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            scanf("%lf", &p[i]);
            if (p[i] < 1 + 1e-9 && p[i] > 1 - 1e-9) {
                p[i] -= 1e-9;
            }
            //assert(1 - p[i] >= -1e-9);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &happiness[i][j]);
            }
        }

        //cout << "hehe" << endl;

        cntState = 1 << m;
        for (int mask = 0; mask < cntState; mask++) {
            P[mask] = 1;
            Q[mask] = 1;
            cnt[mask] = 0;
            for (int j = 0; j < m; j++) {
                if ((mask >> j) & 1) {
                    P[mask] *= p[j];
                    Q[mask] *= 1.0 - p[j];
                    cnt[mask]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            sum[0][i] = 0;
            for (int j = 0; j < m; j++) {
                sum[1 << j][i] = happiness[j][i];
            }
            for (int mask = 0; mask < cntState; mask++) {
                int lowbit = mask & -mask;
                sum[mask][i] = sum[mask ^ lowbit][i] + sum[lowbit][i];
            }
        }

        for (int mask = 0; mask < cntState; mask++) {
            f[mask] = sum[mask][n - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int mask = 1; mask < cntState; mask++) {
                g[mask] = P[mask] / Q[mask] * f[mask];
                h[mask] = P[mask] / Q[mask] * cnt[mask] * sum[mask][i + 1];
            }
            for (int bit = 0; bit < m; bit++) {
                for (int mask = cntState - 1; mask; mask--) {
                    if ((mask >> bit) & 1) {
                        g[mask] = g[mask] + g[mask ^ (1 << bit)];
                        h[mask] = h[mask] + h[mask ^ (1 << bit)];
                    }
                }
            }
            for (int mask = 1; mask < cntState; mask++) {
                f[mask] = Q[mask] * g[mask] + Q[mask] / cnt[mask] * h[mask] + sum[mask][i];
            }
        }

        printf("%.10f\n", f[cntState - 1]);
    }

    return 0;
}
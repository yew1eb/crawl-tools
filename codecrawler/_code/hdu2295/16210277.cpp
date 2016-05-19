#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 

using namespace std;

const int maxn = 50*50 + 10;
const int oo = 1 << 30;
const int maxrow = 55;
const int maxcol = 55;
int mtx[maxrow][maxcol];
double dis[55][55];
double cx[55], cy[55];
double rx[55], ry[55];
int t, n, m, k;

int totRow, totCol, head, idx;
int L[maxn], R[maxn], U[maxn], D[maxn];
int RH[maxn], CH[maxn], S[maxn];

void initMtx(double x)
{
    memset(mtx, 0, sizeof(mtx));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dis[i][j] <= x) {
                mtx[i][j] = 1;
            }
        }
    }
}

int newNode(int up, int down, int left, int right)
{
    U[idx] = up;    D[idx] = down;
    L[idx] = left;  R[idx] = right;
    U[down] = D[up] = L[right] = R[left] = idx;
    return idx++;
}

void build()
{
    idx = maxn - 1;
    head = newNode(idx, idx, idx, idx);
    idx = 0;
    for (int j = 0; j < totCol; ++j) {
        newNode(idx, idx, L[head], head);
        CH[j] = j;  S[j] = 0;
    }
    for (int i = 0; i < totRow; ++i) {
        int k = -1;
        for (int j = 0; j < totCol; ++j) {
            if (!mtx[i][j]) continue;
            if (-1 == k) {
                k = newNode(U[CH[j]], CH[j], idx, idx);
                RH[k] = i;  CH[k] = j;  S[j]++;
            } else {
                k = newNode(U[CH[j]], CH[j], k, R[k]);
                RH[k] = i;  CH[k] = j;  S[j]++;
            }
        }
    }
}

void remove(int c)
{
    for (int i = D[c]; i != c; i = D[i]) {
        L[R[i]] = L[i]; R[L[i]] = R[i]; /*S[CH[i]]--;*/
    }
}

void resume(int c)
{
    for (int i = U[c]; i != c; i = U[i]) {
        L[R[i]] = R[L[i]] = i; /*S[CH[i]]++;*/ 
    }
}

/*ä¼°ä»·å½æ°*/
int h()
{
    bool vis[maxcol];
    memset(vis, false, sizeof(vis));
    int ret = 0;
    for (int i = R[head]; i != head; i = R[i]) {
        if (!vis[i]) {
            ret++;
            vis[i] = true;
            for (int j = D[i]; j != i; j = D[j]) {
                for (int k = R[j]; k != j; k = R[k]) {
                    vis[CH[k]] = true;
                }
            }
        }
    }
    return ret;
}

bool dance(int cnt)
{
    if (cnt + h() > k) {
        return false;
    }
    if (R[head] == head) {
        return true;
    }
    int c, Min = oo;
    for (int i = R[head]; i != head; i = R[i]) {
        if (S[i] < Min) {
            Min = S[i]; c = i;
        }
    }
    for (int i = D[c]; i != c; i = D[i]) {
        remove(i);
        for (int j = R[i]; j != i; j = R[j]) {
            remove(j);
        } 
        if (dance(cnt + 1)) {
            return 1;
        } 
        for (int j = L[i]; j != i; j = L[j]) {
            resume(j);
        }
        resume(i);
    }
    return false; 
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &k);
        totRow = m; totCol = n;
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &cx[i], &cy[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lf%lf", &rx[i], &ry[i]); 
        }
        double l = 1e9, r = -1.0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = sqrt((rx[i] - cx[j])*(rx[i] - cx[j]) + (ry[i] - cy[j])*(ry[i] - cy[j])); 
                l = min(dis[i][j], l);
                r = max(dis[i][j], r);
            }
        }
        
        while (r - l > 1e-7) {
            double mid = (r + l) / 2.0;
            initMtx(mid);
            build();
            if (dance(0)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%.6lf\n", l);
    }
    return 0;
}

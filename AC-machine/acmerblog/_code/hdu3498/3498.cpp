#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath> 

using namespace std;

const int maxn = 60*60 + 10;
const int oo = 1 << 30;
const int maxrow = 60;
const int maxcol = 60;
int mtx[maxrow][maxcol];
int n, m, ans;

int totRow, totCol, head, idx;
int L[maxn], R[maxn], U[maxn], D[maxn];
int RH[maxn], CH[maxn], S[maxn];

void initMtx()
{
    memset(mtx, 0, sizeof(mtx));
    for (int i = 0; i < n; ++i) {
        mtx[i][i] = 1;
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        a--; b--;
        mtx[a][b] = mtx[b][a] = 1;
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

/*估价函数*/
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

void dance(int cnt)
{
    if (cnt + h() >= ans) { //此处写成">"会TLE
        return ;
    }
    if (R[head] == head) {
        ans = cnt;
        return ;
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
        
        dance(cnt + 1);
        
        for (int j = L[i]; j != i; j = L[j]) {
            resume(j);
        }
        resume(i);
    }
    return ; 
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF) {
        totRow = n; totCol = n; 
        initMtx();
        build();
        ans = oo;
        dance(0);
        printf("%d\n", ans);
    } 
    return 0;
}

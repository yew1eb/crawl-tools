#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 9*9*9*9*9*4 + 10;
const int oo = 1 << 30;
const int maxrow = 9*9*9 + 10;
const int maxcol = 9*9*4 + 10;
int mtx[maxrow][maxcol];
int sub[10][10];
int map[10][10];
int ansMap[10][10];

int totRow, totCol, head, idx;
int L[maxn], R[maxn], U[maxn], D[maxn];
int RH[maxn], CH[maxn], S[maxn];
int t, ans;

void initMtx()
{
    memset(mtx, 0, sizeof(mtx));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int t = i * 9 + j;
            if (map[i][j] == 0) {
                for (int k = 0; k < 9; ++k) {
                    int row = t * 9 + k;
                    mtx[row][t] = 1;
                    mtx[row][i*9+k+81] = 1;
                    mtx[row][j*9+k+162] = 1;
                    mtx[row][sub[i][j]*9+k+243] = 1;
                }
            } else {
                int k = map[i][j] - 1;
                int row = t * 9 + k;
                mtx[row][t] = 1;
                mtx[row][i*9+k+81] = 1;
                mtx[row][j*9+k+162] = 1;
                mtx[row][sub[i][j]*9+k+243] = 1;
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

inline void remove(int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i]) {
        for (int j = R[i]; j != i; j = R[j]) {
            U[D[j]] = U[j];  D[U[j]] = D[j];  S[CH[j]]--;
        }
    }
}

inline void resume(int c)
{
    L[R[c]] = c;
    R[L[c]] = c;
    for (int i = U[c]; i != c; i = U[i]) {
        for (int j = L[i]; j != i; j = L[j]) {
            U[D[j]] = j;  D[U[j]] = j;  S[CH[j]]++;
        }
    }
}

int dance()
{
    if (R[head] == head) {
        if (ans == 0) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    ansMap[i][j] = map[i][j];
                }
            } 
        }
        return ++ans;
    }
    int i, j, k, c, min = oo;
    for (j = R[head]; j != head; j = R[j]) {
        if (S[j] < min) {
            min = S[j];  c = j;
        }
    }
    remove(c);
    for (i = D[c]; i != c; i = D[i]) {
        k = RH[i];
        map[k/9/9][(k/9)%9] = (k % 9) + 1;
        for (j = R[i]; j != i; j = R[j]) {
            remove(CH[j]);
        }
        if (dance() >= 2) {
            return 2;
        }
        for (j = L[i]; j != i; j = L[j]) {
            resume(CH[j]);
        }
        map[k/9/9][(k/9)%9] = 0;
    }
    resume(c);
    return 0;
}

inline bool hasWall(int x, int y, int d)
{
    int tmp = map[x][y] / 16;
    return tmp & (1 << d);
}

void dfs(int x, int y, int id)
{
    if (sub[x][y] != -1) {
        return ;
    }
    sub[x][y] = id;
    if (!hasWall(x, y, 0)) {
        dfs(x - 1, y, id);
    }
    if (!hasWall(x, y, 1)) {
        dfs(x, y + 1, id); 
    }
    if (!hasWall(x, y, 2)) {
        dfs(x + 1, y, id);
    }
    if (!hasWall(x, y, 3)) {
        dfs(x, y - 1, id);
    }
}

int main()
{
    totRow = 9*9*9, totCol = 9*9*4;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                scanf("%d", &map[i][j]);
            } 
        }
        memset(sub, -1, sizeof(sub));
        int id = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (sub[i][j] == -1) {
                    dfs(i, j, id);
                    id++;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                map[i][j] %= 16;
            }
        }
        initMtx();
        build();
        ans = 0;
        dance();
        
        printf("Case %d:\n", cas);
        if (ans == 0) {
            printf("No solution\n");
        } else if (ans > 1) {
            printf("Multiple Solutions\n");
        } else {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    printf("%d", ansMap[i][j]);
                }
                printf("\n");
            } 
        }
    }
    return 0;
}

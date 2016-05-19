#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/******* Token **********/
const int C[3] = {1, 2, 4};
const int T[3][4][4][2] = {
    {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {}, {}, {}}, 
    {{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, {}, {}},
    {{{0, 0}, {0, 1}, {1, 0}, {2, 0}}, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 1}, {1, 1}, {2, 0}, {2, 1}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}}}
};

void put (const int a[4][2]) {
    int g[4][4];
    memset(g, 0, sizeof(g));

    for (int i = 0; i < 4; i++)
        g[a[i][0]][a[i][1]] = 1;

    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++)
            printf("%c", g[j][i] ? '#' : '.');
        printf("\n");
    }
    printf("\n");
}
/************************/

const int maxn = 1005;

int N, M, P, B[maxn], G[15][15];
char order[maxn];

bool judge (int x, int y, const int t[4][2]) {
    for (int i = 0; i < 4; i++) {
        int p = x + t[i][0];
        int q = y + t[i][1];
        if (G[p][q])
            return false;
    }
    return true;
}

void tag (int x, int y, const int t[4][2]) {
    for (int i = 0; i < 4; i++) {
        int p = x + t[i][0];
        int q = y + t[i][1];
        G[p][q] = 1;
    }
}

void play(int t) {
    int x = 4, y = 9, c = 0;
    while (P < M) {
        if (order[P] == 'w') {
            if (judge(x, y, T[t][(c + 1) % C[t]]))
                c = (c + 1) % C[t];
        } else if (order[P] == 'a') {
            if (judge(x - 1, y, T[t][c]))
                x = x - 1;
        } else if (order[P] == 's') {
            if (judge(x, y - 1, T[t][c]))
                y = y - 1;
        } else if (order[P] == 'd') {
            if (judge(x + 1, y, T[t][c]))
                x = x + 1;
        }
        P++;

        if (!judge(x, y - 1, T[t][c]))
            break;
        y = y - 1;
    }
    tag(x, y, T[t][c]);
}

int remove () {
    int ret = 0;
    for (int j = 1; j <= 9; j++) {
        bool flag = true;
        for (int i = 1; i <= 9; i++) {
            if (G[i][j] == 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ret++;
            for (int x = j; x < 12; x++) {
                for (int i = 1; i <= 9; i++)
                    G[i][x] = G[i][x+1];
            }
            j--;
        }
    }
    return ret;
}

int solve () {
    scanf("%d%s", &N, order);
    P = 0;
    M = strlen(order);

    memset(G, 0, sizeof(G));
    for (int i = 0; i < 15; i++)
        G[i][0] = G[0][i] = G[10][i] = -1;

    int ret = 0, t;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &t);
        play(t);
        ret += remove();
    }
    return ret;
}

int main () {
    int cas;
    scanf("%d", &cas);
    for (int kcas = 1; kcas <= cas; kcas++) {
        printf("Case %d: %d\n", kcas, solve ());
    }
    return 0;
}

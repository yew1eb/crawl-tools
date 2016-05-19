#include <cstdio>
#include <cstring>
using namespace std;
#define INF 10000
const int maxn = 201;
int r[maxn][maxn];

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset (r, INF, sizeof(r));
        int x, y, v;
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &v);
            if (r[x][y] > v)
                r[x][y] = r[y][x] = v;
        }//for
        for (int i = 0; i < n ;i++)
            r[i][i] = 0;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (r[i][k] + r[k][j] < r[i][j])
                        r[i][j] = r[j][i] = r[i][k] + r[k][j];
                }//for
        scanf("%d%d", &x, &y);
        if (r[x][y] < INF)
            printf("%d\n", r[x][y]);
        else
            printf("-1\n");
    }//while
    return 0;
}//hehe
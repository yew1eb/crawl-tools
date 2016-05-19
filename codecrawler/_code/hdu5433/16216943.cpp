#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define fuck printf("fuck")
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)
using namespace std;
typedef long long LL;

const int MX = 50 + 5;
const int INF = 0x3f3f3f3f;

int dist[][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
int Sx, Sy, Ex, Ey;
double d[MX][MX][MX];
char S[MX][MX];

int main() {
    int T, m, n, w; //FIN;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &m, &n, &w);
        for(int i = 1; i <= m; i++) {
            scanf("%s", S[i] + 1);
        }
        scanf("%d%d%d%d", &Sx, &Sy, &Ex, &Ey);
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 0; k <= w; k++) {
                    d[i][j][k] = INF;
                }
            }
        }

        d[Sx][Sy][w] = 0;
        for(int k = w; k >= 2; k--) {
            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    if(d[i][j][k] == INF) continue;
                    for(int t = 0; t < 4; t++) {
                        int nx = i + dist[t][0];
                        int ny = j + dist[t][1];
                        if(nx < 1 || nx > m || ny < 1 || ny > n || S[nx][ny] == '#') continue;
                        double value = abs(S[i][j] - S[nx][ny]) * 1.0 / k;
                        d[nx][ny][k - 1] = min(d[nx][ny][k - 1], d[i][j][k] + value);
                    }
                }
            }
        }

        double ans = INF;
        for(int k = 1; k <= w; k++) {
            ans = min(ans, d[Ex][Ey][k]);
        }
        if(ans == INF) printf("No Answer\n");
        else printf("%.2lf\n", ans);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;

int n, m;
int g[MAXN][MAXN];

int deal(int x, int y) {
    int sum = 1;
    if (g[x][y - 1] == 1)
        sum *= 2;
    if (g[x][y + 1] == 1)
        sum *= 2;
    if (g[x - 1][y] == 1)
        sum *= 2;
    if (g[x + 1][y] == 1)
        sum *= 2;
    return sum;
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &m);         
        if (n == 1 && m == 1) {
            printf("1\n"); 
            continue; 
        }
        memset(g, 0, sizeof(g));
        int flag = 1;
        if (m % 2 == 1) {
            for (int i = 1; i <= n; i++) 
                for (int j = 1; j <= m; j++) {
                    g[i][j] = flag; 
                    flag = -flag; 
                } 
        }
        else {
            for (int i = 1; i <= n; i++) { 
                for (int j = 1; j <= m; j++) {
                    g[i][j] = flag; 
                    flag = -flag; 
                }
                flag = -flag;
            }
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) 
                if (g[i][j] == -1)
                    ans += deal(i, j); 

        printf("%lld\n", ans);   
    }
    return 0;
}
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<bitset>
using namespace std;
#define M 260

int T, top;
int ans[M] = { 1, 5, 6, 3, 6, 3, 7, 4, 7, 8, 4, 5, 4, 5, 4, 1, 6, 3, 7, 4, 7, 4,
        9, 7, 8, 8, 7, 5, 7, 5, 7, 4, 7, 8, 4, 5, 8, 8, 7, 5, 8, 9, 5, 6, 8, 8,
        5, 5, 4, 5, 4, 1, 7, 5, 7, 4, 8, 8, 5, 5, 5, 7, 6, 4, 7, 8, 8, 8, 4, 5,
        7, 5, 8, 9, 8, 8, 5, 6, 5, 5, 4, 5, 7, 5, 4, 1, 7, 4, 8, 8, 5, 7, 5, 5,
        6, 4, 8, 9, 8, 8, 8, 8, 5, 7, 11, 9, 8, 9, 8, 9, 8, 8, 5, 6, 5, 5, 5, 5,
        6, 4, 8, 9, 8, 8, 8, 8, 8, 7, 8, 9, 9, 9, 9, 9, 10, 9, 5, 7, 6, 6, 6, 6,
        7, 6, 9, 9, 10, 9, 10, 9, 10, 10, 7, 6, 7, 7, 7, 7, 9, 7, 5, 7, 6, 6, 7,
        6, 7, 7, 5, 6, 2, 3, 6, 6, 4, 3, 6, 6, 7, 6, 7, 7, 9, 7, 6, 6, 4, 3, 7,
        7, 7, 6, 5, 7, 7, 6, 6, 6, 7, 7, 5, 6, 6, 6, 2, 3, 4, 3, 6, 6, 7, 7, 7,
        6, 9, 7, 6, 6, 7, 7, 4, 3, 7, 6, 5, 6, 6, 6, 6, 6, 7, 7, 8, 9, 5, 6, 5,
        6, 2, 5, 2, 3, 4, 3, 4, 3, 7, 6, 5, 6, 2, 5, 2, 5, 4, 1 };
int now[M], vis[M];

bool dfs(int f, int x, int floor) {
    if (vis[x])
        return true;
    if (f == floor)
        return false;
    for (int i = 0; i < top; i++) {
        for (int j = i + 1; j < top; j++) {
            int go = ((~(now[i] & now[j])) & 255);
            if (!vis[go]) {
                vis[go] = 1;
                now[top++] = go;
                if (dfs(f + 1, x, floor))
                    return true;
                vis[go] = 0;
                top--;
            }
        }
    }
    return false;
}

void init() {
    top = 5;
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[255] = vis[15] = vis[51] = vis[85] = 1;
}

void pre() {
    int i, j, k;
    now[0] = 0;
    now[1] = 255;
    now[2] = 15;
    now[3] = 51;
    now[4] = 85;
    for (i = 105; i < 256; i++) {
        for (k = 0, j = 0; !k; j++) {
            init();
            if (dfs(0, i, j))
                k = j + 1;
        }
        ans[i] = k;
        cout << i << " " << ans[i] << endl;
    }
}

void maketable() {
    int i, j, k = 256;
    while (k--) {
        scanf("%d %d", &i, &j);
        ans[i] = j;
    }
    printf("{");
    for (i = 0; i < 256; i++)
        printf("%d,", ans[i]);
    printf("}");
}

int main() {
    int k, i;
    char f[10];
    //pre();
    //maketable();
    scanf("%d", &T);
    while (T--) {
        scanf("%s", f);
        k = 0;
        for (i = 0; i < 8; i++) {
            k <<= 1;
            if (f[i] == '1')
                k |= 1;
        }
        printf("%d\n", ans[k]);
    }
    return 0;
}

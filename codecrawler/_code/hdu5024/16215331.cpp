/************************************************************************
    > File Name: 1003.cpp
    > Author: Bslin
    > Mail: Baoshenglin1994@gmail.com
    > Created Time: 2014å¹´09æ20æ¥ ææå­ 12æ¶43å13ç§
 ************************************************************************/

#include <stdio.h>

char map[110][110];
int dir[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int n;

bool inmap(int x, int y) {
    if(x >= 0 && x < n && y >= 0 && y < n)
        return true;
    return false;
}

int togo(int x, int y, int d1, int d2) {
    int nowx, nowy, res;
    res = 1;
    nowx = x + dir[d1][0];
    nowy = y + dir[d1][1];
    while(inmap(nowx, nowy) && map[nowx][nowy] == '.') {
        nowx = nowx + dir[d1][0];
        nowy = nowy + dir[d1][1];
        res ++;
    }
    nowx = x + dir[d2][0];
    nowy = y + dir[d2][1];
    while(inmap(nowx, nowy) && map[nowx][nowy] == '.') {
        nowx = nowx + dir[d2][0];
        nowy = nowy + dir[d2][1];
        res ++;
    }
    return res;
}

int dfs(int x, int y) {
    int res, tmp;
    res = 0;
    // 0: l  1: lu  2: u  3: ru  4: r  5: rd  6: d  7: ld
    tmp = togo(x, y, 0, 2);
    if(tmp > res) res = tmp;
    tmp = togo(x, y, 0, 6);
    if(tmp > res) res = tmp;
    tmp = togo(x, y, 4, 2);
    if(tmp > res) res = tmp;
    tmp = togo(x, y, 4, 6);
    if(tmp > res) res = tmp;
    tmp = togo(x, y, 1, 3);
    if(tmp > res) res = tmp;
    tmp = togo(x, y, 1, 7);
    if(tmp > res) res = tmp;
    tmp = togo(x, y, 5, 3);
    if(tmp > res) res = tmp;
    tmp = togo(x, y, 5, 7);
    if(tmp > res) res = tmp;
    return res;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int i, j;
    int ans, tmp;
    while(~scanf("%d", &n), n) {
        for (i = 0; i < n; ++i) {
            scanf("%s", map[i]);
        }
        ans = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if(map[i][j] == '.') {
                    tmp = dfs(i, j);
                    if(tmp > ans) ans = tmp;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

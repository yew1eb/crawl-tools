#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 1111;
char map[N][N];
bool r[N], c[N];

int main()
{
    int t, n, i, j, m, x, y, cas, ans;
    scanf("%d", &t);
    for(cas = 1; cas <= t; cas++)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%s", map[i]);

        scanf("%d", &m);
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for(i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            r[--x] = !r[x];
            c[--y] = !c[y];
        }
        ans = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if((r[i] + c[j] != 1 && map[i][j] == 'w') || (r[i] + c[j] == 1 && map[i][j] == 'b'))
                    ans++;
        printf("Case #%d: %d\n", cas, ans);
    }
}
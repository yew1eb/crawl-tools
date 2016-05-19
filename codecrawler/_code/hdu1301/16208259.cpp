#include <stdio.h>
#include <string.h>
#define maxn 28

int map[maxn][maxn];
bool vis[maxn];

void Prim(int n)
{
    int i, j, len = 0, tmp, count = 0, u;
    vis[0] = 1;
    while(count < n - 1){
        for(i = 0, tmp = -1; i < n; ++i){
            if(!vis[i]) continue;
            for(j = 0; j < n; ++j)
                if(map[i][j] != -1 && !vis[j] && (map[i][j] < tmp || tmp == -1)){
                    tmp = map[i][j]; u = j;
                }
        }
        if(tmp != -1){
            ++count; vis[u] = 1;
            len += tmp;
        }
    }
    printf("%d\n", len);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, m, a, b, count, len;
    char node[2];
    while(scanf("%d", &n), n){
        memset(map, -1, sizeof(map));
        memset(vis, 0, sizeof(vis));
        m = n - 1;
        while(m--){
            scanf("%s%d", node, &count);
            a = node[0] - 'A';
            while(count--){
                scanf("%s%d", node, &len);
                b = node[0] - 'A';
                map[a][b] = map[b][a] = len;
            }
        }
        Prim(n);
    }
    return 0;
}

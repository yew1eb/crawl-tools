#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e6;

int vis[MAXN];
int n;    

int main() {
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        int n;    
        scanf("%d", &n);
        memset(vis, 0, sizeof(vis));

        int a, max = 0, cnt = 0, num = 0; 
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            a = 10000 - pow((100 - a), 2);
            if (!vis[a]) cnt++;
            if (max < a) max = a;
            vis[a]++; 
            if (num < vis[a]) num = vis[a];
        }

        printf("Case #%d:\n", t++);
        if (cnt * num == n && cnt > 1) {
            printf("Bad Mushroom\n");  
            continue;
        }

        int flag = 1;
        for (int i = 0; i <= max; i++) {
            if (vis[i] == num) {
                if (flag) {
                    printf("%d", i);
                    flag = 0;
                }
                else
                    printf(" %d", i);
            }
        } 
        printf("\n"); 
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 9;

int que[maxn], pre[maxn], pos[maxn], rec[maxn];
bool app[maxn];
int cnt = 0;
int a[17] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7};
int b[17] = {2, 3, 4, 3, 5, 6, 4, 5, 6, 7, 6, 7, 6, 8, 7, 8, 8};

void check() {
    for (int i = 0; i < 17; i++)
        if (pos[a[i]] - pos[b[i]] == 1 || pos[b[i]] - pos[a[i]] == 1)
            return;
    if (cnt++ > 1)
        return;
    for (int i = 1; i <= 9; i++)
        rec[i] = pos[i];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        memset(app, 0, sizeof(app));
        for (int j = 1; j <= 8; j++) {
            scanf("%d", &pre[j]);
            pos[j] = pre[j];
            app[pre[j]] = true;
        }
        int t = 0;
        for (int j = 1; j <= 8; j++)
            if (!app[j])
                que[t++] = j;
        do {
            int p = 0;
            for (int j = 1; j <= 8; j++) {
                if (pre[j] == 0)
                    pos[j] = que[p++];
//                printf("%d ", pos[j]);
            }
//            printf("\n");
            check();
        } while (next_permutation(que, que + t));
        printf("Case %d:", i);
        if (cnt == 1)
            for (int j = 1; j <= 8; j++)
                printf(" %d", rec[j]);
        else if (cnt > 1)
            printf(" Not unique");
        else
            printf(" No answer");
        printf("\n");
    }
    return 0;
}
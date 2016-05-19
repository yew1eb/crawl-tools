#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
struct Node{
    int h, d;
    bool operator < (const Node &rhs)const{
        return h != rhs.h ? h > rhs.h : d < rhs.d;
    }
}apple[MAXN];
int arr[MAXN<<1][MAXN<<1];
int MAX;
inline int lowbit (int x){
    return x & -x;
}
void Modify (int x, int y, int d){
    while (y < MAX){
        arr[x][y] = max(arr[x][y], d);
        y += lowbit(y);
    }
}
int query (int x, int y){
    int res = 0;
    while (y){
        res = max(arr[x][y], res);
        y -= lowbit(y);
    }
    return res;
}
int lsh[MAXN << 1], lshtot, tmp[MAXN << 1];
int main()
{
    int T, n;
    scanf ("%d", &T);
    while (T--){
        scanf ("%d", &n);
        lshtot = 0;
        for (int i = 0; i < n; i++){
            scanf ("%d%d", &apple[i].h, &apple[i].d);
            lsh[lshtot++] = apple[i].d;
        }
        sort (apple, apple+n);
        sort (lsh, lsh+lshtot);
        lshtot = unique(lsh, lsh+lshtot) - lsh;
        for (int i = 0; i < n; i++){
            apple[i].d = lower_bound(lsh, lsh+lshtot, apple[i].d) - lsh + 2;
        }
        MAX = lshtot + 5;
        memset(arr, 0, sizeof (arr));
        for (int i = 0; i < n; i++){
            for (int j = 2; j <= lshtot+1; j++){
                tmp[j] = query(j, apple[i].d);
            }
            for (int j = 2; j <= lshtot+1; j++){
                Modify(apple[i].d, j, tmp[j]+1);
                Modify(j, apple[i].d, tmp[j]+1);
            }
        }
        int ans = 0;
        for (int i = 1; i <= lshtot+1; i++){
            ans = max(ans, query(i, lshtot+1));
        }
        printf("%d\n", ans);
    }
    return 0;
}
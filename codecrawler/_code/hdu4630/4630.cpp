#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

//线段树 + 离线处理

const int V = 50000 + 5;
typedef struct node {
    int l, r, index;
};
node nod[V];
int sum[V][99], sum_top[V], last[V];
int p[V * 3], first_number_index, ans[V];
int n, m, T;
bool cmp(node a, node b) {
    if(a.r < b.r)
        return true;
    return false;
}
void build(int N) {
    int nn = 1;
    int r = 2;
    while(r < 2 * N) {
        nn++;
        r *= 2;
    }
    first_number_index = 1 << (nn - 1);
    memset(p, 0, sizeof(p));
}
void Update(int index, int num) {
    p[index] = num;
    while(index != 0) {
        index >>= 1;
        p[index] = max(p[index << 1], p[(index << 1) | 1]);
    }
}
int Query(int a, int b) {
    int Max = 0;
    while(a <= b) {
        int temp = 1;
        int index = first_number_index + a - 1;
        while(index % (2 * temp) == 0 && a + (2 * temp) - 1 <= b)
            temp *= 2;
        Max = max(Max, p[index / temp]);
        a += temp;
    }
    return Max;
}
int main() {
    int i, j, k;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        build(n);
        memset(sum_top, 0, sizeof(sum_top));
        memset(last, 0, sizeof(last));
        for(i = 1; i <= n; ++i) {
            int temp;
            scanf("%d", &temp);
            for(j = 1; j <= (int) sqrt(temp * 1.0); ++j)
                if(temp % j == 0) {
                    sum[i][sum_top[i]++] = temp / j;
                    if(j * j != temp)
                        sum[i][sum_top[i]++] = j;
                }
        }
        scanf("%d", &m);
        for(i = 0; i < m; ++i) {
            scanf("%d%d", &nod[i].l, &nod[i].r);
            nod[i].index = i;
        }
        int k = 0;
        sort(nod, nod + m, cmp);
        for(i = 1; i <= n && k < m; ++i) {
            for(j = 0; j < sum_top[i]; ++j) {
                int pre = sum[i][j];
                if(last[pre] > 0) {
                    int a = last[pre];
                    int index = first_number_index + a - 1;
                    if(p[index] < pre)
                        Update(index, pre);
                }
                last[pre] = i;
            }
            while(nod[k].r == i) {
                ans[nod[k].index] = Query(nod[k].l, nod[k].r);
                k++;
            }
        }
        for(i = 0; i < m; ++i)
            printf("%d\n", ans[i]);
    }
}

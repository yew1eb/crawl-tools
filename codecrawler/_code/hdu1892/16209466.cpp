#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

#define LEN 1002
#define MIN(a,b) (a<b?a:b)

int tree[LEN+1][LEN+1];

int lowbit(int x) {
    return x & (-x);
}

void update(int x,int y, int val) {
    for(int i = x; i <= LEN; i += lowbit(i)) {
        for(int j = y; j <= LEN; j += lowbit(j)) {
            tree[i][j] += val;
        }
    }
}

int query(int x, int y) {
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        for(int j = y; j > 0; j -= lowbit(j)) {
            sum += tree[i][j];
        }
    }
    return sum;
}

int getans(int x, int y) {
    return query(x, y) + query(x-1, y-1) - query(x-1, y) - query(x, y-1);
}

int main() {
    int t, n;
    scanf("%d", &t);
    for(int cases = 1; cases <= t; cases++) {
        printf("Case %d:\n", cases);
        char cmd[3];
        int i, j;
        scanf("%d", &n);
        memset(tree, 0, sizeof(tree));
        for(i = 1; i <= LEN; i++) {
            for(j = 1; j <= LEN; j++) {
                update(i, j, 1);
            }
        }
        
        for(i = 0; i < n; i++) {
            int x1, y1, x2, y2, n;
            scanf("%s", cmd);
            if('S' == cmd[0]) {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                int tmp;
                if(x1 > x2) {
                    tmp = x1;
                    x1 = x2;
                    x2 = tmp;
                }
                if(y1 > y2) {
                    tmp = y1;
                    y1 = y2;
                    y2 = tmp;
                }
                int ans = query(x2+1, y2+1) - query(x1, y2+1) - query(x2+1, y1) + query(x1, y1);
                printf("%d\n", ans);
            }
            else if('A' == cmd[0]) {
                scanf("%d%d%d", &x1, &y1, &n);
                update(x1+1, y1+1, n);
            }
            else if('D' == cmd[0]){
                scanf("%d%d%d", &x1, &y1, &n);
                int n1 = getans(x1+1, y1+1);
                n = MIN(n, n1);
                update(x1+1, y1+1, -n);
            }
            else if('M' == cmd[0]) {
                scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
                int n1 = getans(x1+1, y1+1);
                n = MIN(n, n1);
                update(x1+1, y1+1, -n);
                update(x2+1, y2+1, n);
            }
        }
    }
    return 0;
}

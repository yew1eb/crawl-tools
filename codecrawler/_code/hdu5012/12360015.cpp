#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <memory.h>
#include <numeric>
#include <utility>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>

#define MX 1000000
using namespace std;

int rot[4][10] = {{2, 1, 3, 0, 2}, {3, 1, 2, 0, 3}, {4, 1, 5, 0, 4}, {5, 1, 4, 0, 5}};

int que[MX];
int chk[MX], T;

int hash(int a[]) {
    
    int i, v = 1, s = 0;
    for (i = 0; i < 6; i ++) {
        s += a[i] * v;
        v *= 7;    
    }    
    return s;
}

void get(int a[], int u) {
    
    int i;
    for (i = 0; i <= 5; i ++) {
        a[i] = u % 7;
        u /= 7;    
    }
}

int main() {
    
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int i, k, S, E, u, dp;
    int a[10], b[10], c[10], d[10], e[10];
    while (scanf("%d", &a[0]) == 1) {
        
        for (i = 1; i < 6; i ++) scanf("%d", a + i);
        for (i = 0; i < 6; i ++) scanf("%d", b + i);
        
        
        T ++;
        S = hash(a);
        E = hash(b);
        chk[S] = T;

        int bf = 0;
        int st = 0, en = 0;
        que[en ++] = S; que[en ++] = 0;
        while (st < en) {
            
            u = que[st ++]; dp = que[st ++];

            if (u == E) {
                printf("%d\n", dp);
                bf = 1;
                break;    
            }
            get(c, u);
            for (i = 0; i < 4; i ++) {
                if (i < 2) {
                    d[4] = c[4], d[5] = c[5];
                    for (k = 1; k <= 4; k ++) d[rot[i][k]] = c[rot[i][k - 1]];    
                } else {
                    d[2] = c[2], d[3] = c[3];
                    for (k = 1; k <= 4; k ++) d[rot[i][k]] = c[rot[i][k - 1]];
                }
                int v = hash(d);
                if (chk[v] == T) continue;
                chk[v] = T;
                que[en ++] = v; que[en ++] = dp + 1;
            }    
        }
        if (!bf) printf("-1\n");
    }
    return 0;    
}
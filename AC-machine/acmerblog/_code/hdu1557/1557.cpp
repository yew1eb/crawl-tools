/*
 * hdu1557/win.cpp
 * Created on: 2013-6-1
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
const int MAXN = 22;
int data[MAXN], result[MAXN], total;
int indexs[MAXN];
double half;

void initindexs() {
    for(int i = 0; i < MAXN; i++) {
        indexs[i] = 1 << i;
    }
}

void work(int state, int n) {
    int to = 0;
    for(int i = 0; i < n; i++) {
        if(state & indexs[i]) {
            to += data[i];
        }
    }
    if(to <= half) {
        return ;
    }
    for(int i = 0; i < n; i++) {
        if((state & indexs[i]) && to - data[i] <= half) {
            result[i]++;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    int T, n;
    initindexs();
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(result, 0, sizeof(result));
        total = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
            total += data[i];
        }
        half = total / 2.0;
        int max_state = 1 << n;
        for(int state = 0; state < max_state; state++) {
            work(state, n);
        }
        printf("%d", result[0]);
        for(int i = 1; i < n; i++) {
            printf(" %d", result[i]);
        }
        putchar('\n');
    }
    return 0;
}
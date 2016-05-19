/* 
 * File:   main.cpp
 * Author: hit-acm
 *
 * Created on 2012年8月27日, 下午7:40
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 65;
int a[3][MAXN];
int size[3];
unsigned long long ans[MAXN];

void init() {
    ans[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        ans[i] = 2 * ans[i - 1] + 1;
    }
}

void DFS(int n, unsigned long long m, int s, int e, int mid) {
    if (n <= 0) {
        return;
    }
    if (m < ans[n - 1]) {
        DFS(n - 1, m, s, mid, e);
    } else if (m == ans[n - 1]) {
        size[s] -= n - 1;
        for (int i = 1; i < n; i++) {
            a[mid][size[mid]++] = a[s][size[s] + i - 1];
        }
    } else {
        a[e][size[e]++] = n;
        size[s] -= n;
        for (int i = 1; i < n; i++) {
            a[mid][size[mid]++] = a[s][size[s] + i];
        }
        DFS(n - 1, m - ans[n - 1] - 1, mid, e, s);
    }
}

void get_result(int n, unsigned long long m) {
    for (int i = 0; i < 3; i++) {
        size[i] = 0;
    }
    size[0] = n;
    for (int i = 0; i < n; i++) {
        a[0][i] = n - i;
    }
    DFS(n, m, 0, 2, 1);
    for (int i = 0; i < 3; i++) {
        printf("%d", size[i]);
        for (int j = 0; j < size[i]; j++) {
            printf(" ");
            printf("%d", a[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int T;
    int n;
    unsigned long long m;
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d%llu", &n, &m);
        get_result(n, m);
    }
    return 0;
}
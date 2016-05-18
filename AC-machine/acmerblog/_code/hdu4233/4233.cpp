#include <stdio.h>
#include <string.h>
#define N 100005
#define INF 1999999999

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int max(int a, int b) {
    return a > b ? a : b;
}

struct Edge {
    int index;
    int next;
};

Edge edge[N];
int head[N];

void addEdge(int a, int b, int ie) {
    edge[ie].index = b;
    edge[ie].next = head[a];
    head[a] = ie;
}

int K;
int money[N];
int son[N];

void dfs1(int index) {//calc the sons of node index
    son[index] = 1;
    for (int i = head[index]; i != -1; i = edge[i].next) {
        int j = edge[i].index;
        dfs1(j);
        son[index] += son[j];
    }
}

int *dp[N];

inline void newInt(int index) {
    int KK = min(K, son[index]);
    dp[index] = new int[KK + 1];
    dp[index][0] = 0;
    for (int k = 1; k <= KK; k++) {
        dp[index][k] = -1;
    }
}

void dfs2(int index, int parent) {
    for (int i = head[index]; i != -1; i = edge[i].next) {
        int j = edge[i].index;
        dfs2(j, index);
    }
    if (dp[index] == 0) {
        newInt(index);
    }
    dp[index][1] = max(dp[index][1], money[index]);
    //dp should be ok here
    int KK = min(K, son[index]);
    while (dp[index][KK] == -1) {
        KK--;
    }
    /*printf ("%d [", index);
    for (int k = 1; k <= KK; k++) {
        printf ("%d ", dp[index][k]);
    }
    puts("]");*/
    if (dp[parent] == 0) {
        newInt(parent);
    }
    int PP = min(K, son[parent]);
    int p = PP;
    while (dp[parent][p] == -1) {
        p--;
    }
    for (p = min(PP, p + KK); p > 0; p--) {
        /*for (int k = 1; k <= KK && k <= p; k++) {
            if (dp[parent][p-k] == -1) {
                continue;
            }
            dp[parent][p] = max(dp[parent][p], dp[parent][p-k] + dp[index][k]);
        }*/
        int l = 1;
        int r = min(KK, p);
        while (l < r) {
            int m1 = (l + r) >> 1;
            int m2 = (r + m1) >> 1;
            int t1 = dp[parent][p-m1] + dp[index][m1];
            int t2 = dp[parent][p-m2] + dp[index][m2];
            if (t1 < t2) {
                l = m1 + 1;
            } else {
                r = m2 - 1;
            }
        }
        for (int k = max(1, l-2); k <= KK && k <= p && k <= l+2; k++) {
            if (dp[parent][p-k] == -1) {
                continue;
            }
            dp[parent][p] = max(dp[parent][p], dp[parent][p-k] + dp[index][k]);
        }
    }
    delete dp[index];
}

int main () {
    int n;
    while (scanf ("%d %d", &n, &K) != EOF && n && K) {
        memset(head, -1, sizeof (head));
        for (int i = 1; i <= n; i++) {
            int p;
            scanf ("%d %d", &p, &money[i]);
            addEdge(p, i, i-1);
        }
        if (n < K) {
            puts("0");
            continue;
        }
        int root = edge[head[0]].index;
        dfs1(0);
        /*for (int i = 1; i <= n; i++) {
            printf ("%d ", son[i]);
        }
        puts("");*/
        memset(dp, 0, sizeof (dp));
        dfs2(root, 0);
        if (dp[0][K] == -1) {
            puts("0");
            continue;
        }
        /*for (int i = 1; i <= KK; i++) {
            printf ("%d ", dp[0][i]);
        }
        puts("");*/
        printf ("%d\n", dp[0][K]);
    }
    return 0;
}
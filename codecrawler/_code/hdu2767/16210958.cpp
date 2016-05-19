/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2767.cpp
*  Create Date: 2014-07-30 14:30:55
*  Descripton:  tarjan
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <stack>
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 20010;

stack<int> S;
vector<int> G[N];
int dfn[N], low[N], sccno[N], tclock, scccnt;
int id[N], od[N];
int t, n, m, x, y;

void tarjan(int u) {
    dfn[u] = low[u] = ++tclock;
    S.push(u);

    int sz = G[u].size();
    repf (i, 0, sz - 1) {
        int v = G[u][i];
        if (!dfn[v]) {                // v not visited
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!sccno[v]) {        // v not belong to scc, so it was in the stack
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        scccnt++;
        int v = -1;
        while (v != u) {
            v = S.top();
            S.pop();
            sccno[v] = scccnt;
        }
    }
}

void find_scc() {
    tclock = scccnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sccno, 0, sizeof(sccno));

    repf (i, 1, n) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}

void read() {
    scanf("%d%d", &n, &m);

    repf (i, 0, n)
        G[i].clear();

    while (m--) {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
    }
}

int solve() {
    if (scccnt == 1)
        return 0;
    memset(id, 0, sizeof(id));
    memset(od, 0, sizeof(od));

    repf (u, 1, n) {
        int sz = G[u].size();
        repf (i, 0, sz - 1) {
            int v = G[u][i];
            if (sccno[u] != sccno[v]) {
                id[sccno[v]]++;
                od[sccno[u]]++;
            }
        }
    }

    int idnum = 0, odnum = 0;
    repf (i, 1, scccnt) {
        idnum += (id[i] == 0);
        odnum += (od[i] == 0);
    }

    return max(idnum, odnum);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        read();
        find_scc();
        printf("%d\n", solve());
    }
    return 0;
}

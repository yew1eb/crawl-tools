#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int ans;

const int SIGMA_SIZE = 26;
const int MAXNODE = 500000 + 100;

struct AhoCorasickAutomata {
    int ch[MAXNODE][SIGMA_SIZE];
    int f[MAXNODE];
    int val[MAXNODE];
    int last[MAXNODE];
    int sz;

    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof ch[0] );
    }

    int idx(char c) {
        return c - 'a';
    }

    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for(int i=0; i<n; ++i) {
            int c = idx(s[i]);
            if(!ch[u][c]) {
                memset(ch[sz], 0, sizeof ch[sz] );
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u]++;
    }

    void print(int j) {
        if(val[j]) {
            ans += val[j];
            val[j] = 0;
            print(last[j]);
        }
    }

    int find(char* T) {
        int n = strlen(T);
        int j = 0;
        for(int i=0; i<n; ++i) {
            int c = idx(T[i]);
            while(j && !ch[j][c]) j = f[j];
            j = ch[j][c];
            if(val[j]) print(j);
            else if(last[j]) print(last[j]);
        }
    }

    void getFail() {
        queue<int> q;
        f[0] = 0;
        for(int c = 0; c <SIGMA_SIZE; ++c) {
            int u = ch[0][c];
            if(u) {
                f[u] = 0;
                q.push(u);
                last[u] = 0;
            }
        }

        while(!q.empty()) {
            int r = q.front();
            q.pop();
            for(int c =0; c<SIGMA_SIZE; ++c) {
                int u = ch[r][c];
                if(!u) continue;
                q.push(u);
                int v = f[r];
                while(v && !ch[v][c]) v = f[v];
                f[u] = ch[v][c];
                last[u] = val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
};

AhoCorasickAutomata ac;

char text[1000001], p[10001][51];
int n, T;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        ac.init();
        for(int i=1; i<=n; ++i) {
            scanf("%s", p[i]);
            ac.insert(p[i], i);
        }

        ac.getFail();
        scanf("%s", text);

        ans = 0;
        ac.find(text);
        printf("%d\n", ans);

    }
    return 0;
}

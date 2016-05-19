#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#include<queue>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define MaxN 1020304

inline int ReadINT()
{
    int num = 0;
    int sign = 1;
    bool skip = false;
    int c = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '-')
        {
            sign = -1;
            skip = true;
        }
        else if(c >= '0' && c <= '9')
        {
            num = num * 10 + c - '0';
            skip = true;
        }
        else if(skip) break;
    }
    return num * sign;
}

inline int ReadOP()
{
    int c = 0;
    while((c = getchar()) != EOF && c != 'A');
    getchar(); getchar();
    return getchar();
}

int v[MaxN], next[MaxN], h[MaxN], bel[MaxN], tot;
void add(int b, int e, int ll) {
    v[++tot] = e; next[tot] = h[b]; h[b] = tot; bel[tot] = ll;
    v[++tot] = b; next[tot] = h[e]; h[e] = tot; bel[tot] = ll;
}

int d[MaxN], fa[111111][19];    
int lca(int x, int y) {
    if (d[x] > d[y]) swap(x,y);
    Cor(i,18,0) if (d[fa[y][i]] >= d[x]) y = fa[y][i];
    if (x == y) return x;
    Cor(i,18,0) if (fa[x][i] != fa[y][i]) {
        x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}


int n,m,q[MaxN], vis[MaxN];
long long addEdge[MaxN], addNode[MaxN],anse[MaxN];
int main() {
    //freopen("C.in","r",stdin);
    int TK = ReadINT();
    For(TTT,1,TK) {
        printf("Case #%d:\n", TTT);
        n = ReadINT();
        m = ReadINT();
        Fill(h,tot = 0);
        For(i,1,n - 1) {
            int b = ReadINT();
            int e = ReadINT();
            add(b,e,i);
        }
        int hd = 0, tl = 1;
        fill(vis, vis + n + 10, 0);
        For(i,0,n + 5) For(j,0,18) fa[i][j] = 0;
        vis[q[1] = 1] = true; d[1] = 1;
        while (hd < tl) {
            int vex = q[++hd];
            for (int z = h[vex]; z; z = next[z]) if (!vis[v[z]]) {
                vis[q[++tl] = v[z]] = true;
                fa[v[z]][0] = vex;
                d[v[z]] = d[vex] + 1;
            }
        }
        For(j,1,18) For(i,1,n) fa[i][j] = fa[fa[i][j - 1]][j - 1];
        fill(addNode, addNode + n + 10, 0);
        fill(addEdge, addEdge + (n * 2) + 10, 0);
        fill(anse, anse + n + 10, 0);
        For(i,1,m) {
            int op = ReadOP();
            int x = ReadINT();
            int y = ReadINT();
            int k = ReadINT();
            int tlca = lca(x,y);
            if (op == '1') {
                addNode[x] += k;
                addNode[y] += k;
                addNode[tlca] -= k;
                if (tlca != 1) addNode[fa[tlca][0]] -= k;
            }
            if (op == '2') {
                addEdge[x] += k;
                addEdge[y] += k;
                addEdge[tlca] -= k * 2;
            }
        }
        Cor(i,tl,1) {
            int vex = q[i];
            int tmp = 0;
            for (int z = h[vex]; z; z = next[z]) if (fa[vex][0] != v[z]) {
                addEdge[vex] += addEdge[v[z]];
                addNode[vex] += addNode[v[z]];
            } else tmp = bel[z];
            if (i != 1) {
                anse[tmp] = addEdge[vex];
            }
        }
        For(i,1,n) {
            printf("%I64d", addNode[i]);
            if (i < n) putchar(' ');
        }
        puts("");
        For(i,1,n - 1) {
            printf("%I64d", anse[i]);
            if (i < n - 1) putchar(' ');
        }
        puts("");
    }
    return 0;    
}
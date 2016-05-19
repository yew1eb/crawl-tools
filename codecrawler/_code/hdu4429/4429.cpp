#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 2005;
struct Node {
    int lx, ly, rx, ry;
    int fath, lson, rson, dep;
}node[maxn];

int find(int x, int y)
{
    int r = 0, t;
    while(1) {
        if(node[r].lson == 0) return r;
        t = node[r].lson;
        if(x >= node[t].lx && x <= node[t].rx && y >= node[t].ly && y <= node[t].ry)
            r = t;
        else r = node[r].rson;
    }
}
int num[maxn];
int get_num(int u)
{
    num[u] = 0;
    if(node[u].lson == 0) return num[u] = 1;
    else {
        num[u] += get_num(node[u].lson);
        num[u] += get_num(node[u].rson);
    }
    return num[u];
}
int main()
{
    //freopen("in", "r", stdin);
    int lx, ly, rx, ry;
    int m, q;
    while(~scanf("%d%d%d%d", &lx, &ly, &rx, &ry)) {
        int root = 0, tol = 1;
        //memset(node, 0, sizeof(node));

        node[root] = (Node){lx, ly, rx, ry, -1, 0, 0, 0};

        scanf("%d%d", &m, &q);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            if(lx > rx) swap(lx, rx);
            if(ly > ry) swap(ly, ry);

            int mx = (lx+rx)/2, my = (ly+ry)/2;
            int pos = find(mx, my);

            int dep = node[pos].dep;
            node[pos].lson = tol;
            node[tol] = (Node){node[pos].lx, node[pos].ly, rx, ry, pos, 0, 0, dep+1};
            tol++;

            node[pos].rson = tol;
            node[tol] = (Node){lx, ly, node[pos].rx, node[pos].ry, pos, 0, 0, dep+1};
            tol++;
        }
        get_num(0);
//        for(int i = 0; i <= tol; ++i) {
//            printf("%d ", num[i]);
//        }
//        puts(" ");
        while(q--) {
            scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
            int g1 = find(lx, ly);
            int g2 = find(rx, ry);
            while(g1 != g2) {
                if(node[g1].dep < node[g2].dep) g2 = node[g2].fath;
                else if(node[g1].dep > node[g2].dep) g1 = node[g1].fath;
                else {
                    g1 = node[g1].fath;
                    g2 = node[g2].fath;
                }
            }
//            printf("%d\n", num[g1]);
            printf("%d\n", m+1 - num[g1]+1);
        }
    }
    return 0;
}

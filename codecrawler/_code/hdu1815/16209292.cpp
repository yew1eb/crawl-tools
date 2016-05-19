#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define N 1010
#define abs(a) ((a) > 0? (a): (-(a))) 

struct cows{
    int x, y;
}C[N], S1, S2, heat[N], like[N];

int n, m, a, b, top, dis_S1_S2;
int S[N], dis_S1[N], dis_S2[N];
bool mark[N];
vector<int> G[N];

void init() {
    scanf("%d%d%d%d", &S1.x, &S1.y, &S2.x, &S2.y);
    dis_S1_S2 = abs(S1.x - S2.x) + abs(S1.y - S2.y);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &C[i].x, &C[i].y);
        dis_S1[i] = abs(C[i].x - S1.x) + abs(C[i].y - S1.y);
        dis_S2[i] = abs(C[i].x - S2.x) + abs(C[i].y - S2.y);
    }

    for (int i = 0; i < a; i++) {
        scanf("%d%d", &heat[i].x, &heat[i].y);
        heat[i].x--; heat[i].y--;
    }

    for (int i = 0; i < b; i++) {
        scanf("%d%d", &like[i].x, &like[i].y); 
        like[i].x--; like[i].y--;
    }
}

bool dfs(int u) {
    if (mark[u ^ 1]) return false;
    if (mark[u]) return true;

    mark[u] = true;
    S[++top] = u;
    for (int i = 0; i < G[u].size(); i++)
        if (!dfs(G[u][i]))
            return false;
    return true;
}

void AddEdge(int x, int valx, int y, int valy) {
    x = 2 * x + valx;
    y = 2 * y + valy;
    G[x].push_back(y);
}

bool judge(int mid) {
    for (int i = 0; i < 2 * m; i++)
        G[i].clear();

    bool flag;
    for (int i = 0; i < m; i++) {
        flag = false;
        //ä¸è½åS1ç¸è¿
        if (dis_S1[i] > mid) {
            AddEdge(i, 0, i, 1);
            flag = true;
        }
        //ä¸è½åS2ç¸è¿
        if (dis_S2[i] > mid) {
            if (flag)
                return false;
            AddEdge(i, 1, i, 0);
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++) {
            //ç¬¬iä¸ªåç¬¬jä¸ªè½å¤åS1ç¸è¿çæåµ
            if (dis_S1[i] <= mid && dis_S1[j] <= mid && dis_S1[i] + dis_S1[j] > mid) {
                    AddEdge(i, 0, j, 1);
                    AddEdge(j, 0, i, 1);
            }
            //ç¬¬iä¸ªåç¬¬jä¸ªè½å¤åS2ç¸è¿çæåµ
            if (dis_S2[i] <= mid && dis_S2[j] <= mid && dis_S2[i] + dis_S2[j] > mid) {
                    AddEdge(i, 1, j, 0);
                    AddEdge(j, 1, i, 0);
            }

            //ç¬¬iä¸ªåS1ç¸è¿ï¼ç¬¬jä¸ªåS2ç¸è¿
            if (dis_S1[i] <= mid && dis_S2[j] <= mid && dis_S1[i] + dis_S2[j] + dis_S1_S2 > mid) {
                    AddEdge(i, 0, j, 0);
                    AddEdge(j, 1, i, 1);
            }
            //ç¬¬iä¸ªåS2ç¸è¿ï¼ç¬¬jä¸ªås1ç¸è¿
            if (dis_S2[i] <= mid && dis_S1[j] <= mid && dis_S2[i] + dis_S1[j] + dis_S1_S2 > mid) {
                    AddEdge(i, 1, j, 1);
                    AddEdge(j, 0, i, 0);
            }
        }

    for (int i = 0; i < a; i++) {
        AddEdge(heat[i].x, 0, heat[i].y, 1);
        AddEdge(heat[i].x, 1, heat[i].y, 0);
        AddEdge(heat[i].y, 0, heat[i].x, 1);
        AddEdge(heat[i].y, 1, heat[i].x, 0);
    }

    for (int i = 0; i < b; i++) {
        AddEdge(like[i].x, 0, like[i].y, 0);
        AddEdge(like[i].x, 1, like[i].y, 1);
        AddEdge(like[i].y, 0, like[i].x, 0);
        AddEdge(like[i].y, 1, like[i].x, 1);
    }

    memset(mark, 0, sizeof(mark));

    for (int i = 0; i < 2 * m; i++) {
        if (!mark[i] && !mark[i ^ 1]) {
            top = 0;
            if (!dfs(i)) {
                while (top) mark[S[top--]] = false;
                if (!dfs(i ^ 1))
                    return false;
            }
        }
    }
    return true;
}

void solve() {
    int l = 0, r = 44444444, mid;
    int ans = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (judge(mid)) {
            ans = mid; 
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
    printf("%d\n", ans);
}

int main() {
    while (scanf("%d%d%d", &m, &a, &b) != EOF) {
        init();
        solve();
    }
    return 0;
}

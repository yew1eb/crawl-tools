#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 50005;

int n, vis[N];
vector<int> save;

struct Point {
    int val, id, rank;
} p[N];

bool cmpv(Point a, Point b) {
    return a.val < b.val;
}

bool cmpid(Point a, Point b) {
    return a.id < b.id;
}

const int INF = 0x3f3f3f3f;

int dp[N];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i].val);
        int pn = 1;
        for (int i = 2; i <= n; i++) {
            if (p[i].val != p[i - 1].val)
                p[++pn] = p[i];
        }
        n = pn;
        for (int i = 1; i <= n; i++)
            p[i].id = i;
        sort(p + 1, p + n + 1, cmpv);
        p[1].rank = 0;
        int s = 0;
        for (int i = 2; i <= n; i++) {
            if (p[i].val != p[i - 1].val)
                ++s;
            p[i].rank = s;
        }
        sort(p + 1, p + n + 1, cmpid);
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        dp[n] = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            if (dp[i] > dp[i + 1]) continue;
            for (int j = i + 1; j <= n; j++) {
                if (vis[p[j].rank] == 0) {
                    save.push_back(p[j].rank);
                    cnt++;
                }
                vis[p[j].rank]++;
                if (dp[i] + cnt * cnt >= dp[n]) break;
                dp[j] = min(dp[j], dp[i] + cnt * cnt);
            }
            for (int i = 0; i < save.size(); i++)
                vis[save[i]] = 0;
            save.clear();
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
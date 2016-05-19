#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100005;

struct Task {
    int x, y;

    bool operator<(const Task &rhs) const {
        if(x == rhs.x)
            return y > rhs.y;
        return x > rhs.x;
    }
} task[N];

int main() {
    int n, m;
    while(cin >> n >> m) {
        multiset<int> S[105];
        LL ans = 0;
        int maxLevel = 0, count = 0;
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            S[y].insert(x);
            maxLevel = max(maxLevel, y);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &task[i].x, &task[i].y);
        }
        sort(task, task + m);
        for(int i = 0; i < m; i++) {
            int x = task[i].x;
            int y = task[i].y;
            for(int j = y; j <= maxLevel; j++) {
                if(S[j].empty())
                    continue;
                multiset<int>::iterator iter = S[j].lower_bound(x);
                if(iter == S[j].end() || *iter < x) {
                    continue;
                } else {
                    count++;
                    ans += 500ll * x + 2ll * y;
                    S[j].erase(iter);
                    break;
                }
            }
        }
        cout << count << " " << ans << endl;
    }
    return 0;
}

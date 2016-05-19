#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int N;
vector<pii> vec;

int main () {
    int cas, x, y;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &N);
        vec.clear();

        for (int i = 0; i < N; i++) {
            scanf("%d%d", &x, &y);
            vec.push_back(make_pair(x, 1));
            vec.push_back(make_pair(y + 1, -1));
        }

        sort(vec.begin(), vec.end());

        int ans = 0, p = 0;
        for (int i = 0; i < vec.size(); i++) {
            p += vec[i].second;
            ans = max(ans, p);
        }
        printf("%d\n", ans);
    }
    return 0;
}

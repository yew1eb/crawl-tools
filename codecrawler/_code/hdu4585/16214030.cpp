#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

//

const int V = 40 + 5;
const int MaxN = 80 + 5;
const int mod = 10000 + 7;
const __int64 INF = 0x7FFFFFFFFFFFFFFFLL;
const int inf = 0x7fffffff;
map<int, int> m;
int n;
int main() {
    int i, j;
    while(scanf("%d", &n), n) {
        m[1000000000] = 1;
        for(i = 0; i < n; ++i) {
            int id, fg, ans;
            scanf("%d%d", &id, &fg);
            m[fg] = id;
            map<int, int>::iterator it = m.find(fg);
            if(it == m.begin())
                ans = (++it)->second;
            else {
                map<int, int>::iterator it1 = it;
                if(abs((++it1)->first - fg) >= abs((--it)->first - fg))
                    ans = it->second;
                else
                    ans = it1->second;
            }
            printf("%d %d\n", id, ans);

        }
        m.clear();
    }
}

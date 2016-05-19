#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

//

const int V = 60000 + 50;
const int inf = 0x7fffffff;
int n, k;
int main() {
    int i, j, q;
    while(~scanf("%d%d", &n, &k)) {
        multiset<int> s[20];
        map<int, int> m[20];
        for(i = 1; i <= n; ++i) {
            int op;
            scanf("%d", &op);
            if(op == 0) {
                int po[10];
                for(j = 0; j < k; ++j)
                    scanf("%d", &po[j]);
                for(j = 0; j < (1 << (k - 1)); ++j) {
                    int sum = po[0];
                    for(q = 0; q < k - 1; ++q) {
                        if(j & (1 << q))
                            sum -= po[q + 1];
                        else
                            sum += po[q + 1];
                    }
                    s[j].insert(sum);
                    m[j][i] = sum;
                }
            }
            else {
                int temp;
                scanf("%d", &temp);
                for(j = 0; j < (1 << (k - 1)); ++j) {
                    if(m[j].size() > 0) {
                        s[j].erase(s[j].find(m[j][temp]));
                        m[j].erase(temp);
                    }
                }
            }
            int Max = 0;
            for(j = 0; j < (1 << (k - 1)); ++j) {
                if(s[j].size() > 0) {
                    multiset<int>::iterator fi = s[j].begin();
                    multiset<int>::iterator se = s[j].end();
                    se--;
                    Max = max(Max, *se - *fi);
                }
            }
            printf("%d\n", Max);
        }
    }
}

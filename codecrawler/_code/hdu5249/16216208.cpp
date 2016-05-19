#include <cstdio>
#include <queue>
#include <set>
using namespace std;
set<int>l, r;
set<int>::iterator it;
queue<int>q;
main() {
    int cas = 1, n;
    while(~scanf("%d", &n)){
        printf("Case #%d:\n", cas++);
        while(!q.empty()) q.pop();
        l.clear(), r.clear();
        while(n--) {
            char str[20];
            scanf("%s", str);
            if(str[0] == 'i') {
                int a;
                scanf("%d", &a);
                q.push(a);
                if(l.size() == r.size()) {
                    if(r.size() == 0 || a > *l.rbegin()) {
                        r.insert(a);
                    }
                    else {
                        r.insert(*l.rbegin());
                        l.erase(*r.begin());
                        l.insert(a);
                    }
                }
                else {
                    if(a > *r.begin()) l.insert(*r.begin()), r.erase(*l.rbegin()), r.insert(a);
                    else l.insert(a);
                }
            }
            else if(str[0] == 'q') printf("%d\n", *r.begin());
            else {
                int a = q.front(); q.pop();
                if(a < *r.begin()) l.erase(a);
                else r.erase(a);
                if(l.size() + 1 < r.size()) l.insert(*r.begin()), r.erase(*l.rbegin());
                else if(l.size() > r.size())r.insert(*l.rbegin()), l.erase(*r.begin());
            }
        }
    }
}
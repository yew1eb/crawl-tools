#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int main()
{
    int n, cas = 0, x;
    int Size;
    char c[10];
    while(~scanf("%d", &n)) {
        printf("Case #%d:\n", ++cas);
        deque<int> Q;
        Size = 0;
        tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pb_tree;
        while(n--) {
            scanf("%s", c);
            if(c[0] == 'i') {
                scanf("%d", &x);
                Q.push_back(x);
                pb_tree.insert(x);
                Size++;
            }else if(c[0] == 'o') {
                pb_tree.erase(Q.front());
                Q.pop_front();
                Size--;
            }else {
                int ans =*pb_tree.find_by_order(Size/2);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}

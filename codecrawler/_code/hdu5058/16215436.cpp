#include<cstdio>
#include<set>
using std::set;
set<int> A, B;
int main() {
    int n, v;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n << 1; i++) {
            scanf("%d", &v);
            if (i < n) A.insert(v);
            else B.insert(v);
        }
        if (A == B) puts("YES");
        else puts("NO");
        A.clear(), B.clear();
    }
    return 0;
}
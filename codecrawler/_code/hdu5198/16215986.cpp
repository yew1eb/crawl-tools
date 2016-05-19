#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define mxn 100020
#define LL long long
#define inf 0x3f3f3f3f
#define MP make_pair


char s[mxn];
int n;
bool check(int l, int r) {
    for(int i = l; i <= r; ++i)
        if(s[i] != s[l]) return 0;
    return 1;
}
int main() {
    while(scanf("%s", s + 1) != EOF) {
        n = strlen(s + 1);
        if(n % 3 != 0) {
            puts("NO");
            continue;
        }
        int x = n / 3 + 1;
        int y = n / 3 * 2 + 1;
        int z = n / 3;
        if(check(1, 1 + z - 1) && check(x, x + z - 1) && check(y, y + z - 1)) {
            if(s[1] != s[x] && s[1] != s[y] && s[x] != s[y])
                puts("YES");
            else
                puts("NO");
        }
        else
            puts("NO");
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 105;
//const int N = 11;
const char S[maxn] = "anniversary";

bool dfs (char* t, int l, int r, int d) {
    if (d >= 3)
        return false;

    for (; t[l]; l++) {
        int v = 0;
        while (t[l+v] && S[r+v] && t[l+v] == S[r+v])
            v++;
        if (S[r+v] == '\0')
            return true;
        if (dfs(t, l+v, r+v, d+1))
            return true;
    }
    return false;
}

int main () {
    int cas;
    char s[maxn];
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", s);
        printf("%s\n", dfs(s, 0, 0, 0) ? "YES" : "NO");
    }
    return 0;
}

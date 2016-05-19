#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1005;

char s[maxn];

int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%s", s);
        int n = strlen(s), ret = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')' && l) {
                l--; ret++;
            } else if (s[i] == '(')
                l++;
        }
        printf("%d\n", ret);
    }
    return 0;
}
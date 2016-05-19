#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define FILE freopen("in","r",stdin)
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)

/*****************************************************************/

char s1[10], s2[10], s3[10];
int p[10];
bool vis[10];
int ans, n;
void check() {
//for (int i = 0; i < n; i++) printf("%d ", p[i]); printf("\n");
 if (strlen(s1) > 1 && p[s1[0] - 65] == 0) return;
 if (strlen(s2) > 1 && p[s2[0] - 65] == 0) return;
 if (strlen(s3) > 1 && p[s3[0] - 65] == 0) return;
 int x1 = 0, x2 = 0, x3 = 0;
 for (int i = 0; s1[i]; i++) x1 = x1 * 10 + p[s1[i] - 65];
 for (int i = 0; s2[i]; i++) x2 = x2 * 10 + p[s2[i] - 65];
 for (int i = 0; s3[i]; i++) x3 = x3 * 10 + p[s3[i] - 65];
 if (x1 + x2 == x3) ans++;
 if (x1 - x2 == x3) ans++;
 if ((LL)x1 * x2 == x3) ans++;
 if (x2 != 0 && x1 % x2 == 0 && x1 / x2 == x3) ans++;
}
void dfs(int k, int x) {
 if (k == n) {
 check();
 return;
 }
 for (int i = 0; i < 10; i++) if (!vis[i]) {
 p[k] = i;
 vis[i] = true;
 dfs(k + 1, i + 1);
 vis[i] = false;
 }
}
void init(char ch) {
 for (int i = 0; s1[i]; i++) if (s1[i] == ch) return;
 for (int i = 0; s2[i]; i++) if (s2[i] == ch) return;
 for (int i = 0; s3[i]; i++) if (s3[i] == ch) return;
 for (int i = 0; s1[i]; i++) if (s1[i] > ch) s1[i]--;
 for (int i = 0; s2[i]; i++) if (s2[i] > ch) s2[i]--;
 for (int i = 0; s3[i]; i++) if (s3[i] > ch) s3[i]--;
 init(ch);
}
bool has(char ch) {
 for (int i = 0; s1[i]; i++) if (s1[i] >= ch) return true;
 for (int i = 0; s2[i]; i++) if (s2[i] >= ch) return true;
 for (int i = 0; s3[i]; i++) if (s3[i] >= ch) return true;
 return false;
}
int main() {
// FILE;
 int T;
 scanf("%d", &T);
 while (T--) {
 scanf("%s%s%s", s1, s2, s3);
 n = 0;
 for (char ch = 'A'; ch <= 'E'; ch++)
 if (has(ch)) {
 n++;
 init(ch);
 }
//printf("%s %s %s\n", s1, s2, s3);
 ans = 0;
 memset(vis, 0, sizeof(vis));
 dfs(0, 0);
 printf("%d\n", ans);
 }
 return 0;
}
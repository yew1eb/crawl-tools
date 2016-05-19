#include <cstdio>
#include <string.h>
using namespace std;
const int maxn = 1111;
int n, m;
bool h[maxn];
char t1, t2; int v1, v2;
int d[maxn][4], type[maxn];
int com;
int ans;
int main() {
 //freopen("c.in", "r", stdin);
 int T; scanf("%d", &T);
 while (T--) {
 ans = 0;
 scanf("%d%d", &n, &m);
 for (int i = 1; i <= m; i++) {
 for (int j = 1; j <= n; j++) h[j] = 1;
 scanf("%*c");
 scanf("%c=%d", &t1, &v1);
 //putchar(t1);
 scanf("%*c%c=%d", &t2, &v2);
 //putchar(t2);
 //puts("");
 d[i][t1-'X'+1] = v1;
 d[i][t2-'X'+1] = v2;
 type[i] = 6-(t1-'X'+1)-(t2-'X'+1);
 d[i][type[i]] = 0;
 for (int j = 1; j < i; j++){
 if (type[i]==type[j]){
 if (d[i][1]==d[j][1]&&d[i][2]==d[j][2]&&d[i][3]==d[j][3]) {
 memset(h,0,sizeof(h)); break;
 }
 } else {
 com = 6-type[i]-type[j];
 if (d[i][com]==d[j][com]) {
 h[d[j][type[i]]]=0;
 }
 }
 }
 for (int j = 1; j <= n; j++) ans += h[j];
 }
 printf("%d\n", ans);
 }
 return 0;
}
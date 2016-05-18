#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 100005


int n, m, k;

int num[MAXN], col[MAXN];
int pos[MAXN], sum[MAXN], pre[MAXN];
int pp, ss, tt;

int main()
{
 int T;
 scanf("%d", &T);
 while (T--)
 {
 scanf("%d %d %d", &n, &m, &k);
 pp = ss = tt = 0;
 pos[pp++] = 0;
 for (int i = 1; i <= n; i++)
 {
 scanf("%d", &num[i]);
 if (num[i] < k)
 pos[pp++] = i;
 }
 pos[pp++] = n + 1;
 memset(sum, 0, sizeof (sum));
 for (int i = 1; i <= n; i++)
 {
 scanf("%d", &col[i]);
 if (num[i] < k)
 ss++;
 else
 sum[ss] += col[i];
 sum[pp] += col[i];
 }
 long long ori = 0;
 pre[tt++] = 0;
 for (int i = 1; i <= n; i++)
 {
 if (num[i] < k)
 pre[i] = tt++;
 else
 pre[i] = pre[i - 1];
 }
 ori = (long long) sum[pp] * (n - sum[pp]);
 for (int i = 0; i <= ss; i++)
 ori -= (long long) sum[i] * (pos[i + 1] - pos[i] - 1 - sum[i]);


 while (m--)
 {
 int op, x;
 scanf("%d", &op);
 if (op == 0)
 {
 scanf("%d", &x);
 int pr = pre[x];
 ori -= (long long) sum[pp] * (n - sum[pp]);
 if (num[x] >= k)
 ori += (long long) sum[pr] * (pos[pr + 1] - pos[pr] - 1 - sum[pr]);

 if (col[x] == 0)
 {
 if (num[x] >= k)
 sum[pr]++;
 sum[pp]++;
 }
 else
 {
 if (num[x] >= k)
 sum[pr]--;
 sum[pp]--;
 }

 col[x] ^= 1;


 ori += (long long) sum[pp] * (n - sum[pp]);
 if (num[x] >= k)
 ori -= (long long) sum[pr] * (pos[pr + 1] - pos[pr] - 1 - sum[pr]);
 }
 else
 printf("%I64d\n", ori);
 }
 }
}
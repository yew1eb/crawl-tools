#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
const int maxn = 100005;
int n, m, T;
__int64 a[maxn], b[maxn], p, ans, sum;
queue<__int64> u, w;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
        for (int i = 0; i < m; i++) scanf("%I64d", &b[i]);
        sort(a, a + n);
        sort(b, b + m);
        for (int i = 0, j = 0; i < n; i++)
        {
            if (j == m) { if (!u.empty()) u.pop(), u.push(a[i]); }
            else if (a[i] >= b[j])
            {
                u.push(a[i]);
                w.push(b[j++]);
            }
            else if (!u.empty()) u.pop(), u.push(a[i]);
        }
        ans = 0;    sum = 0;
        for (int i = 0; i < u.size(); i++) sum -= b[i];
        for (int i = n - 1; i + u.size() >= n; i--) sum += a[i];
        for (int i = u.size(); i; i--)
        {
            ans = max(ans, sum);
            sum += b[i - 1];
            sum -= a[n - i];
        }
        while (!u.empty()) u.pop();
        while (!w.empty()) w.pop();
        printf("%I64d\n", ans);
    }
    return 0;
}
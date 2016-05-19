#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
int T, n, m, a[maxn], b[maxn], ans[maxn];

struct ST
{
    int f[maxn * 5];
    void build(int x,int l,int r)
    {
        if (l == r) f[x] = 1;
        else
        {
            int mid = l + r >> 1;
            build(x + x, l, mid);
            build(x + x + 1, mid + 1, r);
            f[x] = f[x + x] + f[x + x + 1];
        }
    }
    int find(int x, int l, int r, int v)
    {
        if (l == r) { f[x]--; return l; }
        else
        {
            int mid = l + r >> 1;
            f[x]--;
            if (v > f[x + x + 1]) return find(x + x, l, mid, v - f[x + x + 1]);
            else return find(x + x + 1, mid + 1, r, v);
        }
    }
}st;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        a[0] = 0;
        st.build(1, 1, n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i] - a[i - 1];
        }
        for (int i = n; i; i--)
        {
            ans[i] = st.find(1, 1, n, b[i] + 1);
        }
        for (int i = 1; i <= n; i++) printf("%d%s", ans[i], i == n ? "\n" : " ");
    }
    return 0;
}
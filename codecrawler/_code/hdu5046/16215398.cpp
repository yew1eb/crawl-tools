#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 105;
int T, n, m, x, y, t, tot, tt = 0;
ll X[maxn], Y[maxn], mp[maxn][maxn], l, r, mid;

inline void read(int &ret)
{
    char c;
    do {
        c = getchar();
    } while (c < '0' || c > '9');
    ret = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
}

struct DLX
{
#define maxn 500005
#define F(i,A,s) for (int i=A[s];i!=s;i=A[i])
    int L[maxn], R[maxn], U[maxn], D[maxn];
    int row[maxn], col[maxn], ans[maxn], cnt[maxn];
    int n, m, num, sz;

    void add(int now, int l, int r, int u, int d, int x, int y)
    {
        L[now] = l;    R[now] = r;    U[now] = u;
        D[now] = d;   row[now] = x;  col[now] = y;
    }
    void reset(int n, int m)
    {
        num = 0x7FFFFFFF;
        this->n = n;    this->m = m;
        for (int i = 0; i <= m; i++)
        {
            add(i, i - 1, i + 1, i, i, 0, i);
            cnt[i] = 0;
        }
        L[0] = m;     R[m] = 0;     sz = m + 1;
    }
    void insert(int x, int y)
    {
        int ft = sz - 1;
        if (row[ft] != x)
        {
            add(sz, sz, sz, U[y], y, x, y);
            U[D[sz]] = sz; D[U[sz]] = sz;
        }
        else
        {
            add(sz, ft, R[ft], U[y], y, x, y);
            R[L[sz]] = sz; L[R[sz]] = sz;
            U[D[sz]] = sz; D[U[sz]] = sz;
        }
        ++cnt[y];    ++sz;
    }

    //ç²¾ç¡®è¦ç
    void remove(int now)
    {
        R[L[now]] = R[now];
        L[R[now]] = L[now];
        F(i, D, now) F(j, R, i)
        {
            D[U[j]] = D[j];
            U[D[j]] = U[j];
            --cnt[col[j]];
        }
    }
    void resume(int now)
    {
        F(i, U, now)    F(j, L, i)
        {
            D[U[j]] = j;
            U[D[j]] = j;
            ++cnt[col[j]];
        }
        R[L[now]] = now;
        L[R[now]] = now;
    }
    bool dfs(int x)
    {
        //if (x + A() >= num) return;
        if (!R[0]) { num = min(num, x); return true; }
        int now = R[0];
        F(i, R, 0) if (cnt[now]>cnt[i]) now = i;
        remove(now);
        F(i, D, now)
        {
            ans[x] = row[i];
            F(j, R, i) remove(col[j]);
            if (dfs(x + 1)) return true;
            F(j, L, i) resume(col[j]);
        }
        resume(now);
        return false;
    }
    //ç²¾ç¡®è¦ç

    //éå¤è¦ç
    void Remove(int now)
    {
        F(i, D, now)
        {
            L[R[i]] = L[i];
            R[L[i]] = R[i];
        }
    }
    void Resume(int now)
    {
        F(i, U, now) L[R[i]] = R[L[i]] = i;
    }
    int vis[maxn];
    int flag[maxn];
    int A()
    {
        int dis = 0;
        F(i, R, 0) vis[i] = 0;
        F(i, R, 0) if (!vis[i])
        {
            dis++;    vis[i] = 1;
            F(j, D, i) F(k, R, j) vis[col[k]] = 1;
        }
        return dis;
    }
    void Dfs(int x)
    {
        if (!R[0]) num = min(num, x);
        else if (x + A()<num)
        {
            int now = R[0];
            F(i, R, 0) if (cnt[now]>cnt[i]) now = i;
            F(i, D, now)
            {
                Remove(i); F(j, R, i) Remove(j);
                Dfs(x + 1);
                F(j, L, i) Resume(j); Resume(i);
            }
        }
    }
    //éå¤è¦ç
}dlx;

int main()
{
    read(T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%lld%lld", &X[i], &Y[i]);
        l = r = 0;
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n; j++)
            {
                mp[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
                r = max(mp[i][j], r);
            }
        while (l < r)
        {
            mid = (l + r) >> 1;
            dlx.reset(n, n);
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (mp[i][j] <= mid) dlx.insert(i, j);
            dlx.Dfs(0);
            if (dlx.num> m) l = mid + 1; else r = mid;;
        }
        printf("Case #%d: %lld\n", ++tt, l);
    }
    return 0;
}
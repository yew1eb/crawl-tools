#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int maxn = 130;
int n, m;

struct mat
{
    int num[maxn][maxn];
    mat()
    {
        memset(num, 0, sizeof(mat));
    }
    mat operator * (const mat& c)const
    {
        mat ans;
        int col = 1 << m;
        for (int i = 0; i < col; i++)
            for (int k = 0; k < col; k++)
            {
                if (num[i][k] == 0) continue;
                for (int j = 0; j < col; j++)
                    ans.num[i][j] = (ans.num[i][j] + (ll)num[i][k] * c.num[k][j] % mod) % mod;
            }
        return ans;
    }
};

mat pow(mat x, int k)
{
    mat ans;
    for (int i = 0; i < (1 << m); i++) ans.num[i][i] = 1;
    while (k)
    {
        if (k & 1) ans = ans * x;
        x = x * x;
        k >>= 1;
    }
    return ans;
}

int ok(int s1, int s2)
{
    for (int i = 0; i < m; i++)
    {
        if (s2 & (1 << i))
        {
            if ((1 << i) & s1) continue;
            if (i && !(s2 & (1 << (i - 1))) && (s1 & (1 << (i - 1)))) return 0;
            if (i != (m - 1) && !(s2 & (1 << (i + 1))) && (s1 & (1 << (i + 1)))) return 0;
        }
    }
    return 1;
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        mat a;
        int col = 1 << m;
        for (int i = 0; i < col; i++)
            for (int j = 0; j < col; j++)
                a.num[i][j] = ok(i, j);
        a = pow(a, n - 1);
        int ans = 0;
        for (int i = 0; i < col; i++)
            for (int j = 0; j < col; j++)
            ans = (ans + a.num[i][j]) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
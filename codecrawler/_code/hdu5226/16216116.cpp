#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100005;
long long a[maxn], b[maxn], X1, X2, Y1, Y2, P, ans;
int n;

long long inv(long long x, long long m)
{
    if (x == 1) return x;
    return inv(m % x, m)*(m - m / x) % m;
}

long long C(int x, int y)
{
    if (x > y) return 0;
    return (a[y] * b[x]) % P * b[y - x] % P;
}

long long c(int x, int y)
{
    if (x > y) return 0;
    if (y >= P) return C(x % P, y % P)*c(x / P, y / P) % P;
    else return C(x, y);
}

int main()
{
    while (cin >> X1 >> Y1 >> X2 >> Y2 >> P)
    {
        a[0] = b[0] = 1;
        for (int i = 1; i <= min(X2 + 1, P - 1); i++)
        {
            a[i] = (a[i - 1] * i) % P;
            b[i] = inv(a[i], P);
        }
        ans = 0;
        for (int i = Y1; i <= Y2; i++)
        {
            (ans += c(i + 1, X2 + 1) - c(i + 1, X1)) %= P;
        }
        (ans += P) %= P;
        cout << ans << endl;
    }
    return 0;
}
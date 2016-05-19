#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <deque>
#include <stack>
#include <cctype>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1100;
const int INF = 0xfffffff;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const ld PI = acos (-1.0);

#define INFL 0x7fffffffffffffffLL
#define met(a, b) memset(a, b, sizeof(a))
#define put(a) cout << setiosflags(ios::fixed) << setprecision(a)

struct node
{
    int x, y, len;
    bool operator < (const node &a) const
    {
        return len < a.len;
    }
};

int Find (int x);
int Union (int x, int y);
int kruskal ();

int x[N][N], m, n, k;

int father[N*N];
node ve[N*N*4];

int main ()
{
    int na, ca = 1;
    scanf ("%d", &na);
    while (na--)
    {
        k = 0;
        scanf ("%d%d", &m, &n);

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                node q;

                father[i*n+j] = i * n + j;

                scanf ("%d", &x[i][j]);

                if (j > 0)
                {
                    q.x = i*n+j, q.y = i*n+j-1;
                    q.len = abs (x[i][j] - x[i][j-1]);
                    ve[k++] = q;
                }
                if (i > 0)
                {
                    q.x = i*n+j, q.y = i*n+j-n;
                    q.len = abs (x[i][j] - x[i-1][j]);
                    ve[k++] = q;
                }
            }

        sort (ve, ve + k);

        printf ("Case #%d:\n", ca++);
        int xx = kruskal();
        printf ("%d\n", xx);
    }
    return 0;
}


int Union (int x, int y)
{
    int a = Find (x), b = Find (y);

    if (a != b)
    {
        father[a] = b;
        return 1;
    }
    return 0;
}

int kruskal ()
{
    node s;
    int i;
    int sum = 0;

    for (int i=0; i<k; i++)
    {
        if (Union (ve[i].x, ve[i].y))
            sum += ve[i].len;
    }
    return sum;
}


int Find(int x)
{
   return x == father[x] ? x : father[x] = Find (father[x]);

}
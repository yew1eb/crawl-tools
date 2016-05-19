#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;


#define N 60
#define INF 0x3f3f3f3f
#define PI acos (-1.0)
#define EPS 1e-8
#define met(a, b) memset (a, b, sizeof (a))

typedef long long LL;

struct node
{
    char point, color;
}A[N], E[N];

bool g[N][N];
int used[N], vis[N], n;

int DFS (int u)
{
    for (int i=1; i<=n; i++)
    {
        if (!vis[i] && g[u][i])
        {
            vis[i] = true;
            if (!used[i] || DFS (used[i]))
            {
                used[i] = u;
                return true;
            }
        }
    }
    return false;
}

int get_num (char ch)
{
    if (ch >= '0' && ch <= '9') return ch-'0';
    else if (ch == 'T') return 10;
    else if (ch == 'J') return 11;
    else if (ch == 'Q') return 12;
    else if (ch == 'K') return 13;
    else if (ch == 'A') return 14;
}

int solve ()
{
    int ans = 0;
    for (int i=1; i<=n; i++)
    {
        met (vis, 0);
        if (DFS (i)) ans++;
    }
    return ans;
}

int main ()
{
    int t;
    scanf ("%d", &t);

    while (t--)
    {
        scanf ("%d", &n);
        met (g, 0);
        met (used, 0);

        for (int i=1; i<=n; i++)
        {
            getchar ();
            scanf("%c%c", &A[i].point, &A[i].color);
        }
        for (int i=1; i<=n; i++)
        {
            getchar ();
            scanf("%c%c", &E[i].point, &E[i].color);
        }

        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                if (A[j].point != E[i].point)
                {
                    int a = get_num (A[j].point);
                    int b = get_num (E[i].point);

                    if (b > a) g[i][j] = true;
                }
                else if (A[j].point == E[i].point)
                {
                    if (E[i].color == 'H' && A[j].color != 'H')
                        g[i][j] = true;
                    else if (E[i].color == 'S' && A[j].color != 'H' && A[j].color != 'S')
                        g[i][j] = true;
                    else if (E[i].color == 'D' && A[j].color == 'C')
                        g[i][j] = true;
                }
            }
        }
        printf ("%d\n", solve ());
    }
    return 0;
}

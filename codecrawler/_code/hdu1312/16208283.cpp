#include <iostream>
#include <queue>
using namespace std;
char f[23][23], d[4][2] = {1,0,0,1,-1,0,0,-1};
struct Z
{
    int x, y;
}o;
queue <Z> Q;
int i, j, k, n, m, a, b, ans;

int main()
{
    while (~scanf("%d%d\n", &m, &n), m|n)
    {
        for (i=1;i<=n;++i)
        {
            for (j=1;j<=m;++j)
            {
                scanf("%c", &f[i][j]);
                if (f[i][j] == '@')
                f[a=i][b=j] = '#';
            }
            getchar();
        }
        Z v = {a, b};
        Q.push(v);
        ans = 0;
        while (!Q.empty())
        {
            o = Q.front(), Q.pop();
            a = o.x, b = o.y;
            ans++;
            for (k=0;k<4;++k)
            {
                i = a + d[k][0];
                j = b + d[k][1];
                if (0<i && i<=n && 0<j && j<=m && f[i][j]=='.')
                {
                    f[i][j] = '#';
                    Z v = {i, j};
                    Q.push(v);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
        

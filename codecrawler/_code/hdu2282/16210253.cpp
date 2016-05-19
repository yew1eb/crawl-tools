#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;
int n, nx, ny;
int lx[N], ly[N], slack[N], match[N], s[N][N];
bool visx[N], visy[N];
int v[N], tmp[N];

bool hungary(int v)
{
    visx[v] = true;
    for(int i = 0; i < ny; i++)
    {
        if(visy[i]) continue;
        if(lx[v] + ly[i] == s[v][i])
        {
            visy[i] = true;
            if(match[i] == -1 || hungary(match[i]))
            {
                match[i] = v;
                return true;
            }
        }
        else slack[i] = min(slack[i], lx[v] + ly[i] - s[v][i]);
    }

    return false;
}

void km()
{
    memset(match, -1, sizeof match);
    memset(ly, 0, sizeof ly);
    for(int i = 0; i < nx; i++)
        lx[i] = -INF;
    for(int i = 0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            lx[i] = max(lx[i], s[i][j]);
    for(int i = 0; i < nx; i++)
    {
        memset(slack, 0x3f, sizeof slack);
        while(true)
        {
            memset(visx, 0, sizeof visx);
            memset(visy, 0, sizeof visy);
            if(hungary(i)) break;
            else
            {
                int d = INF;
                for(int j = 0; j < ny; j++)
                    if(!visy[j]) d = min(d, slack[j]);
                for(int j = 0; j < nx; j++)
                    if(visx[j]) lx[j] -= d;
                for(int j = 0; j < ny; j++)
                    if(visy[j]) ly[j] += d;
                    else slack[j] -= d;
            }
        }
    }
}

int main()
{
    int n;

    while(~ scanf("%d", &n))
    {
        int t = n / 2;
        for(int i = 0; i < n; i++)
            scanf("%d", v + i);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                s[i][j] = -INF;

        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++)
            if(v[i] == 0)
                tmp[i] = cnt2++;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < v[i] - 1; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(v[k] == 0)
                    {
                        if(abs(k - i) >= t)
                            s[cnt1][tmp[k]] = -(n - abs(k - i));
                        else
                            s[cnt1][tmp[k]] = -abs(k - i);
                    }
                }
                cnt1++;
            }

        nx = cnt1, ny = cnt2;
        km();

        int res = 0;
        for(int i = 0; i < ny; i++)
            if(match[i] != -1)
                res += s[match[i]][i];
        printf("%d\n", -res);
    }

    return 0;
}

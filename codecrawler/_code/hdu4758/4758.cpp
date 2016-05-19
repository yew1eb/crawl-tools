#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define CLR(a, b) memset(a, b, sizeof(a))

using namespace std;
typedef long long LL;

const int MAX_NODE = 110 * 2;
const int MOD = 1000000007;
const int CHILD_NUM = 2;
const int N = 110;

class ACAutomaton
{
private:
    int chd[MAX_NODE][CHILD_NUM];
    int dp[2][N][MAX_NODE][4];
    int fail[MAX_NODE];
    int val[MAX_NODE];
    int Q[MAX_NODE];
    int ID[128];
    int sz;
public:
    void Initialize()
    {
        fail[0] = 0;
        ID['R'] = 0;
        ID['D'] = 1;
    }
    void Reset()
    {
        CLR(chd[0] , 0);
        CLR(val, 0);
        sz = 1;
    }
    void Insert(char *a, int hav)
    {
        int p = 0;
        for ( ; *a ; a ++)
        {
            int c = ID[*a];
            if (!chd[p][c])
            {
                memset(chd[sz] , 0 , sizeof(chd[sz]));
                chd[p][c] = sz ++;
            }
            p = chd[p][c];
        }
        val[p] |= hav;
    }
    void Construct()
    {
        int *s = Q , *e = Q;
        for (int i = 0 ; i < CHILD_NUM ; i ++)
        {
            if (chd[0][i])
            {
                fail[chd[0][i]] = 0;
                *e ++ = chd[0][i];
            }
        }
        while (s != e)
        {
            int u = *s++;
            for (int i = 0 ; i < CHILD_NUM ; i ++)
            {
                int &v = chd[u][i];
                if (v)
                {
                    *e ++ = v;
                    fail[v] = chd[fail[u]][i];
                    val[v] |= val[fail[v]];
                }
                else
                {
                    v = chd[fail[u]][i];
                }
            }
        }
    }
    int Work(int n, int m)
    {
        //最好手动初始化dp数组，不然如果没有用滚动数组的话会超时。
        for(int j = 0; j <= m; j ++)
                for(int k = 0; k < sz; k ++)
                    for(int s = 0; s < 4; s ++)
                        dp[0][j][k][s] = 0;
        dp[0][0][0][0] = 1;
        for(int i = 0; i <= n; i ++)
        {
            for(int j = 0; j <= m; j ++)
                for(int k = 0; k < sz; k ++)
                    for(int s = 0; s < 4; s ++)
                        dp[(i + 1) & 1][j][k][s] = 0;
            for(int j = 0; j <= m; j ++)
                for(int k = 0; k < sz; k ++)
                    for(int s = 0; s < 4; s ++)
                    {
                        if(i < n)
                        {
                            int next = chd[k][0];
                            int tmp = s | val[next];
                            dp[(i + 1) & 1][j][next][tmp] += dp[i & 1][j][k][s];
                            dp[(i + 1) & 1][j][next][tmp] %= MOD;
                        }
                        if(j < m)
                        {
                            int next = chd[k][1];
                            int tmp = s | val[next];
                            dp[i & 1][j + 1][next][tmp] += dp[i & 1][j][k][s];
                            dp[i & 1][j + 1][next][tmp] %= MOD;
                        }
                    }
        }
        int ret = 0;
        for(int i = 0; i < sz;i ++)
        {
            ret = (ret + dp[n & 1][m][i][3]) % MOD;
        }
        return ret;
    }
} AC;

int main()
{
    //freopen("input.txt", "r", stdin);
    AC.Initialize();
    int n, t, m;
    scanf("%d", &t);
    while (t --)
    {
        AC.Reset();
        scanf("%d%d", &n, &m);
        for (int i = 1 ; i <= 2 ; i ++)
        {
            char temp[N];
            scanf("%s", temp);
            AC.Insert(temp, i);
        }
        AC.Construct();
        printf("%d\n", AC.Work(n, m));
    }
    return 0;
}

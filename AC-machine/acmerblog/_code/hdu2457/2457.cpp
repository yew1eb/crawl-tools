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

const int MAX_NODE = 22 * 55 * 2;
const int INF = 0x3f3f3f3f;
const int CHILD_NUM = 4;
const int N = 1010;

class ACAutomaton
{
private:
    int chd[MAX_NODE][CHILD_NUM];
    int dp[N][MAX_NODE];
    int fail[MAX_NODE];
    bool val[MAX_NODE];
    int Q[MAX_NODE];
    int ID[128];
    int sz;
public:
    void Initialize()
    {
        fail[0] = 0;
        ID['A'] = 0;ID['G'] = 1;
        ID['C'] = 2;ID['T'] = 3;
    }
    void Reset()
    {
        CLR(chd[0] , 0);sz = 1;
    }
    void Insert(char *a)
    {
        int p = 0;
        for ( ; *a ; a ++)
        {
            int c = ID[*a];
            if (!chd[p][c])
            {
                CLR(chd[sz] , 0);
                val[sz] = false;
                chd[p][c] = sz ++;
            }
            p = chd[p][c];
        }
        val[p] = true;
    }
    void Construct()
    {
        int *s = Q , *e = Q;
        for (int i = 0 ; i < CHILD_NUM ; i ++)
        {
            if (chd[0][i])
            {
                fail[ chd[0][i] ] = 0;
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
                    fail[v] = chd[ fail[u] ][i];
                    val[v] |= val[fail[v]];
                }
                else
                {
                    v = chd[ fail[u] ][i];
                }
            }
        }
    }
    int Work(char *ch)
    {
        int len, S, T, ret;
        len = strlen(ch);
        CLR(dp, INF);dp[0][0] = 0;
        for(int i = 0; i < len; i ++)
            for(int j = 0; j < sz; j ++)
            {
                if(val[j]) continue;
                if(dp[i][j] == INF) continue;
                for(int k = 0; k < 4; k ++)
                {
                    T = chd[j][k];
                    if(val[T]) continue;
                    dp[i + 1][T] = min(dp[i + 1][T], dp[i][j] + (ID[ch[i]] != k));
                }
        }ret = INF;
        for(int i = 0; i < sz; i ++)
        {
            ret = min(ret, dp[len][i]);
        }
        return ret == INF ? -1 : ret;
    }
} AC;

char ch[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    AC.Initialize();
    int n, t, cas = 1;
    while (scanf("%d", &n), n)
    {
        AC.Reset();
        for (int i = 0 ; i < n ; i ++)
        {
            char temp[55];
            scanf("%s", temp);
            AC.Insert(temp);
        }
        scanf("%s", ch);
        AC.Construct();
        printf("Case %d: %d\n", cas ++, AC.Work(ch));
    }
    return 0;
}
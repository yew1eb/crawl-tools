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

const int MAX_NODE = 10100 * 66;
const int INF = 0x3f3f3f3f;
const int MOD = 20090717;
const int CHILD_NUM = 26;
const int N = 30;

class Trie
{
private:
    int chd[MAX_NODE][CHILD_NUM];
    int val[MAX_NODE];
    int Q[MAX_NODE];
    int ID[128];
    int sz;
public:
    void Initialize()
    {
        for(int i = 0; i < 26; i ++)
            ID[i + 'a'] = i;
    }
    void Reset()
    {
        CLR(chd[0] , 0);sz = 1;
        CLR(val, 0);
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
                chd[p][c] = sz ++;
            }
            p = chd[p][c];
            val[p] ++;
        }
    }
    int Work()
    {
        int q, now, S = 0;
        double tmp[10], lg;
        scanf("%d", &q);bool flag = 0;
        for(int i = 0; i < q; i ++)
        {
            lg = 1e18;
            for(int j = 0; j < 8; j ++)
            {
                scanf("%lf", &tmp[j]);
                lg = min(lg, tmp[j]);
            }now = 0;
            for(int j = 0; j < 8; j ++)
            {
                now <<= 1;
                if(tmp[j] > lg * 1.105)
                    now += 1;
            }
            if(!flag)S = chd[S][ID[now]];
            if(!S) flag = 1;
        }
        if(!flag) return val[S];
        else return 0;
    }
} Tr;

char ch[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    Tr.Initialize();
    int n, m, k, ans;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        Tr.Reset();
        for (int i = 0 ; i < n ; i ++)
        {
            char temp[66];
            scanf("%s", temp);
            Tr.Insert(temp);
        }
        ans = 0;
        for(int i = 0; i < m; i ++)
            ans += Tr.Work();
        printf("%d\n", ans);
    }
    return 0;
}

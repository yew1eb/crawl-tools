#include <cstdlib>   
#include <cctype>   
#include <cstring>   
#include <cstdio>   
#include <cmath>   
#include <algorithm>   
#include <vector>   
#include <string>   
#include <iostream>   
#include <sstream>   
#include <map>   
#include <set>   
#include <queue>   
#include <stack>   
#include <fstream>   
#include <numeric>   
#include <iomanip>   
#include <bitset>   
#include <list>   
#include <stdexcept>   
#include <functional>   
#include <utility>   
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int N = 100;
LL dp[N][3];
int dig[N];
int getst(int st, int d)
{
    if (st == 2) return 2;
    if (st == 1 && d == 9) return 2;
    if (d == 4) return 1;
    return 0;
}

LL dfs(int pos, int st, int limit)
{
    if (pos == -1) return st == 2;
    if (!limit && dp[pos][st] >= 0) return dp[pos][st];
    int e = limit ? dig[pos] : 9;
    LL ans = 0;
    for (int i = 0; i <= e; i++)
    {
        ans += dfs(pos - 1, getst(st, i), limit&&e == i);
    }
    if (!limit) dp[pos][st] = ans;
    return ans;
}

LL solve(LL n)
{
    int pos = 0;
    while (n)
    {
        dig[pos++] = n % 10;
        n /= 10;
    }
    return dfs(pos - 1, 0, 1);
}
int main()
{
    //freopen("input.txt", "r", input);
    MEM(dp, -1);
    int ncase;
    cin >> ncase;
    while (ncase--)
    {
        LL n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
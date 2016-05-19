#include <stdio.h>//dfs
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll __int64
int bit[25];
int f[12][10];
int dfs(int pos, int pre, int flag, int z)//flagè¡¨ç¤ºåä¸ä½ä¸åä¸ä½çæé«ä½ä¸åzè¡¨ç¤ºåè¾¹æ¯å¦æå¤§äº0çä½
{
    if (pos == 0) return 1;
    if (z == 0&& flag && f[pos][pre] != -1) return f[pos][pre];
    int mmax = flag ? 9 : bit[pos];
    int ans = 0;
    for (int i = 0; i <= mmax; i++)
    {
        if (z == 0 || pre >= i && i !=0 && pre%i==0)
            ans += dfs(pos-1, i, flag || i < mmax, z||i);
    }
    if (flag && z == 0) f[pos][pre] = ans;
    return ans;
}

int solve(int x)
{
    int len = 0, tmp = x;
    while (tmp)//æè¯¥æ°æ¾å°æ°ç»é
    {
        bit[++len] = tmp % 10;
        tmp /= 10;
    }
    int ans = 0;
    ans = dfs(len, 0, 0, 0);
    //cout << ans << endl;
    return ans;
}
int main()
{
    int t;
    cin >> t;
    memset(f, -1, sizeof(f));//åå§å
    while (t--)
    {

        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", solve(b)-solve(a-1));
    }
    return 0;
}

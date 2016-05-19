#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
const int N = 20;
bool edge[N][N];//å¨å­æ¯æ¡è¾¹
int p[N];//æ¯ä¸ªç¹çç¥åç»ç¹
int n, m;//nä¸ªå°æåï¼mä¸ªç®ç
bool dfs(int id, int cnt)//å·²ç»èèå°ç¬¬å ä¸ªå°æåï¼å·²ç»ç¨äºå ä¸ªç®ç
{
    if (cnt > m)//ç®çè¶è¿äºmä¸ª
    {
        return false;
    }

    if (id == n)//ææäººé½å·²ç»èèå®äº
    {
        return true;
    }

    for (int i = 0; i < id; ++i)//æä¸¾idè¯¥å å¥åªä¸ªéå
    {
        if (p[i] != i)//å¦æè¯¥èç¹å·²ç»å å¥å¶å®çéå
        {
            continue;//åä¸åèè
        }

        bool f = true;

        for (int j = 0; j < id && f; ++j)//æä¸¾é¡¶ç¹
        {
            if (p[j] == i)//å¦æé¡¶ç¹jå¨éåiéï¼é£ä¹å½idå è¿æ¥çæ¶åå°±è¦èèidåjä¹é´æ¯ä¸æ¯ä¹æè¾¹
            {
                f = edge[j][id];
            }
        }

        if (f)//å¦æidå¯ä»¥å å¥iéå
        {
            p[id] = i;//idçç¥åç»ç¹å³ä¸ºi

            if (dfs(id + 1, cnt))//èèä¸ä¸ä¸ªå°æåï¼éåçä¸ªæ°å¹¶æ²¡æå¢å 
            {
                return true;
            }

            p[id] = id;//å¦æåç°idä¸è½å å¥iéåï¼éåºéåi
        }
    }

    if (dfs(id + 1, cnt + 1))//èèä¸ä¸ä¸ªå°æåï¼idä¸ºåç¬ä¸ä¸ªéå
    {
        return true;
    }

    return false;
}
int main()
{
    int i, j, k, a, b;

    while (~scanf("%d%d", &n, &m))
    {
        memset(edge, 0, sizeof(edge));

        for (i = 0; i < n; ++i)
        {
            scanf("%d", &k);

            while (k--)
            {
                scanf("%d", &a);
                edge[i][a] = true;
            }
        }

        for (i = 0; i < n; ++i)//ä¸å¼å§çæ¶åï¼æä»¥ç¹é½æ¯åç¬ä¸ä¸ªéå
        {
            p[i] = i;
        }

        if (m >= n || dfs(0, 0))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }

    return 0;
}

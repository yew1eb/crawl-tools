#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAXN 177
int N;
int g[MAXN][MAXN], linker[MAXN];
bool used[MAXN];
int dfs(int L)//ä»å·¦è¾¹å¼å§æ¾å¢å¹¿è·¯å¾
{
    int R;
    for(R = 1 ; R <= N ; R++)//è¿ä¸ªé¡¶ç¹ç¼å·ä»0å¼å§ï¼è¥è¦ä»1å¼å§éè¦ä¿®æ¹
    {
        if(g[L][R]!=0 && !used[R])
        {
            //æ¾å¢å¹¿è·¯ï¼åå
            used[R]=true;
            if(linker[R] == -1 || dfs(linker[R]))
            {
                linker[R]=L;
                return 1;
            }
        }
    }
    return 0;//è¿ä¸ªä¸è¦å¿äºï¼ç»å¸¸å¿è®°è¿å¥
}
int hungary()
{
    int res = 0 ;
    memset(linker,-1,sizeof(linker));
    for(int L = 1; L <= N; L++)
    {
        memset(used,0,sizeof(used));
        if(dfs(L))
            res++;
    }
    return res;
}
int main()
{
    int t;
    int k, res, tt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&k);
        memset(g,0,sizeof(g));
        for(int i = 1 ; i <= N ; i++ )
        {
            scanf("%d",&tt);
            while(tt <= N)
            {
                g[tt][i] = 1;
                tt+=k;
            }
        }
        res = hungary();
        if(res == N)
        {
            printf("Jerry\n");
        }
        else
        {
            printf("Tom\n");
        }
    }
    return 0 ;
}

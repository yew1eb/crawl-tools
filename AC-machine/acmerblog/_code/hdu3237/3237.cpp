#include <stdio.h>
#include <string.h>
#define MIN 110
#define INF 1047483647
#define min(a,b) (a)<(b)?(a):(b)


int n,m,ht[MIN],ans,one[1<<8]; //one[i]表示状态i中1的个数
int state,dp[2][MIN][1<<8][10];//dp[i][j][k][s]表示到第i行取走j本书剩下的状态数为k最后一本书高度是s时最少连续段数


void Initial() {

    for (int i = 0; i < (1<<8); ++i) {

        for (int j = 0; j < 8; ++j)
            if (i & (1<<j)) one[i]++;
    }
}


int main()
{
    int i,j,k,s,cas = 0;
    int pre,cur,mx,tot;
    Initial();


    while (scanf("%d%d",&n,&m) ,n+m) {

        mx = state = 0;
        for (i = 1; i <= n; ++i) {

            scanf("%d",&ht[i]);
            ht[i] -= 25;
            if (ht[i] > mx) mx = ht[i];       //统计最大的高度
            state |= (1<<ht[i]);
        }

        //Initial
        mx++ ,tot = (1<<mx);
        for (j = 0; j <= m; ++j)
            for (k = 0; k < tot; ++k)
                for (s = 0; s <= mx; ++s)
                    dp[1][j][k][s] = INF;


       dp[1][0][1<<ht[1]][ht[1]] = 1;   //如果第一本书留下来段数就为1
       dp[1][1][0][mx] = 0;             //mx其实是不存在的高度，因为第一本书被拿走了那么留下的最后一本书高度实际是不存在的，用这个只是好转移
       for (i = 2; i <= n; ++i) {

           cur = i & 1;                 //当前状态
           pre = 1 - cur;               //前一个状态


           for (j = 0; j <= m ; ++j)
                for (k = 0; k < tot; ++k)
                    for (s = 0; s <= mx; ++s)
                        dp[cur][j][k][s] = INF;


           for (j = 0; j <= m && j < i; ++j)
               for (k = 0; k < tot; ++k)
                   for (s = 0; s <= mx; ++s) {

                       if (dp[pre][j][k][s] == INF) continue;           //小剪枝，但不剪就TLE
                       int stk = k | (1<<ht[i]);                        //当前的状态
                        if (j < m)                                      //如果还可以取走
                            dp[cur][j + 1][k][s] = min(dp[cur][j + 1][k][s], dp[pre][j][k][s]);
                        if (s == ht[i])                                 //如果和留下来的最后一本高度相同，则当前的书留下来并不增加段数
                            dp[cur][j][k][s] = min(dp[cur][j][k][s],dp[pre][j][k][s]);
                        else                                            //增加一段
                            dp[cur][j][stk][ht[i]] = min(dp[cur][j][stk][ht[i]],dp[pre][j][k][s]+1);
                    }
        }


        cur = n & 1,ans = n;
        for (j = 0; j <= m; ++j)
            for (k = 0; k < tot; ++k)
                for (s = 0; s < mx; ++s) 
                    if (dp[cur][j][k][s] != INF) {

                    int st = state ^ k;
                    ans = min(ans,one[st]+dp[cur][j][k][s]);
                }


        printf("Case %d: %d\n\n",++cas,ans);
    }
}
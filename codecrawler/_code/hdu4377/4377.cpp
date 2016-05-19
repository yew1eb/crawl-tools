#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define MAXN 1005
bool vis[MAXN];
int a[MAXN], ant[MAXN];
int n;

int UU()
{
    int dp[MAXN], ans = 1;
    for(int i = 1; i <= n; i++) dp[i] = 1;
    for(int i = 1; i <= n; i++)
    {
        int MAX = 0;
        for(int j = i-1; j >= 1; j--)
        {
            if(a[i] > a[j] && dp[j] > MAX) MAX = dp[j];
        }
        dp[i] = MAX + 1;
        if(dp[i] > ans) ans = dp[i];
    }
    return ans;
}

int DD()
{
    int dp[MAXN], ans = 1;
    for(int i = 1; i <= n; i++) dp[i] = 1;
    for(int i = 1; i <= n; i++)
    {
        int MAX = 0;
        for(int j = i-1; j >= 1; j--)
        {
            if(a[i] < a[j] && dp[j] > MAX) MAX = dp[j];
        }
        dp[i] = MAX + 1;
        if(dp[i] > ans) ans = dp[i];
    }
    return ans;
}

int mmm = 99999;

void dfs(int x, int num)
{
    //if(tar) return;
    a[num] = x;
    if(num == n)
    {
        int MAX = UU();
        int MIN = DD();
        //printf("MAX=%d MIN=%d\n", MAX, MIN);
        int tp = max(MAX, MIN);
        if(tp < mmm)
        {
            mmm = tp;
            for(int i = 1; i <= n; i++)
            {
                ant[i] = a[i];
            }
        }
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        vis[i] = true;
        dfs(i, num+1);
        vis[i] = false;
    }
}

int main()
{
    int i, j, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        /*memset(vis, false, sizeof(vis));
        mmm = 99999;
        for(i = 1; i <= n; i++)
        {
            vis[i] = true;
            dfs(i, 1);
            vis[i] = false;
        }
        for(i = 1; i <= n; i++)
        {
            printf("%d ", ant[i]);
        }
        printf("\n------------------\n");*/

        if(n == 1) {printf("1\n");continue;}
        if(n == 2) {printf("1 2\n");continue;}
        if(n == 3) {printf("1 3 2\n"); continue;}
        /*if(n == 4) {printf("2 1 4 3\n"); continue;}
        if(n == 5) {printf("1 2 5 4 3\n"); continue;}
        if(n == 6) {printf("1 3 2 6 5 4\n"); continue;}
        if(n == 8) {printf("2 1 5 4 3 8 7 6\n"); continue;}
        if(n%2 == 1)
        {
            printf("1");
            for(i = 2; i <= (n+1)/2-3; i++)
            {
                printf(" %d", i);
            }
            printf(" %d %d %d", (n+1)/2, (n+1)/2-1, (n+1)/2-2);
            for(i = n; i >= (n+1)/2+1; i--)
            {
                printf(" %d", i);
            }
            printf("\n");
        }
        else
        {
            printf("1");
            for(i = 2; i <= n/2+1-4; i++)
            {
                printf(" %d", i);
            }
            printf(" %d %d %d %d", n/2+1, n/2, n/2-1, n/2-2);
            for(i = n; i >= n/2+2; i--)
            {
                printf(" %d", i);
            }
            printf("\n");
        }*/
        int l, kuai, sheng, tp;
        l = sqrt(n*1.0);
        bool tar = true;
        if(l == sqrt(n*1.0))
        {
            sheng = 0;
            kuai = n / l;
            tar = false;
            ///printf("goto L\n");
            goto L;
        }

        if(l != sqrt(n*1.0)) l++;
        kuai = n / l;
        sheng = n - kuai*l;
        if(sheng == 0 && l != sqrt(n*1.0))
        {
            sheng = l;
            kuai--;
        }
        //tp = l - kuai;
        //tp = min(tp, sheng)-1;

        //printf("l=%d kuai=%d sheng=%d\n", l, kuai, sheng);

        if(l - kuai >= 2)
        {
            printf("1");
            for(i = sheng; i > 1; i--)
                printf(" %d", i);
        }
        else
        {
            printf("%d", sheng);
            for(i = sheng-1; i >= 1; i--)
                printf(" %d", i);
        }
        /*for(i = 1; i <= tp; i++)
        {
            printf("%d ", i);
        }
        if(sheng-tp==0) goto L;
        for(i = sheng; i > sheng-tp; i--)
        {
            printf("%d ", i);
        }*/
        L:
        int sum = sheng;
        for(i = 1; i <= kuai; i++)
        {
            for(j = 0; j < l; j++)
            {
                if(tar) printf(" ");
                tar = true;
                printf("%d", sum+l-j);
            }
            sum += l;
        }
        printf("\n");
    }

    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define N 510
#define MAXN 1<<28
#define CLR(arr, what) memset(arr, what, sizeof(arr))

int map[N][N];
int lx[N], ly[N];
bool visitx[N], visity[N];
int slack[N];
int match[N];
int usem[N];
int n, m, edge;

bool Hungary(int u)
{
    int temp;
    visitx[u] = true;
    for(int i = 0; i < m; ++i)
    {
        if(visity[i])
            continue;
        else
        {
            temp = lx[u] + ly[i] - map[u][i];
            if(temp == 0) //å±äºç¸ç­å­å¾
            {
                visity[i] = true;
                if(match[i] == - 1 || Hungary(match[i]))
                {
                    match[i] = u;
                    return true;
                }
            }
            else //xå¨äº¤éæ ï¼yä¸å¨äº¤éæ ï¼æ´æ°d
                slack[i] = min(slack[i], temp);
        }
    }
    return false;
}

bool KM_perfect_match()
{
    int temp;
    CLR(lx, 0); //åå§åé¡¶æ 
    CLR(ly, 0);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            lx[i] = max(lx[i], map[i][j]);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j) //åå§åæ¾å¼é
            slack[j] = MAXN;
        while(1)
        {
            CLR(visitx, 0);
            CLR(visity, 0);
            if(Hungary(i))
                break;
            else
            {
                temp = MAXN;
                for(int j = 0; j < m; ++j)
                    if(!visity[j])
                        temp = min(temp, slack[j]);
                if(temp == MAXN) //æ æ³æ¾å¼ï¼æ¾ä¸å°å®å¤å¹é
                    return false;
                for(int j = 0; j < n; ++j) //æ´æ°é¡¶æ 
                {
                    if(visitx[j])
                        lx[j] -= temp;
                }
                for(int j = 0; j < m; ++j)
                {
                    if(visity[j])
                        ly[j] += temp;
                    else
                        slack[j] -= temp;
                }
            }
        }
    }
    return true;
}

int main()
{
    int T = 1;
    int s, r, v;
    int ans;
    int countm; //ç»è®¡ä½¿ç¨å¬å¯æ°ï¼åªæ
    bool perfect; //æ¯å¦å­å¨å®å¤å¹é
    while(~scanf("%d%d%d", &n, &m, &edge))
    {
        CLR(match, -1);
        CLR(usem, 0);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                map[i][j] = -MAXN;
        countm = ans = 0;
        perfect = false;
        for(int i = 0; i < edge; ++i)
        {
            scanf("%d%d%d", &s, &r, &v);
            if(v >= 0) //è´æå¼ä¸å è¾¹
                map[s][r] = v;
            usem[r] = true;
        }
        for(int i = 0; i < N; ++i) //å¬å¯æ°å°orä½¿ç¨å¬å¯æ°å°
            if(usem[i])
                countm++;
        if(n > m || n > countm)
        {
            printf("Case %d: -1\n", T++);
            continue;
        }
        perfect = KM_perfect_match();
        for(int i = 0; i < m; ++i) //æå¼ç¸å 
            if(match[i] != - 1)
                ans += map[ match[i] ][i];
        if(perfect)
            printf("Case %d: %d\n", T++, ans);
        else
            printf("Case %d: -1\n", T++);
    }
    return 0;
}
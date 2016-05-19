#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
#define N 310
int map[N][N];
bool visitx[N], visity[N];
int lx[N], ly[N];
int match[N];
int n;

bool Hungary(int u) //åçå©ç®æ³
{
    visitx[u] = true;
    for(int i = 0; i < n; ++i)
    {
        if(!visity[i] && lx[u] + ly[i] == map[u][i])
        {
            visity[i] = true;
            if(match[i] == -1 || Hungary(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}

void KM_perfect_match()
{
    int temp;
    memset(lx, 0, sizeof(lx)); //åå§åé¡¶æ 
    memset(ly, 0, sizeof(ly)); //ly[i]ä¸º0
    for(int i = 0; i < n; ++i) //lx[i]ä¸ºæå¼æå¤§çè¾¹
        for(int j = 0; j < n; ++j)
            lx[i] = max(lx[i], map[i][j]);
    for(int i = 0; i < n; ++i) //å¯¹nä¸ªç¹å¹é
    {
        while(1)
        {
            memset(visitx, false, sizeof(visitx));
            memset(visity, false, sizeof(visity));
            if(Hungary(i)) //å¹éæå
                break;
            else //å¹éå¤±è´¥ï¼æ¾æå°å¼
            {
                temp = INT_MAX;
                for(int j = 0; j < n; ++j) //xå¨äº¤éæ ä¸­
                    if(visitx[j])
                        for(int k = 0; k < n; ++k) //yå¨äº¤éæ å¤
                            if(!visity[k] && temp > lx[j] + ly[k] - map[j][k])
                                temp = lx[j] + ly[k] - map[j][k];
                for(int j = 0; j < n; ++j) //æ´æ°é¡¶æ 
                {
                    if(visitx[j])
                        lx[j] -= temp;
                    if(visity[j])
                        ly[j] += temp;
                }
            }
        }
    }
}

int main()
{
    int ans;
    while(scanf("%d", &n) != EOF)
    {
        ans = 0;
        memset(match, -1, sizeof(match));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &map[i][j]);
        KM_perfect_match();
        for(int i = 0; i < n; ++i) //æå¼ç¸å 
            ans += map[match[i]][i];
        printf("%d\n", ans);
    }
    return 0;
}
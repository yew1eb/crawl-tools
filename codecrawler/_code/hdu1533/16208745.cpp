#include<iostream>
#include<cstring>
#include<climits>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 110
char maps[N][N];
int map[N][N];
int lx[N], ly[N];
int slack[N];
int match[N];
bool visitx[N], visity[N];
int n;

bool Hungary(int u)
{
    visitx[u] = true;
    for(int i = 0; i < n; ++i)
    {
        if(visity[i])
            continue;
        else
        {
            if(lx[u] + ly[i] == map[u][i])
            {
                visity[i] = true;
                if(match[i] == -1 || Hungary(match[i]))
                {
                    match[i] = u;
                    return true;
                }
            }
            else
                slack[i] = min(slack[i], lx[u] + ly[i] - map[u][i]);
        }
    }
    return false;
}

void KM_perfect_match()
{
    int temp;
    for(int i = 0; i < n; ++i) //åå§åå¤§è´æ°
            lx[i] = -INT_MAX;
    memset(ly, 0, sizeof(ly));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            lx[i] = max(lx[i], map[i][j]);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
                slack[j] = INT_MAX;
        while(1)
        {            
            memset(visitx, false, sizeof(visitx));
            memset(visity, false, sizeof(visity));
            if(Hungary(i))
                break;
            else
            {
                temp = INT_MAX;
                for(int j = 0; j < n; ++j)
                    if(!visity[j])
                        temp = min(temp, slack[j]);
                for(int j = 0; j < n; ++j)
                {
                    if(visitx[j])
                        lx[j] -= temp;
                    if(visity[j])
                        ly[j] += temp;
                    else
                        slack[j] -= temp;
                }
            }
        }
    }
}

int main()
{
    int row, col, ans, numi, numj;
    while(scanf("%d%d", &row, &col) && (row + col))
    {
        n = ans = numi = numj = 0;
        memset(match, -1, sizeof(match));
        for(int i = 0; i < row; ++i)
        {
            scanf("%*c");
            for(int j = 0; j < col; ++j)
            {
                scanf("%c", &maps[i][j]);
                if(maps[i][j] == 'm')
                    n++;
            }
        }
        for(int i = 0; i < row; ++i) //å»ºå¾
        {
            for(int j = 0; j < col; ++j)
            {
                if(maps[i][j] == 'm')
                {
                    for(int k = 0; k < row; ++k)
                    {
                        for(int l = 0; l < col; ++l)
                        {
                            if(maps[k][l] == 'H')
                            map[numi][numj++] = - (abs(k - i) + abs(l - j)); //åä¸ºè´æè¾¹
                        }
                    }
                    numi++;
                    numj = 0;
                }
            }
        }
        KM_perfect_match();
        for(int i = 0; i < n; ++i)
            ans += map[match[i]][i];
        printf("%d\n", - ans); //ç»æåå
    }
    return 0;
}
#include<iostream> 
#include<algorithm>
#include<cstring>
#include<cstdio> 
using namespace std;

const int M[5][5] = 
{
    {3, 1, 1, 1, 0},
    {1, 0, 1, 0, 0},
    {1, 1, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {0, 0, 0, 1, 0}
};
int DP[1000][5];    // DP[i][j]è¡¨ç¤ºæ¼æãiåå ä¸jå¯¹åºçä½åãçæåµæ°
int W;

int DFS(int col, int state)
{
    if(col == 0 && state == 0)    return 1;
    if(col <= 0)    return 0;
    int& ans = DP[col][state];
    if(ans > 0)    return ans;
    for(int i = 0; i < 5; i++)
    {
        if(M[state][i])
        {
            ans += DFS(col-1, i);
             if(M[state][i] == 3)    ans += DFS(col-2, i);
        }
    }
    return ans;
}

int main()
{
    memset(DP, 0, sizeof(DP));
    DFS(1000, 0);
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++)
    {
        printf("%d ", kase);
        scanf("%d", &W);
        printf("%d\n", DFS(W, 0));
    }
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<functional>
using namespace std;

#define me(s) memset(s,0,sizeof(s))
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair <int, int> P;



const int N = 15;

int dx[7][4] = { { 0, 0, 1, 1 }, { 0, 0, 0, 0 }, { 0, 1, 2, 3 },    
{ 0, 0, 1, 2 }, { 0, 0, 0, 1 }, { 0, 1, 2, 2 }, { 0, 1, 1, 1 }
};
int dy[7][4] = { { 0, 1, 0, 1 }, { 0, 1, 2, 3 }, { 0, 0, 0, 0 },
{ 0, 1, 0, 0 }, { 0, 1, 2, 2 }, { 1, 1, 1, 0 }, { 0, 0, 1, 2 }
};
int first[] = { 0, 1, 3 };//æ¯ä¸ç±»ä¿ç½æ¯æ¹åçåå§ç¶æçç¼å·
int g[N][N];
int a[100000];
vector<P>pos;//ç¨ä¸ä¸ªvectorå­å¨æ¯æ¬¡æä½å®çææåæ 
int sx, sy, cur;//(sx,sy)è¡¨ç¤ºspecialÂ squareçåæ ï¼curè¡¨ç¤ºå½åçç¶æ(0~6çæä¸ç§)

void init(int id)//åå§åç¶æ
{
    pos.clear();
    sx = 4, sy = 9, cur = first[id];
    for (int i = 0; i < 4; i++)
        pos.push_back(P(sx + dx[cur][i], sy + dy[cur][i]));
}

bool inside(int x, int y)
{
    return x >= 1 && x <= 9 && y >= 1 && y <= 12;
}

bool can_move(int dx, int dy)
{
    int len = pos.size();
    for (int i = 0; i < len; i++)
    {
        int nx = pos[i].first + dx, ny = pos[i].second + dy;
        if (!inside(nx, ny) || g[nx][ny])return false;
    }
    return true;
}

bool can_rotate(int type)
{
    if (type == 1)
    {
        int goal = 3 - cur;
        for (int i = 0; i < 4; i++)
        if (!inside(sx + dx[goal][i], sy + dy[goal][i]) || g[sx + dx[goal][i]][sy + dy[goal][i]])return false;
    }
    else if (type == 2)
    {
        int goal = (cur == 6) ? 3 : cur + 1;
        for (int i = 0; i < 4; i++)
        if (!inside(sx + dx[goal][i], sy + dy[goal][i]) || g[sx + dx[goal][i]][sy + dy[goal][i]])return false;
    }
    return true;
}

void move(int dx, int dy)
{
    int len = pos.size();
    for (int i = 0; i < len; i++)
    {
        int nx = pos[i].first + dx, ny = pos[i].second + dy;
        pos[i] = P(nx, ny);
    }
    sx += dx, sy += dy;
}

void rotate(int type)
{
    if (!type)return;
    else if (type == 1)
    {
        cur = 3 - cur;  //æ´æ°ç¶æ
        int len = pos.size();
        pos.clear();
        for (int i = 0; i < 4; i++)
            pos.push_back(P(sx + dx[cur][i], sy + dy[cur][i]));
    }
    else if (type == 2)
    {
        cur = (cur == 6) ? 3 : cur + 1;
        pos.clear();
        for (int i = 0; i < 4; i++)
            pos.push_back(P(sx + dx[cur][i], sy + dy[cur][i]));
    }
}

void draw()
{
    int len = pos.size();
    for (int i = 0; i < len; i++)
    {
        int x = pos[i].first, y = pos[i].second;
        g[x][y] = 1;
    }
}

void operate(char op, int id)
{
    if (op == 'w')
    {
        if (can_rotate(id))rotate(id);
    }
    else if (op == 'a')
    {
        if (can_move(-1, 0))move(-1, 0);
    }
    else if (op == 's')
    {
        if (can_move(0, -1))move(0, -1);
    }
    else if (op == 'd')
    {
        if (can_move(1, 0))move(1, 0);
    }
}

int can_fall()
{
    int y;
    for (y = 1; y <= 12; y++)
    {
        int ok = 1;
        for (int i = 1; i <= 9; i++)
        if (!g[i][y]){ ok = 0; break; }
        if (ok)return y;
    }
    return 0;
}
int main()
{
    int T;
    int rnd = 0;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        string cmd;
        scanf("%d", &n);
        cin >> cmd;
        me(g); me(a); pos.clear();
        int len = cmd.length();
        int ans = 0, p = 0;
        for (int i = 0; i < n; i++)scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
        {
            init(a[i]);
            while (1)
            {
                if (p < len)
                    operate(cmd[p++], a[i]);
                if (can_move(0, -1)) move(0, -1);//ä¸è½ä¸è½
                else break;
            }
            draw();//ç»åºæç»çä½ç½®
            int q, ok;
            while ((q = can_fall())>0)//ç´å°æ²¡æå®æ´çä¸è¡æ¶æéåº
            {
                ans++;
                for (int i = 1; i <= 9; i++)
                {
                    g[i][q] = 0;
                    for (int j = q + 1; j <= 12; j++)
                    if (g[i][j])
                        g[i][j - 1] = 1, g[i][j] = 0;  //åªä¸è½ä¸æ ¼ãããä¸è¦å¤æ³
                }
            }
        }
        printf("Case %d: %d\n", ++rnd, ans);
    }
}


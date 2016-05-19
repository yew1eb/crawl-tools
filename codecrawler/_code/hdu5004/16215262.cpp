#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
#define pf printf
#define sf scanf
#define Fill(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 16;
const int M = 10;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
struct Point
{
    int x,y;
    Point(){}
    Point(int a,int b):x(a),y(b){};
};
char t[N][M],s[N][M];
bool v[N][M];
bool flag;
int n,ans[10];
queue<Point>q;
inline bool judge(int x,int y)
{
    if (x - 1 >= 0 && t[x - 1][y] == t[x][y]) return 0;
    if (y - 1 >= 0 && t[x][y - 1] == t[x][y]) return 0;
    return 1;
}
inline void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) s[i][j] = t[i][j];
}
inline bool check()
{
    char c = s[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (s[i][j] != c) return 0;
    return 1;
}
inline void find_color(int x,int y,bool ok[])
{
    while (!q.empty()) q.pop();
    q.push(Point(x,y)); char c = s[x][y];
    Fill(v,0);
    while (!q.empty())
    {
        Point p = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            x = p.x + dx[i]; y = p.y + dy[i];
            if (x >= 0 && x < N && y >= 0 && y < M)
            {
                if (s[x][y] == c && !v[x][y])
                {
                    q.push(Point(x,y));
                    v[x][y] = 1;
                }
                else if (s[x][y] != c) ok[s[x][y] - '0'] = 1;
            }
        }
    }
}
inline void paint(int x,int y,char c)
{
    while (!q.empty()) q.pop();
    q.push(Point(x,y));
    char tar = s[x][y];
    s[x][y] = c;
    while (!q.empty())
    {
        Point p = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            x = p.x + dx[i]; y = p.y + dy[i];
            if (x >= 0 && x < N && y >= 0 && y < M && s[x][y] == tar)
            {
                q.push(Point(x,y));
                s[x][y] = c;
            }
        }
    }
}
void dfs(int x,int y,int step)
{
    if (step > n) return;
    if (flag) return;
    if (check())
    {
        if (step == n) flag = 1;
        return;
    }
    if (step == n) return;
    bool ok[5] = {0,0,0,0,0};
    char tmp[16][10];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) tmp[i][j] = s[i][j];
    find_color(x,y,ok);
    for (int i = 1; i <= 4; i++)
        if (ok[i])
        {
            paint(x,y,i + '0');
            ans[step + 1] = i;
            dfs(x,y,step + 1);
            if (flag) return;
            for (int j = 0; j < N; j++)
                for (int k = 0; k < M; k++) s[j][k] = tmp[j][k];
        }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T; sf("%d",&T);
    for (int TT = 1; TT <= T; TT++)
    {
        sf("%d",&n);
        for (int i = 0; i < N; i++) sf("%s",s[i]);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) t[i][j] = s[i][j];
        flag = 0;
        pf("Case #%d:\n",TT);
        for (int i = 0; i <= N; i++)
        {
            if (flag) break;
            for (int j = 0; j < M; j++)
                if (judge(i,j))
                {
                    init();
                    dfs(i,j,0);
                    if (flag)
                    {
                        for (int k = 1; k <= n; k++) pf("%d %d %d\n",ans[k],i + 1,j + 1);
                        break;
                    }
                }
        }
    }
    return 0;
}

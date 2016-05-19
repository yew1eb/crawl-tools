#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct node
{
    int num[4];
    int step;
};
queue<node> q;
bool vis[10][10][10][10];
int ansnum[4];
int ans;
int dir[8][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{-1,0,0,0},{0,-1,0,0},{0,0,-1,0},{0,0,0,-1}};

void init()
{
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();
}

bool istrue(node x)
{
    if (x.num[0] == ansnum[0] && x.num[1] == ansnum[1] && x.num[2] == ansnum[2] && x.num[3] == ansnum[3])
        return true;
    return false;
}

bool judge(node x)
{
    if (vis[x.num[0]][x.num[1]][x.num[2]][x.num[3]]) return false;
    return true;
}

node change(node a, int b)
{
    a.step ++;

    if (b < 4)        // +
    {
        if (a.num[b] == 9) a.num[b] = 1;
        else a.num[b] ++;
    }
    else if (b < 8)    // -
    {
        if (a.num[b%4] == 1) a.num[b%4] = 9;
        else a.num[b%4] = a.num[b%4] - 1;
    }
    else    // æ¢
    {
        int tmp;
        b %= 4;
        tmp = a.num[b];
        a.num[b] = a.num[b+1];
        a.num[b+1] = tmp;
    }

    return a;
}

void bfs()
{
    node now, next;
    while (!q.empty())
    {
        now = q.front();
        q.pop();

        if (istrue(now))
        {
            ans = now.step;
            return ;
        }

        for (int i = 0; i < 11; i++)
        {
            next = change(now, i);
            if (judge(next))
            {
                vis[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        int a, b;
        node now;
        scanf("%d %d", &a, &b);

        for (int i=3; i>=0; i--)
        {
            ansnum[i] = a  % 10;
            now.num[i] = b % 10;
            a /= 10;
            b /= 10;
        }
        now.step = 0;
        q.push(now);
        vis[now.num[0]][now.num[1]][now.num[2]][now.num[3]] = true;

        bfs();

        printf("%d\n", ans);
    }
    return 0;
}

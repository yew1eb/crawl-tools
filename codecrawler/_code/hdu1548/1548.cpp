#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1 << 30;

int a[222];
bool vis[222];
int n;

struct point
{
    int now_floor, step;
};


int Bfs(int star, int end)
{
    memset(vis, 0, sizeof(vis));
    point q1, q2;
    queue <point> q;
    q1.now_floor = star - 1;
    q1.step = 0;
    q.push(q1);
    vis[q1.now_floor] = 1;

    while (!q.empty())
    {
        q2 = q.front();
        q.pop();

        if (q2.now_floor == end - 1)
        {
            return q2.step;
        }

        q1.now_floor = q2.now_floor + a[q2.now_floor];
        q1.step = q2.step + 1;
        if (q1.now_floor < n && q1.now_floor >= 0 && !vis[q1.now_floor])
        {

            q.push(q1);
            vis[q1.now_floor] = 1;
        }

        q1.now_floor = q2.now_floor - a[q2.now_floor];

        if (q1.now_floor >= 0 && q1.now_floor < n && !vis[q1.now_floor])
        {
            q.push(q1);
            vis[q1.now_floor] = 1;
        }
    }
    return -1;

}

int main()
{

    int i, j;
    int ans;
    int star, end;

    while (~scanf("%d", &n), n)
    {
        scanf("%d%d", &star, &end);
        for (i = 0; i < n; i++)
        {
            scanf("%d", a + i);
        }

        
        printf("%d\n", Bfs(star, end));

    }

    return 0;
}
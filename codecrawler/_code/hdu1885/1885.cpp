#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<queue>
#define MAXN 105
using namespace std;
char map[105][105];
bool v[105][105][20];
const int d[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int n,m,flag;
int sx,sy;
struct node
{
    int x,y;
    int step;
    int key;
};
int deal(char c)
{
    int n,j = 1;
    if(c >= 'a' && c <= 'z') n = c - 'a';
    else n = c - 'A';
    while(n--)
        j <<= 1;
    return j;
}
void bfs()
{
    memset(v,0,sizeof(v));
    queue <node> q;
    node s,temp;
    s.x = sx;
    s.y = sy;
    s.step = 0;
    s.key = 0;
    q.push(s);
    v[s.x][s.y][s.key] = 1;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(map[temp.x][temp.y] == 'X')
        {
            flag = 1;
            printf("Escape possible in %d steps.\n",temp.step);
            return;
        }
        for(int i = 0; i < 4; i ++)
        {
            s.x = temp.x + d[i][0];
            s.y = temp.y + d[i][1];
            s.key = temp.key;
            if(v[s.x][s.y][s.key] || s.x < 0 || s.x >= n || s.y < 0 || s.y >= m || map[s.x][s.y] == '#')
                continue;

            s.step = temp.step + 1;
            v[s.x][s.y][s.key] = 1;
            if(map[s.x][s.y]>='a'&&map[s.x][s.y]<='d')
            {
                int num = deal(map[s.x][s.y]);
                if((s.key&num) == 0)
                    s.key |= num;
                q.push(s);
            }
            else if(map[s.x][s.y]>='A'&&map[s.x][s.y]<='D')
            {
                int num = deal(map[s.x][s.y]);
                if(s.key&num)
                    q.push(s);
            }
            else q.push(s);
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m),(m+n))
    {
        for(i = 0; i < n; i ++)
        {
            scanf("%s",map[i]);
            for(j = 0; j < m; j ++)
            {
                if(map[i][j] == '*')
                    sx = i, sy = j, map[i][j] = '.';
                else if(isalpha(map[i][j]))
                {
                    switch(map[i][j])
                    {
                        case 'G': map[i][j] = 'A'; break;
                        case 'g': map[i][j] = 'a'; break;
                        case 'Y': map[i][j] = 'C'; break;
                        case 'y': map[i][j] = 'c'; break;
                        case 'R': map[i][j] = 'D'; break;
                        case 'r': map[i][j] = 'd'; break;
                        default: break;
                    }
                }
            }
        }
        flag = 0;
        bfs();
        if(!flag) printf("The poor student is trapped!\n");
    }
    return 0;
}
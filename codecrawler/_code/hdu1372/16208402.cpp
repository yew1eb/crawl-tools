#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int step;
int to[8][2] = {-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1};//éªå£«ç§»å¨ç8ä¸ªæ¹ä½
int map[10][10],ex,ey;
char s1[5],s2[5];

struct node
{
    int x,y,step;
};

int check(int x,int y)
{
    if(x<0 || y<0 || x>=8 || y>=8 || map[x][y])
    return 1;
    return 0;
}

int bfs()
{
    int i;
    queue<node> Q;
    node p,next,q;
    p.x = s1[0]-'a';
    p.y = s1[1]-'1';
    p.step = 0;
    ex = s2[0]-'a';
    ey = s2[1]-'1';
    memset(map,0,sizeof(map));
    map[p.x][p.y] = 1;
    Q.push(p);
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        if(q.x == ex && q.y == ey)
        return q.step;
        for(i = 0;i<8;i++)
        {
            next.x = q.x+to[i][0];
            next.y = q.y+to[i][1];
            if(next.x == ex && next.y == ey)
            return q.step+1;
            if(check(next.x,next.y))
            continue;
            next.step = q.step+1;
            map[next.x][next.y] = 1;
            Q.push(next);
        }
    }
    return 0;
}

int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,bfs());
    }
    return 0;
}

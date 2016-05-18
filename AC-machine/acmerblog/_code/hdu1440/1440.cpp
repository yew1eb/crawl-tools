#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct Point
{
    int x;
    int y;
};
Point start,end;

int disx[8] = {-2,-1,1,2,2,1,-1,-2};
int disy[8] = {1,2,2,1,-1,-2,-2,-1};

int dis[8][8];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
    char s[4],e[4];
    Point nex,temp;
    while(scanf("%s %s",s,e) == 2)
    {
        start.x = s[1] - '1';
        start.y = s[0] - 'a';
        end.x = e[1] - '1';
        end.y = e[0] - 'a';
        memset(dis,-1,sizeof(dis));
        queue<Point> p;
        p.push(start);

        dis[start.x][start.y] = 0;

        if(start.x == end.x && start.y == end.y)
        {
            printf("To get from %s to %s takes 0 knight moves.\n",s,e);
            continue;
        }
        while(!p.empty())
        {
            nex = p.front();
            p.pop();
            for(int i=0;i<8;i++)
            {
                int x = nex.x + disx[i];
                int y = nex.y + disy[i];
                if(x>=0 && x<8 && y>=0 && y<8 && dis[x][y] == -1)
                {
                    dis[x][y] = dis[nex.x][nex.y] + 1;
                    if(end.x == x && end.y == y)
                    {
                        printf("To get from %s to %s takes %d knight moves.\n",s,e,dis[x][y]);
                        break;
                    }
                    temp.x = x;
                    temp.y = y;
                    p.push(temp);
                }
            }
        }
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct Point
{
    int x;
    int y;
    int z;
};

Point s,e;

int map[35][35][35];
int vis[35][35][35];
int dist[35][35][35];

int disx[6] = {-1,0,1,0,0,0};
int disy[6] = {0,1,0,-1,0,0};
int disz[6] = {0,0,0,0,1,-1};
int l,r,c;

int bfs()
{
    queue<Point> p;
    Point temp,nex;
    p.push(s);
    vis[s.x][s.y][s.z] = 1;

    while(!p.empty())
    {
        temp = p.front();
        p.pop();
        for(int i=0; i<6; i++)
        {

            int tempx = temp.x + disx[i];
            int tempy = temp.y + disy[i];
            int tempz = temp.z + disz[i];

            //注意我这里把x作为第一维，y作为第二维，z作为第三维
            if(tempx>=1 && tempx<=l && tempy>=1 && tempy<=r && tempz>=1 && tempz<=c)
            {
                if(vis[tempx][tempy][tempz] == 0 && map[tempx][tempy][tempz] == 1)
                {
                    vis[tempx][tempy][tempz] = 1;
                    nex.x = tempx,nex.y = tempy,nex.z = tempz;
                    dist[nex.x][nex.y][nex.z] = dist[temp.x][temp.y][temp.z] + 1;
                    if(nex.x == e.x && nex.y == e.y && nex.z == e.z)
                    {
                        return dist[nex.x][nex.y][nex.z];
                    }
                    p.push(nex);
                }
            }
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif

    char str[35];
    while(scanf(" %d %d %d",&l,&r,&c)!=EOF && l!=0 && r!=0 && c!=0)
    {

        memset(vis,0,sizeof(vis));
        memset(dist,0,sizeof(dist));
        memset(map,0,sizeof(map));

        for(int i = 1; i<=l; i++)
        {
            for(int j=1; j<=r; j++)
            {
                scanf(" %s",str);
                for(int k=0; k<strlen(str); k++)
                {
                    if(str[k] == '#')
                    {
                        map[i][j][k+1] = 0;
                    }
                    else if(str[k] == '.')
                    {
                        map[i][j][k+1] = 1;
                    }
                    else if(str[k] == 'S')
                    {
                        map[i][j][k+1] = 1;
                        s.x = i,s.y = j,s.z = k+1;
                    }
                    else if(str[k] == 'E')
                    {
                        map[i][j][k+1] = 1;
                        e.x = i,e.y = j,e.z = k+1;
                    }
                }
            }
        }

        int ans = bfs();
        if(ans == 0)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n",ans);
        }
    }
    return 0;
}
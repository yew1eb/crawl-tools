#include <iostream>

#include <queue>

#include <string>

using namespace std;

int n,m,t,ans;

int dir[4][2] = {1,0,-1,0,0,-1,0,1};

char map[10][10];

bool vis[2][10][10];

struct node

{

   int x,y,t,k;

   int rox[64],roy[64];

};

node start,end,temp,in;

queue <node> Q;

void dfs(int deep)

{

       if(deep > ans) return ;

    int i,j,minstep = -1;

    node q;

    while(!Q.empty())//清空队列

       Q.pop();

       Q.push(start);//起始位置入队

    memset(vis,false,sizeof(vis));//初始化标记数组

       vis[0][start.x][start.y] = true;//标记起始点为真

       while(!Q.empty())//从起点开始寻找一条路径

    {

              q = Q.front();

        Q.pop();

        if(q.t > t) 

                     continue;

        if(q.k && map[q.x][q.y] == 'E')//找到出口

        {

                     minstep = q.t;

                     break;

        }

        for(i = 0;i < 4;i++)//分别从四个方向开始扫描

        {

                     int xx = q.x + dir[i][0];

            int yy = q.y + dir[i][1];

            if(xx < 0 || xx >= n || yy < 0 || yy >= m || map[xx][yy] == '#')

                            continue;//越界或碰到墙

            if(map[xx][yy] == 'J')

                            in.k = 1;//碰到珠宝

            else 

                            in.k = q.k;//没有碰到则标记为前一个状态

            if(!vis[in.k][xx][yy])

            {

                            vis[in.k][xx][yy] = true;

                for(j = 1;j <= q.t;j++)

                {

                                   in.rox[j] = q.rox[j];

                    in.roy[j] = q.roy[j];

                }

                            in.x = xx;

                            in.y = yy;

                            in.t = q.t + 1;

                in.rox[in.t] = xx;

                in.roy[in.t] = yy;

                Q.push(in);

                     }

              }

       }

    if(minstep == -1)

    {// minstep == -1 表明在t时间内即使不用设置关卡也不能成功逃离

              if(deep < ans)

                     ans = deep;

        return ;

    }

       char cc;

    for(i = 1;i < q.t;i++)

    {

              cc = map[q.rox[i]][q.roy[i]];

              if(cc == 'S' || cc == 'E') 

                     continue;

              map[q.rox[i]][q.roy[i]] = '#';

              dfs(deep+1);

              map[q.rox[i]][q.roy[i]] = cc ;

       }

}

void inits()

{

       int i,j;

    memset(vis,false,sizeof(vis));

    for(i = 0;i < n;i++)

              for(j = 0;j < m;j++)

              {

                     if(map[i][j] == 'S')

                     {

                            start.x = i;start.y = j;

                            start.t = 0;start.k = 0;

                            break;

                     }

              }

    ans = 4;

    dfs(0);

    printf("%d/n",ans);

}

int main()

{

       int i,cas;

    scanf("%d",&cas);

    while(cas--)

    {

              scanf("%d%d%d",&n,&m,&t);

        for(i = 0;i < n;i++)

           scanf("%s",map[i]);

        inits();

    }

    return 0;

}
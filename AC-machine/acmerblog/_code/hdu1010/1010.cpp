http://acm.hdu.edu.cn/showproblem.php?pid=1010
大致题意：给一幅图，有起点有墙有终点，问能不能在刚好t秒的时间走到终点
DFS + 多重剪枝(奇偶性剪枝)
一开始果断DFS，交上去TLE了。。。用了好几重的剪枝才过。。。。
所以不要小看剪枝，往往优化个成百上千倍
#include<iostream>
#include<cmath>
using namespace std;
char map[10][10];
int flag, Xnum, Sx, Sy, Dx, Dy;
int n, m, t;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void DFS(int x, int y, int time)
{
    if (x<=0 || x>n || y<=0 || y>m) return;
    if (flag == 1) return;  //1.马上中断
    if (x == Dx && y == Dy && time == t)
    {
        if(time == t)
            flag = 1;
        return;
    }

    int temp = (t - time) - abs(x - Dx) - abs(y - Dy);//2.奇偶性剪枝
    if(temp<0 || temp & 1)  return;  

    for (int i = 0; i<4; i++)
    {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        if (map[x1][y1] != 'X')
        {
            map[x1][y1] = 'X';
            DFS(x1, y1, time + 1);
            map[x1][y1] = '.';
        }
    }
    return;
}


int main()
{
    while (cin>>n>>m>>t)
    {
        if(n==0&&m==0&&t==0) break;
        Xnum = 0;
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                cin>>map[i][j];
                if (map[i][j] == 'S')
                {
                    Sx = i;
                    Sy = j;
                }
                if (map[i][j] == 'D')
                {
                    Dx = i;
                    Dy = j;
                }
                if (map[i][j] == 'X')
                    Xnum ++;
            }
        }
        flag = 0;
        map[Sx][Sy] = 'X';

        if (n * m - Xnum <= t)//3.提前判断t过大的情况避免再去搜，写上由500MS降到46MS
        {
            cout<<"NO"<<endl;
            continue;
        }
        DFS(Sx, Sy, 0);
        if (flag)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0;
}
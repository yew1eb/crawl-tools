#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
char map[10][10];
int t;
int maxn;
int sum;
int move[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
bool yescan(int x,int y)
{
    if(x < 8 && x >= 0 && y < 8 && y >= 0)
        return true;
    return false;
}
void DFS(int xx,int yy)
{
    for(int i = 0;i < 8;i ++)
    {
        int flag = 0;
        int x = xx + move[i][0];int y = yy + move[i][1];
        while(yescan(x,y) == 1)
        {
            if(map[x][y] == '*')
                break ;
            if(map[x][y] == 'D')
            {
                sum += flag;
                break ;
            }
            if(map[x][y] == 'L')
            {
                flag ++;
                x += move[i][0];
                y += move[i][1];
            }
        }
    }
    return ;
}
int main()
{
    scanf("%d",&t);
    for(int k = 1;k <= t;k ++)
    {
        memset(map,0,sizeof(map));
        for(int i = 0;i < 8;i ++)
           scanf("%s",map[i]);
        maxn = 0;
        printf("Case %d: ",k);
        for(int i = 0;i < 8;i ++)
           for(int j = 0;j < 8;j ++)
           {
               if(map[i][j] == '*')
               {
                   sum = 0;
                   DFS(i,j);
                   if(sum > maxn)
                      maxn = sum;
               }
           }
           printf("%d\n",maxn);
    }
    return 0;
}
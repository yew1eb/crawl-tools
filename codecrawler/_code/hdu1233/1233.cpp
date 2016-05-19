/************************************************************************/
/*     
        hdu  还是畅通工程
        最小生成树
        题目大意：求连通这些村庄最少的建设公路长度
        解题思路：最小生成树，所有的这些村子放在一个图中，找出一个最小生成树
*/
/************************************************************************/

#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N = 101;
int map[N][N];
int mark[N];
int i,j,n;

int prim()
{
    int sum = 0;
    int min,t = n,k;
    while(--t)
    {
        min = 100000;
        for (i = 2; i <= n; i++)
        {
            if(mark[i] != 1 && min > map[1][i])
            {
                min = map[1][i];
                k = i;
            }
        }
        sum += min;
        mark[k] = 1;
        for (i = 2; i <= n; i++)
        {
            if(mark[i] != 1 && map[k][i] < map[1][i])
            map[1][i] = map[k][i];
        }
    }
    return sum;
}

int main()
{
    int x,y,len,num;
    while(scanf("%d",&n) && n != 0)
    {
        num = n*(n-1)/2;
        memset(map,0,sizeof(map));
        for (i = 1; i <= num; i++)
        {
            scanf("%d%d%d",&x,&y,&len);
            map[x][y] = map[y][x] = len;
        }
        memset(mark,0,sizeof(mark));
        printf("%d\n",prim());
    }
    return 0;
}
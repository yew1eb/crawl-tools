#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 510
bool flag[MAX];
int map[MAX][MAX],mark[MAX];
int k,b,g;
bool dfs(int x)
{

    for(int i=1;i<=b;i++)
    {
        if(!map[x][i]||flag[i])//如果这两点没边 或有边但被标记过了就继续循环
            continue;
        flag[i]=1;   
        if(!mark[i]||dfs(mark[i])) //如果该点是孤立点或者不是孤立点时就搜索该点对应女生的增广路
        {
            mark[i]=x;
            return 1;
        }
    }
    return 0;
}
int find()
{
    int i,sum=0;
    memset(mark,0,sizeof(mark));
    for(i=1;i<=g;i++)
    {
        memset(flag,0,sizeof(flag));
        if(dfs(i))
            sum++;
    }
    return sum;
}
int main()
{
    int x,y;
    while(scanf("%d",&k)!=EOF)
    {
        if(k==0) break;
        scanf("%d%d",&g,&b);
        memset(map,0,sizeof(map));
        for(int i=1;i<=k;i++)
            {
                scanf("%d%d",&x,&y);
                map[x][y]=1;
            }
        printf("%d\n",find());
    }
    return 0;
}
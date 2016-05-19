#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<algorithm>
#define N 15
using namespace std;
int map[N][N],v1[15],v2[15];
int flag,n,ok;
struct node
{
    int x,y;
}s[6];
void judge1()//判断行和列
{
    int i,j;
    for(i = 0 ; i < 9 ; i ++)
    {
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        for(j = 0 ; j < 9 ; j ++)
        {
            if(v1[map[i][j]])
            {
                ok = 0;
                return;
            }
            else
            v1[map[i][j]] = 1;
            if(v2[map[j][i]])
            {
                ok = 0;
                return;
            }
            else
            v2[map[j][i]] = 1;
        }
    }
}
void judge2()//判断3*3矩形
{
    int i,j,x,y;
    for(i = 0 ; i <= 6 ; i += 3 )
    {
        for(j = 0 ; j <= 6 ; j += 3)
        {
            memset(v1,0,sizeof(v1));
            for(x = 0 ; x < 3 ; x ++)
            for(y = 0 ; y < 3 ; y ++)
            {
                if(v1[map[x + i][y + j]])
                {
                    ok = 0;
                    return ;
                }
                else v1[map[x + i][y + j]] = 1;
            }
        }
    }
}
void print()
{
    ok = 1;
    judge1();
    if(!ok)
    {
        printf("Could not complete this grid.\n");
        return ;
    }
    ok = 1;
    judge2();
    if(!ok)
      printf("Could not complete this grid.\n");
    else
    {
        for(int i = 0 ; i < 9 ; i ++)
        {
            for(int j = 0 ; j < 9 ; j ++)
            printf("%d",map[i][j]);
            printf("\n");
        }
    }
}
bool judge(int cur,int t)
{
    int i,j;
    for(i = 0 ; i < 9 ; i ++)
      if(map[ s[cur].x ][i] == t || map[i][ s[cur].y ] == t)
       return 0;
    int x = s[cur].x/3 * 3;
    int y = s[cur].y/3 * 3;
    for(i = 0 ; i < 3 ; i ++)
      for(j = 0 ; j < 3 ; j ++)
        if(map[x + i][y + j] == t) return 0;
    return 1;
}
void dfs(int cur)
{
    if(cur == n)
    {
        flag = 1;
        print();
        return ;
    }
    if(flag) return ;
    for(int i = 1 ; i <= 9 ; i ++)
    if(judge(cur,i) && !flag)
    {
        map[s[cur].x][s[cur].y] = i;
        dfs(cur + 1);
        map[s[cur].x][s[cur].y] = 0;
    }
}
int main()
{
    int i,j,T;
    char a[15];
    scanf("%d",&T);
    while(T--)
    {
        n = 0;
        for(i = 0 ; i < 9 ; i ++)
        {
            scanf("%s",a);
            for(j = 0 ; j < 9 ; j ++)
            {
                map[i][j] = a[j] - '0';
                if(!map[i][j])
                {
                    s[n].x = i;
                    s[n].y = j;
                    n ++;
                }
            }
        }
        flag = 0;
        dfs(0);
        if(!flag)
         printf("Could not complete this grid.\n");
        if(T) printf("\n");
    }
    return 0;
}
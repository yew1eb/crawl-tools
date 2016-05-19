#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char Map[20][20];
int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}},visit[20][20],ans,ant;
void dfs(int x,int y)
{
    int tx,ty,i;
    visit[x][y]=ans;
    for(i=0; i<4; i++)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if(Map[tx][ty]=='x')
            continue;
        if(tx<0||tx>=9||ty<0||ty>=9||visit[tx][ty]==ans)
            continue;
        if(Map[tx][ty]=='.')
        {
            ant++;
            visit[tx][ty]=ans;
        }
        else
        {
            dfs(tx,ty);
        }
    }
}
int fuck()
{
    int i,j;
    ans=0;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(Map[i][j]=='o'&&!visit[i][j])
            {
                ans++;
                ant=0;
                dfs(i,j);
                if(ant==1)
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t,i,k;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    k=1;
    getchar();
    while(t--)
    {
        memset(visit,0,sizeof(visit));
        for(i=0; i<9; i++)
        {
            scanf("%s",Map[i]);
        }
        printf("Case #%d: ",k++);
        if(fuck())
            printf("Can kill in one move!!!\n");
        else
            printf("Can not kill in one move!!!\n");
    }
    return 0;
}

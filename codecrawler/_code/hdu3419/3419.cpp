#include<stdio.h>
#include<string.h>
#define N 10
int vis[N],mark[N][N][N];
int a,b,c;
int x,y,z;
int cnt;
void dfs(int t,int f,int k)
{
    if(k==1&&f==a)
        x=t,f=0,k++,t=0;
    else if(k==2&&f==b)
        y=t,f=0,k++,t=0;
    else if(k==3&&f==c)
    {
        z=t;
        if(x*y==z) cnt++;
        return ;
    }
    for(int i=1;i<=9;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(t*10+i,f+1,k);
            vis[i]=0;
        }
    }
    return ;
}
int main()
{
    memset(mark,0,sizeof(mark));
    while(scanf("%d%d%d",&a,&b,&c),a+b+c)
    {
        if(a+b<c)
        {
            printf("0\n");
            continue;
        }
        if(a>c||b>c)
        {
            printf("0\n");
            continue;
        }
        if(a+b-c>1)
        {
            printf("0\n");
            continue;
        }
        if(mark[a][b][c])
        {
            printf("%d\n",mark[a][b][c]);
            continue;
        }
        cnt=0;
        memset(vis,0,sizeof(vis));
        dfs(0,0,1);
        mark[a][b][c]=cnt;
        printf("%d\n",mark[a][b][c]);
    }
    return 0;
}
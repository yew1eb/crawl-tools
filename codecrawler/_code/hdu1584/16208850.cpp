#include <stdio.h>
#include <string.h>

int a[15],vis[15],ans;

int abs(int x)
{
    if(x<0)
    return -x;
    return x;
}

void dfs(int cnt,int sum)
{
    int i,j;
    if(sum>=ans)
    return ;
    if(cnt == 9)
    {
        ans = sum;
        return ;
    }
    for(i = 1;i<10;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            for(j = i+1;j<=10;j++)
            {
                if(!vis[j])
                {
                    dfs(cnt+1,sum+abs(a[i]-a[j]));
                    break;
                }
            }
            vis[i] = 0;
        }
    }
}

int main()
{
    int t,i,x;
    scanf("%d",&t);
    while(t--)
    {
        for(i = 1;i<=10;i++)
        {
            scanf("%d",&x);
            a[x] = i;//çé¢ä¸ºxççå¨ç¬¬iä¸ªä½ç½®
        }
        memset(vis,0,sizeof(vis));
        ans = 10000000;
        dfs(0,0);
        printf("%d\n",ans);
    }

    return 0;
}

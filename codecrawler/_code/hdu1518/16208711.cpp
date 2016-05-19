#include <stdio.h>
#include <string.h>
int n,sum,l;
int a[30],vis[30];
int flag;

void dfs(int bian,int l,int k)
{
    int i;
    if(bian==5)
    {
        flag = 1;
        return ;
    }
    if(l == sum)
    {
        dfs(bian+1,0,0);
        if(flag)
            return ;
    }
    for(i = k; i<n; i++)
    {
        if(!vis[i] && l+a[i]<=sum)
        {
            vis[i] = 1;
            dfs(bian,a[i]+l,i+1);
            if(flag)
                return;
            vis[i] = 0;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i;
        sum = 0;
        scanf("%d",&n);
        for(i = 0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%4!=0)
        {
            printf("no\n");
            continue;
        }
        sum = sum/4;
        for(i = 0; i<n; i++)
        {
            if(a[i]>sum)
                break;
        }
        if(i!=n)
        {
            printf("no\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        flag = 0;
        dfs(1,0,0);
        if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
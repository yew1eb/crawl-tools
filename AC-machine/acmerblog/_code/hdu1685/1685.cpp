#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 16
using namespace std;

int n,m,ans,depth,flag;
int a[maxn];

bool isok()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(a[i]!=i) return false ;
    }
    return true ;
}
int h()
{
    int i,j,t=0;
    for(i=0;i<=n;i++)
    {
        if(a[i]+1!=a[i+1]) t++;
    }
    return t;
}
void dfs(int d)
{
    if(isok())
    {
        flag=1;
        return ;
    }
    if(flag||(d-1)*3+h()>depth*3) return ;  // 实现IDA*
    int i,j,k,p;
    int tmp[maxn];
    for(i=1; i<=n; i++)    // 模拟操作
    {
        for(j=i; j<=n; j++)
        {
            for(k=1; k<=i-1; k++)
            {
                memcpy(tmp,a,sizeof(tmp));
                for(p=k; p<=i-1; p++)
                {
                    a[p+j-i+1]=tmp[p];
                }
                for(p=i; p<=j; p++)
                {
                    a[p-i+k]=tmp[p];
                }
                dfs(d+1);
                memcpy(a,tmp,sizeof(tmp));
            }
            for(k=j+1; k<=n; k++)
            {
                memcpy(tmp,a,sizeof(tmp));
                for(p=j+1; p<=k; p++)
                {
                    a[p-j-1+i]=tmp[p];
                }
                for(p=i; p<=j; p++)
                {
                    a[p+k-j]=tmp[p];
                }
                dfs(d+1);
                memcpy(a,tmp,sizeof(tmp));
            }
        }
    }
}
int main()
{
    int i,j,t,flg;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        flg=1;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=i) flg=0;
        }
        a[0]=0,a[n+1]=n+1;
        if(flg)
        {
            printf("0\n");
            continue ;
        }
        flag=depth=0;
        while(!flag)
        {
            depth++;
            dfs(1);
            if(depth>=4) break ;
        }
        if(flag) printf("%d\n",depth);
        else printf("5 or more\n");
    }
    return 0;
}
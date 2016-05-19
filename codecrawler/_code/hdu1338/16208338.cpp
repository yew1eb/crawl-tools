#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int a[60],vis[1000+5];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int ca=1;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
            vis[a[i]]=1;
        }
        sort(a+1,a+1+m,cmp);
        int key,sum=0;
        for(int i=n*m;i>=1;i--)
        {
            if(!vis[i])
            {
                key=i;
                break;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(a[i]>=key) 
            {
                sum++;
            }
            else
            {
                vis[key]=1;    
            }
            for(int j=n*m;j>=1;j--)
            {
                if(!vis[j])
                {
                    key=j;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",ca++,sum);
    }
    return 0;
}
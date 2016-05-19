#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#define nn 510
#define inff 0x3fffffff
typedef long long LL;
using namespace std;
int n;
char tu[nn][nn];
bool vis[nn];
int a[nn];
int ans[nn];
int main()
{
    int i,j,k;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",tu[i]);
        }
        memset(a,0,sizeof(a));
        memset(vis,false,sizeof(vis));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(tu[i][j]=='1')
                    a[i]++;
            }
        }
        int la=0;
        int mx,id;
        for(i=0;i<n;i++)
        {
            mx=-inff;
            for(j=0;j<n;j++)
            {
                if(!vis[j]&&a[j]>mx)
                {
                    mx=a[j];
                    id=j;
                }
            }
            vis[id]=true;
            ans[la++]=id;
            for(k=0;k<n;k++)
            {
                if(tu[k][id]=='1')
                    a[k]--;
            }
        }
        for(i=0;i<la;i++)
        {
            printf("%d%c",ans[i]+1,i==la-1?'\n':' ');
        }
    }
    return 0;
}

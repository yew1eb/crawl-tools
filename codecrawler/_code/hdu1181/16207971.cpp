#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct
{
    char x,y;
}a[10000];
int vis[10000],flag,k,l;
char s[10000];
void dfs(int cur)
{
    if(a[cur].y=='m')
    {
        flag=1;return;
    }
    else
    {
        int i;
        for(i=0;i<k;i++)
        {
            if(!vis[i]&&a[cur].y==a[i].x)
            {
                vis[i]=1;
                dfs(i);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='0')
        {
            printf("No\n");
            continue;
        }
        k=flag=0;
        l=strlen(s);
        a[k].x=s[0];
        a[k].y=s[l-1];
        k++;
        while(scanf("%s",s)!=EOF)
       {
            if(s[0]=='0')
            break;
            int l=strlen(s);
            a[k].x=s[0];
            a[k].y=s[l-1];
            k++;
        }

        int i;
        for(i=0;i<k;i++)
        {
            if(a[i].x=='b')
            {
                memset(vis,0,sizeof(vis));
                vis[i]=1;
                dfs(i);
            }
            if(flag)
            break;
        }
        printf("%s\n",flag?"Yes.":"No.");
    }
    return 0;
}

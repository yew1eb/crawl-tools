# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <iostream>
using namespace std;
struct node
{
    int x1;
    int x2;
    char x[5];
};
struct node a[100010];
int map[110][110];
int n,m,k;
bool judge (int xx1,int yy1)
{
    if(xx1<1||xx1>n||yy1<1||yy1>m)
        return 0;
    return 1;
}
int dfs(int x,int y,int cot)
{
    int i,j;
    int fx,fy;
    if(cot==k)
        return true;
    for(i=1; i<a[cot].x1; i++)
    {
        if(a[cot].x[0]=='R')
            fx=x,fy=y+i;
        else if(a[cot].x[0]=='L')
            fx=x,fy=y-i;
        else if(a[cot].x[0]=='U')
            fx=x-i,fy=y;
        else
            fx=x+i,fy=y;
        if(map[fx][fy])
            return 0;
        if(!judge(fx,fy))
            return 0;
    }
    if(a[cot].x[0]=='R')
    {
        for(i=a[cot].x1; i<=a[cot].x2; i++)
        {
            fy=y+i;
            fx=x;
            if(!judge(fx,fy)||map[fx][fy])
                break;
            if(dfs(fx,fy,cot+1))
                return 1;
        }
    }
    if(a[cot].x[0]=='L')
    {
        for(i=a[cot].x1; i<=a[cot].x2; i++)
        {
            fy=y-i;
            fx=x;
            if(!judge(fx,fy)||map[fx][fy])
                break;
            if(dfs(fx,fy,cot+1))
                return 1;
        }
    }
    if(a[cot].x[0]=='U')
    {
        for(i=a[cot].x1; i<=a[cot].x2; i++)
        {
            fy=y;
            fx=x-i;
            if(!judge(fx,fy)||map[fx][fy])
                break;
            if(dfs(fx,fy,cot+1))
                return 1;
        }
    }

    if(a[cot].x[0]=='D')
    {
        for(i=a[cot].x1; i<=a[cot].x2; i++)
        {
            fy=y;
            fx=x+i;
            if(!judge(fx,fy)||map[fx][fy])
                break;
            if(dfs(fx,fy,cot+1))
                return 1;
        }
    }
    return 0;
}
int main()
{
    int t,i,j,cot1;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d%d",&n,&m);
            memset(map,0,sizeof(map));
            for(i=1; i<=n; i++)
                for(j=1; j<=m; j++)
                    scanf("%d",&map[i][j]);
            k=0;
            while(1)
            {
                getchar();
                scanf("%d%d",&a[k].x1,&a[k].x2);
                if(a[k].x1==0&&a[k].x2==0)
                    break;
                cin>>a[k].x;
                k++;
            }
            cot1=0;
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    if(map[i][j]==0)
                    {
                        if(dfs(i,j,0))
                            cot1++;
                    }
                }
            }
            printf("%d\n",cot1);
        }
    }
    return 0;
}

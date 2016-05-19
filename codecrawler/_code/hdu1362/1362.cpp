#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 110
using namespace std;

int n,m,flag,cnt;
int a[15],b[15];
bool mp[maxn][maxn];

void showmap()                // 中间输出函数  方便debug
{
    int i,j;
    printf("\n");
    for(i=1; i<=2*n; i++)
    {
        for(j=1; j<=4*n; j++)
        {
            printf("%d",mp[i][j]);
        }
        printf("\n");
    }
}
void presolve()
{
    int i,j;
    sort(a+1,a+m+1);
    cnt=0;
    for(i=1; i<=m; i++)
    {
        if(a[i]>=2*n) break;
        for(j=1; j<=cnt; j++)
        {
            if(a[i]%b[j]==0) break;
        }
        if(j==cnt+1) b[++cnt]=a[i];
    }
}
void init()
{
    int i,j,temp;
    memset(mp,1,sizeof(mp));
    for(i=1; i<=n; i++)
    {
        temp=2*n+1+(i-1)*2;
        for(j=1; j<=temp; j++)
        {
            mp[i][j]=0;
        }
    }
    for(i=n+1; i<=2*n; i++)
    {
        for(j=4*n; j>1+(i-n-1)*2; j--)
        {
            mp[i][j]=0;
        }
    }
}
bool isok(int u,int v,int k)
{
    int i,j;
 //   printf("u:%d v:%d k:%d\n",u,v,k);
    if(v%2==0)
    {
        for(i=u+b[k]-1;i>=u;i--)
        {
            for(j=v+2*(b[k]-1);j>=v+2*(b[k]-1)-2*(b[k]+u-1-i);j--)
            {
                if(mp[i][j])
                {
  //                  printf("i:%d j:%d\n",i,j);
                    return false;
                }
            }
        }
    }
    else
    {
        for(i=u;i<u+b[k];i++)
        {
            for(j=v;j<v+1+2*(i-u);j++)
            {
                if(mp[i][j]) return false;
            }
        }
    }
    return true;
}
void mark(int u,int v,int k,int flag1)
{
    int i,j;
    if(v%2==0)
    {
        for(i=u+b[k]-1;i>=u;i--)
        {
            for(j=v+2*(b[k]-1);j>=v+2*(b[k]-1)-2*(b[k]+u-1-i);j--)
            {
                if(flag1) mp[i][j]=1;
                else mp[i][j]=0;
            }
        }
    }
    else
    {
        for(i=u;i<u+b[k];i++)
        {
            for(j=v;j<v+1+2*(i-u);j++)
            {
                if(flag1) mp[i][j]=1;
                else mp[i][j]=0;
            }
        }
    }
}
void dfs(int x,int y)
{
    int i,j;
    if(flag) return ;
 //   showmap();
 //   printf("x:%d y:%d\n",x,y);
    if(x==2*n&&y>4*n||x>2*n)
    {
        flag=1;
        return ;
    }
    if(y>4*n) dfs(x+1,1);
    else if(mp[x][y])             // 加上else  不然会死循环  想一想 为什么
    {
        for(j=y+1; j<=4*n; j++)
        {
            if(mp[x][j]==0) break;
        }
        dfs(x,j);
    }
    else
    {
        for(i=1; i<=cnt; i++)
        {
            if(isok(x,y,i))
            {
                mark(x,y,i,1);     // 标记
                dfs(x,y+1);
                mark(x,y,i,0);     // 取消标记
            }
            else break;
        }
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d%d",&n,&m);
        for(i=1; i<=m; i++)
        {
            scanf("%d",&a[i]);
            if(n%a[i]==0) flag=1;
        }
        if(flag)  printf("YES\n");      // 预处理  三角形的边长是六边形约数则一定满足条件
        else
        {
            presolve();                 // 预处理
            init();
            showmap();
            dfs(1,1);
            if(flag)  printf("YES\n");
            else printf("NO\n");
        }
    }
}
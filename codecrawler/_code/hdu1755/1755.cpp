#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 50005
#define LL __int64

using namespace std;

LL st[N],total,h[15],n,flag[15];
LL Dp[105][105],m;

void Dfs(int x,LL num)//递归求所有的组合
{
    if(x>=n)
    {
        st[total++]=num;
        return;
    }
    int i,k=-1;
    if(num==0)k=0;
    for(i=0;i<n;i++)
    {
        if(!flag[i] && h[i]!=k)
        {
            flag[i]=1;
            Dfs(x+1,num*10+h[i]);
            flag[i]=0;
            k=h[i];
        }
    }
}

void make()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        flag[i]=0;
        scanf("%I64d",&h[i]);
    }
    sort(h,h+n);//排序
    total=0;
    Dfs(0,0);
    memset(Dp,-1,sizeof(Dp));//初始化
    for(i=0;i<total;i++)
    {
        for(j=1;j<=100;j++)
        {
            k=st[i]%j;
            if(Dp[j][k]==-1 || Dp[j][k]>st[i])
            {
                Dp[j][k]=st[i];//预处理
            }
        }
    }
    LL x,y;
    while(m--)//询问
    {
        scanf("%I64d%I64d",&x,&y);
        if(y==1)printf("%I64d\n",Dp[1][0]);
        else
        {
            x%=y;
            x=y-x;//互补
            if(x==y)x=0;
            if(Dp[y][x]==-1)printf("None\n");
            else printf("%I64d\n",Dp[y][x]);
        }
    }
}
int main()
{
    while(scanf("%I64d%I64d",&n,&m)==2)
    {
        make();
    }
    return 0;
}
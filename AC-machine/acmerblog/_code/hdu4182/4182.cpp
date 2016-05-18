#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define INF (1<<29)
int n,m;
int x[20],y[20],c[20];
int state[1<<17],cnt;//cnt表示合法状态有多少个,state[i]=x,表示第i个合法状态是x
bool isok[1<<17];
int dp1[1<<17],cost[17][1<<17];
int dist[20][20];
int np[1<<17];
bool good(int st)
{
    int sum=0;
    for(int i=0;i<n;i++)if(st&(1<<i))
        sum +=c[i];
    return sum<=m;
}
int solve_1()
{
    cnt=0;
    for(int i=0;i<(1<<n);i++)
    {
        isok[i]=good(i);
        if(isok[i]) state[cnt++]=i;
    }
    for(int i=0;i<(1<<n);i++)
        dp1[i]=INF;
    dp1[0]=0;
    for(int i=0;i<cnt;i++)
    {
        for(int j=(1<<n)-1;j>=0;j--)if(dp1[j]!=INF)
            dp1[j|state[i]]=min(dp1[j|state[i]],dp1[j]+1);
    }
    return dp1[(1<<n)-1];
}
int solve_2()
{
    //计算任意两点间的距离
    memset(dist,0,sizeof(dist));
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            dist[i][j]=dist[j][i]= ceil(sqrt((double)(x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])));

    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            cost[i][j]=INF;//cost[i][j]表示当前在i点,已经走过了集合j中的点,所需要的最短距离
    cost[0][1]=0;

    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)if( (i&(1<<j)) )//j在集合i中
            for(int k=0;k<n;k++)if( (i&(1<<k))==0 )//k不在集合i中
                cost[k][i|(1<<k)] = min(cost[k][i|(1<<k)] , cost[j][i]+dist[j][k]);
    for(int i=0;i<(1<<n);i++)
    {
        np[i]=INF;
        if(isok[i])
        for(int j=0;j<n;j++)if(i&(1<<j))//j在集合i中
        {
            np[i] = min(np[i],cost[j][i]+dist[j][0]);//这里计算出来的有效np[i]的i&1都是!=0的
            //因为cost中的i&1 !=0
        }
    }
    for(int i=1;i<(1<<n);i++)
        if(i&1)for(int j=(i-1)&i;j;j=(j-1)&i)
        np[i]=min(np[i],np[j|1]+np[(i-j)|1]);//如果此处不|1的话,那么有可能分成的集合j和(i-j)因为没有前置1从而是INF的值
    return np[(1<<n)-1];
}
int main()
{

    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&c[i]);
        int ans1=solve_1();
        int ans2=solve_2();
        if(ans1==INF)
            printf("-1 -1\n");
        else
            printf("%d %d\n",ans1,ans2);
    }
    return 0;
}

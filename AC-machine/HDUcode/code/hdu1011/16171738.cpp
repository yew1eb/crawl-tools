#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"queue"
#define N 111
using namespace std;

int n,m;
int bugs[N],cost[N],val[N];
int dp[N][N];
struct Eage{
    int from,to,next;
}eage[2*N],eage2[N];
int tot,tot2,head[N],head2[N];
void add(int a,int b){
    eage[tot].from=a;eage[tot].to=b;eage[tot].next=head[a];head[a]=tot++;
}
void add2(int a,int b){
    eage2[tot2].from=a;eage2[tot2].to=b;eage2[tot2].next=head2[a];head2[a]=tot2++;
}

void get_direct()
{
    int j,v;
    int flag[N];
    queue<int>q;
    int now,next;

    tot2=0;
    memset(head2,-1,sizeof(head2));

    memset(flag,0,sizeof(flag));
    q.push(1);
    flag[1]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(j=head[now];j!=-1;j=eage[j].next)
        {
            v=eage[j].to;
            if(flag[v])    continue;
            flag[v]=1;
            next=v;
            add2(now,next);
            q.push(next);
        }
    }
}
void get_map()
{
    int i;
    int a,b,temp;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&bugs[i],&val[i]);
        temp=bugs[i];
        if(!temp)    cost[i]=1;                //就算该点没有bug，不过要想得到val，仍然需要至少一个士兵
        else
        {
            cost[i]=temp/20;
            if(temp%20)    cost[i]++;
        }
    }
    tot=0;
    memset(head,-1,sizeof(head));
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    get_direct();
}
int MAX(int a,int b)
{
    return a>b?a:b;
}
void dfs_dp(int k)
{
    int i,l,j,v;

    if(head2[k]==-1)            //这个地方已经是底了，已经保证在底层至少有一个soldier了
    {
        dp[k][cost[k]]=val[k];
        return ;
    }

    int c[N];
    /*****/        //合并分枝
    for(j=head2[k];j!=-1;j=eage2[j].next)
    {
        v=eage2[j].to;
        dfs_dp(v);
        memset(c,0,sizeof(c));
        if(j==head2[k])
        {
            for(l=0;l<=m;l++)    dp[k][l]=dp[v][l];
            continue;
        }
        memset(c,0,sizeof(c));
        for(i=m;i>=1;i--)
        {
            if(!dp[v][i])        continue;
            for(l=m-i;l>=0;l--)
                c[l+i]=MAX(c[l+i],dp[k][l]+dp[v][i]);
        }
        for(l=1;l<=m;l++)
            dp[k][l]=MAX(dp[k][l],c[l]);
    }
    //将当前root节点(k)合并进去
    if(!bugs[k])
    {
        for(l=1;l<=m;l++)
            dp[k][l]+=val[k];
    }
    else
    {
        for(l=m;l>=cost[k];l--)    dp[k][l]=dp[k][l-cost[k]]+val[k];
        for(l=0;l<cost[k];l++)    dp[k][l]=0;
    }
}
int main()
{
    int l;
    while(scanf("%d%d",&n,&m),n!=-1 || m!=-1)
    {
        get_map();
        memset(dp,0,sizeof(dp));
        dfs_dp(1);

        int ans=0;
        for(l=1;l<=m;l++)    if(dp[1][l]>ans)    ans=dp[1][l];
        printf("%d\n",ans);
    }
    return 0;
}
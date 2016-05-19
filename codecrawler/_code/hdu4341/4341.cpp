#include"iostream"
#include"cstdio"
#include"cmath"
#include"cstring"
#include"algorithm"
using namespace std;
const int N=205;
const int M=40005;

int n,m,now,pre,dp[2][M];
struct node{
    int x,y,dis2,cost,val;
}E[N];
struct Edge{
    int v,next;
}edge[N];
int tot,head[N];
void add(int a,int b){
    edge[tot].v=b;edge[tot].next=head[a];head[a]=tot++;
}

int cmp(node n1,node n2){
    return n1.dis2<n2.dis2;
}
void build()
{
    int i,l,ff;
    double k1,k2;
    tot=0;
    memset(head,-1,sizeof(head));
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&E[i].x,&E[i].y,&E[i].cost,&E[i].val);
        E[i].dis2=E[i].x*E[i].x+E[i].y*E[i].y;
    }
    sort(E,E+n,cmp);
    for(i=n-1;i>=0;i--)
    {
        ff=0;
        if(!E[i].x) k1=123456;
        else        k1=1.0*E[i].y/E[i].x;
        for(l=i-1;l>=0;l--)
        {
            if(ff)    break;
            if(!E[l].x) k2=123456;
            else        k2=1.0*E[l].y/E[l].x;
            if(fabs(k1-k2)>1e-5)    continue;
            ff=1;
            add(l,i);
        }
        if(!ff) add(i,i);
    }
}
void dfs(int j,int k,int acc_val,int acc_cost)
{
    int l;
    int sum_val=acc_val+E[k].val;
    int sum_cost=acc_cost+E[k].cost;
    for(l=0;l<sum_cost;l++) dp[now][l]=dp[pre][l];
    for(;l<=m;l++)
    {
        dp[now][l]=dp[pre][l];
        if(dp[now][l] < dp[pre][l-sum_cost]+sum_val)
            dp[now][l]=dp[pre][l-sum_cost]+sum_val;
    }
    j=edge[j].next;
    if(j!=-1)   dfs(j,edge[j].v,sum_val,sum_cost);
}
void DP()
{
    int i,j;
    now=1;pre=0;
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
    {
        j=head[i];
        if(j==-1) continue;
        if(edge[j].v!=i)  continue;
        now=(now+1)%2;
        pre=1-now;
        dfs(j,edge[j].v,0,0);
    }
}
int main()
{
    int Case=1;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        build();
        DP();
        printf("Case %d: %d\n",Case++,dp[now][m]);
    }
    return 0;
}

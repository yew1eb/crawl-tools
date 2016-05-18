#include<iostream>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define LL long long
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
#define M 1000000007
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define Maxn 510000
int dp[Maxn],n,l,r,cnt;

struct Edge
{
    int v,len,next;
}edge[Maxn];
int head[Maxn];

void add(int a,int b,int c)
{
    cnt++;
    edge[cnt].v=b,edge[cnt].len=c;
    edge[cnt].next=head[a];
    head[a]=cnt;
}

void dfs(int cur,int from,int dep)
{
    int p=head[cur];
    if(!p) //到了叶子节点
    {
       dp[cur]=0;
       return ;
    }
    dp[cur]=dep?INF:-1; //当前为谁
    for(;p;p=edge[p].next)
    {
        int v=edge[p].v;
        dfs(v,from+edge[p].len,dep^1);//先计算叶子节点
        if(dp[v]==-1||dp[v]==INF) //叶子节点不满足要求，不走这条路
            continue;
        int tmp=dp[v]+from+edge[p].len;

        if(tmp<=r&&tmp>=l) //满足总体要求
        {
            if(dep)
                dp[cur]=min(dp[cur],dp[v]+edge[p].len);
            else
                dp[cur]=max(dp[cur],dp[v]+edge[p].len);
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&l,&r))
    {
        memset(head,0,sizeof(head));
        cnt=0;
        for(int i=1;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        dfs(0,0,0);
        //printf("%d\n",dp[0]);
        if(dp[0]>=l&&dp[0]<=r)
            printf("%d\n",dp[0]);
        else
            printf("Oh, my god!\n");
    }
   return 0;
}



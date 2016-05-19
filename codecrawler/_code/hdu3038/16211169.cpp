#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<30
#define M 60005
#define N 10005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
using namespace std;
int n,m;
int pre[200005];
int sum[200005];
int find(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=find(pre[x]);
        sum[x]+=sum[f];
    }
    return pre[x];
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++) pre[i]=i,sum[i]=0;
        int ans=0;
        while(m--)
        {
            int l,r,s;
            scanf("%d%d%d",&l,&r,&s);
            l--;
            int ra=find(l),rb=find(r);
            if(ra==rb)
            {
                if(sum[l]-sum[r]!=s) ans++;
            }
            else
            {
                pre[ra]=rb;
                sum[ra]=sum[r]-sum[l]+s;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
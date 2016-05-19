#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int ans;
LL state[200];
int check(LL st)
{
    int cnt=0;
    for(;st;st>>=1)
        cnt+=(st&1);
    return cnt;
}
void dfs(int k,int i,LL st)
{
    if(k>=ans)
        ans=k;
    for(;i<=36;i++)
    {
        if(check(st&state[i])>=k+1)
            dfs(k+1,i+1,st&state[i]);
    }
}
int main()
{
    int n,T;
    for(scanf("%d",&T);T;T--)
    {
        scanf("%d",&n);
        ans=0;
        memset(state,0,sizeof(state));
        for(int i=0,a,b;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            state[a]|=(1LL<<b);
        }
        dfs(0,1,(1LL<<36)-1);
        printf("%d\n",ans);
    }
    return 0;
}
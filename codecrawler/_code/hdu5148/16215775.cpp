#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<vector>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define F (100000007)
#define MAXN (2000+10)
#define MAXK (100+10)
#define MAXc (100000+10) 
#define INF (1000000000000LL)
typedef long long ll;

int n,k;
ll dp[MAXN][MAXK];
vector<int> edge[MAXN],dis[MAXN];
void dfs(int u,int fa)
{
    int sz=edge[u].size();
    Rep(i,sz)
    {
        int v=edge[u][i];
        ll d=dis[u][i];
        if (v!=fa)
        {
            dfs(v,u);
            ForD(j,k)
            {
                ForD(t,j-1) //è³å°å1ä¸ªèç¹ 
                    dp[u][j]=min(dp[u][j],dp[u][t]+dp[v][j-t]+(j-t)*(k-(j-t))*d*2);
            }
            
            
        }
    }
}
int main()
{
//    freopen("1003.in","r",stdin);
//    freopen(".out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        For(i,n) dis[i].resize(0);
        For(i,n) edge[i].resize(0);
        For(i,n-1)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            dis[a].push_back(c);
            dis[b].push_back(c);
        }
        
        MEM(dp)
        For(i,n)
            Fork(j,2,k)
            {
                dp[i][j]=(ll)INF;
            }
        
        dfs(1,-1);
        ll ans=INF;
        For(i,n) ans=min(ans,dp[i][k]);
        printf("%I64d\n",ans);    
    }
    
        
    return 0;
}

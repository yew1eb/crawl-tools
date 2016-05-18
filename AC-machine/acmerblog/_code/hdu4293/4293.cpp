#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=506;

int n,dp[N],map[N][N];
inline int max(int a,int b){
    return a>b?a:b;
}
int main()
{
    int i,l;
    int a,b,ans;
    while(scanf("%d",&n)!=-1)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a+b>=n)    continue;
            map[a+1][n-b]+=(n-a-b)>map[a+1][n-b]?1:0;
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        for(l=1;l<=i;l++)
            dp[i]=max(dp[i],dp[l-1]+map[l][i]);
        cout<<dp[n]<<endl;
    }
    return 0;
}
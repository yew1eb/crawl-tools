#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int INF=1000000100;
int a[maxn];
int g[maxn];
int dp[maxn];
int N;
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&a[i]);
            a[i]-=i;
        }
        int ans=0;
        for(int i=0;i<=N;i++)g[i]=INF;
        for(int i=1;i<=N;i++)
        {
            int k=upper_bound(g+1,g+1+N,a[i])-g;
            g[k]=a[i];
            ans=max(ans,k);
        }
        printf("Case #%d:\n%d\n",cas++,N-ans);
    }
    return 0;
}
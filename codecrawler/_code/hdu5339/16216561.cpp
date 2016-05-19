#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;
    while((c=getchar())<'0' || c>'9');
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res;
}
int b[22];
int dp[1000010];//dp[i]ä»¥iä¸ºç»å°¾çæç­åºå

int main()
{
    int T=in();
    while(T--)
    {
        int n=in(),a=in();
        mem(dp,inf);
        for(int i=1;i<=n;i++)b[i]=in();
        dp[0]=0;
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i]=min(dp[i],dp[i%b[j]]+1);
            }
        }
       // for(int i=0;i<=a;i++)cout<<dp[i]<<" ";
       // cout<<endl;
        printf("%d\n",dp[a]==inf?-1:dp[a]);
    }
    return 0;
}
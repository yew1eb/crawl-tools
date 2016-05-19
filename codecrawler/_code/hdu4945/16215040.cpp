#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>

#define sqr(x) ((x)*(x))
#define LL long long 
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define eps 1e-10
#define mod 998244353ll
using namespace std;
inline int ReadInt()
{
    int flag=0;
    char ch=getchar();
    int data=0;
    while (ch<'0'||ch>'9')
    {
        if (ch=='-') flag=1;
        ch=getchar();
    }
    do
    {
        data=data*10+ch-'0';
        ch=getchar();
    }while (ch>='0'&&ch<='9');
    return data;
}
void egcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1,y=0;
        return ;
    }
    egcd(b,a%b,x,y);
    LL t=x;
    x=y;y=t-a/b*x;
}
int a[100005];
LL inv[100005];
LL cnt[15],fr;
int base[3000];
LL dp[20][2050];
int lim[20];
LL mypow(LL x,LL y)
{
    LL res=1;
    LL mul=x;
    while (y)
    {
        if (y&1)
        res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int main()
{
    lim[0]=2048;
    for (int i=1;i<=12;i++)
    lim[i]=2048>>(i-1);
    for (LL i=1;i<=100000;i++)
    {
        LL x,y;
        egcd(i,mod,x,y);
        x=(x+mod)%mod;
        inv[i]=x;
    }
    int n,ca=0;
    while (~scanf("%d",&n),n)
    {
        fr=n;
        memset(base,0,sizeof base);
        for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        base[a[i]]++;
        }
        memset(cnt,0,sizeof cnt);
        for (int i=1;i<=12;i++)
        {
            cnt[i]=base[1<<(i-1)];
            fr-=cnt[i];
        }
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for (int i=1;i<=12;i++)
        {
            for (int j=0;j<=lim[i-1];j++)
            if (dp[i-1][j])
            {
                LL cal=1;
                for (int k=j/2;k<lim[i];k++)
                {
                    int pos=j/2;
                    if ((k-pos)>cnt[i]) break;
                    dp[i][k]+=dp[i-1][j]*cal%mod;
                    dp[i][k]%=mod;
                    cal=(cal*(LL)(cnt[i]-((k-pos))))%mod;
                    cal=(cal*inv[(k-pos)+1])%mod;
                }
            }
        }

        LL ans;
        ans=(mypow(2ll,(LL)n-fr)-dp[12][0]+mod)%mod;
        ans=ans*mypow(2ll,fr)%mod;
        printf("Case #%d: %I64d\n",++ca,ans);
    }
    return 0;
}
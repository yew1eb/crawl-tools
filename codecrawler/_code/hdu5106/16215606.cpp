#include"cstdlib"
#include"cstdio"
#include"cstring"
#include"cmath"
#include"queue"
#include"algorithm"
#include"map"
#include"vector"
#include"string"
#define inf 0x7fffffff
#include"iostream"
#define ll __int64
using namespace std;
ll mod=1000000007;
struct node
{
    ll cnt,sum;
    node()
    {
        cnt=-1;
        sum=0;
    }
} dp[1005][1005];
int num[1234];
ll bit[1234];
char v[1234];
int k;
node dfs(int site,int sum,int f)
{
    if(sum>k)
    {
        node tep;
        tep.cnt=0;
        return tep;
    }
    if(site==0)
    {
        node tep;
        if(sum==k)
        {
            tep.cnt=1;
            tep.sum=0;
        }
        else
        {
            tep.cnt=0;
            tep.sum=0;
        }
        return tep;
    }
    if(!f&&dp[site][sum].cnt!=-1) return dp[site][sum];
    int len=f?num[site]:1;
    node ans;
    ans.cnt=0;
    for(int i=0; i<=len; i++)
    {
        node tep;
        if(i==0) tep=dfs(site-1,sum,f&&i==len);
        else tep=dfs(site-1,sum+1,f&&i==len);
        ans.cnt+=tep.cnt;
        if(ans.cnt>=mod) ans.cnt%=mod;
        ll sss;
        if(i==0) sss=0;
        else sss=bit[site];
        ans.sum+=(tep.cnt*sss)%mod+tep.sum;
        if(ans.sum>=mod) ans.sum%=mod;
    }
    if(!f) dp[site][sum]=ans;
    return ans;
}
int main()
{
    bit[1]=1;
    for(int i=2; i<=1000; i++) bit[i]=(bit[i-1]*2)%mod;
    while(scanf("%d%s",&k,v)!=-1)
    {
        memset(num,0,sizeof(num));
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<=k;j++)
            {
                dp[i][j].cnt=-1;
                dp[i][j].sum=0;
            }
        }
        if(k==0)
        {
            puts("0");
            continue;
        }
        int len=strlen(v);
        for(int i=0; v[i]; i++) num[i+1]=v[len-1-i]-'0';
        int i=1;
        while(1)       //è®°å¾åä¸
        {
            if(num[i]==1)
            {
                num[i]=0;
                break;
            }
            else
            {
                num[i]=1;
                num[i+1]--;
                if (num[i+1]==0) break;
                i++;
            }
        }
        if (num[len]==0) len--;
        node ans;
        ans=dfs(len,0,1);
        printf("%I64d\n",ans.sum%mod);
    }
    return 0;
}

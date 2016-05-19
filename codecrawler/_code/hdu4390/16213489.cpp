#include<iostream>
#include<cstdio>
#include <queue>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb(a) push_back(a)
#define MOD 1000000007
#define LL long long
using namespace std;
int n;
LL c[505][505];
vector<int>p;
void fuck(int num)
{
    for(int i=2;i*i<=num;i++)
    {
        while(num%i==0)
        {
            num/=i;
            p.pb(i);
        }
    }
    if(num>1) p.pb(num);
}
void Init()
{
    for(int i=0;i<=500;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
    }
}
LL get(int n,int m)
{
    return c[m+n-1][n-1];
}
LL slove()
{
    int a[1005]={1},cnt=0;
    sort(p.begin(),p.end());
    for(int i=1;i<p.size();i++)
    {
        if(p[i]!=p[i-1]) a[++cnt]=1;
        else a[cnt]++;
    }
    LL ans=1;
    for(int i=0;i<=cnt;i++)  ans=(ans*get(n,a[i]))%MOD;
    //cout<<ans<<endl;
    for(int i=1;i<n;i++)
    {
        LL tmp=c[n][i];
        for(int j=0;j<=cnt;j++)
        {
            tmp=(tmp*get(n-i,a[j]))%MOD;
        }
        if(i&1) ans=((ans-tmp)%MOD+MOD)%MOD;
        else ans=(ans+tmp)%MOD;
    }
    return ans;
}
int main()
{
    Init();
    while(scanf("%d",&n)!=EOF)
    {
        p.clear();
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            fuck(k);
        }
        printf("%I64d\n",slove());
    }
    return 0;
}
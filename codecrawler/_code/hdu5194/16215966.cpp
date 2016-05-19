#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
using namespace std;
long long c(long long x,long long y)
{
    long long i,r,j;
    x=min(x,y-x);
    if(x==0)
    {
        return 1;
    }
    r=1;
    for(i=1,j=y;i<=x;i++,j--)
    {
        r*=j;
    }
    for(i=x;i>=1;i--)
    {
        r/=i;
    }
    return r;
}
long long f(long long da,long long xiao)
{
    long long t;
    while(da%xiao!=0)
    {
        t=da;
        da=xiao;
        xiao=t%xiao;
    }
    return xiao;
}
long long dp[15][15];
int main()
{
    long long n,m,z,az,an,am,q,i,p,sum,y,j,sw,x,k;
    memset(dp,0,sizeof(dp));
    for(i=0;i<=15;i++)
    {
        dp[1][i]=1;
        dp[i][0]=1;
    }
    for(i=2;i<=13;i++)
    {
        for(j=1;j<=12;j++)
        {
            for(k=0;k<=j;k++)
            {
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    while(cin>>n>>m)
    {
        z=m+n;
        az=an=am=1;
        for(i=z;i>n;i--)
        {
            az*=i;
        }
        for(i=1;i<=m;i++)
        {
            am*=i;
        }
        q=az/(am);
        //cout<<"q:"<<q<<endl;
        p=0;
        for(i=1;i<=n&&i<=m;i++)
        {
            sw=m-i;
            sum=dp[i+1][sw];
            p+=sum*c(i,n)*i;
            //cout<<"p:"<<p<<endl;
        }
        //cout<<"p:"<<p<<endl;
        y=f(max(p,q),min(p,q));
        cout<<p/y<<"/"<<q/y<<endl;
    }
    return 0;
}

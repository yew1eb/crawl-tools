#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#define MAX 20010
using namespace std;
long long a[MAX];
long long c[100005];
long long d[MAX];
long long f[MAX];
long long t[MAX];
long long h[MAX];
long long lowbit(long long x)
{
    return x&-x;
}
void update(long long x,long long n)
{
    while(x<=n)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
long long query(long long x)
{
    long long ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    long long x,sum,m;
    int ca,n,i;
    scanf("%d",&ca);
    while(ca--)
    {
        memset(c,0,sizeof(c));
        m=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
            m=max(m,a[i]);
        }
        m=m+1;
        for(i=0;i<n;i++)
        {
            update(a[i],m);
            d[i]=query(m)-query(a[i]);
            f[i]=query(a[i]-1);
        }
        memset(c,0,sizeof(c));
        for(i=n-1;i>=0;i--)
        {
            update(a[i],m);
            t[i]=query(m)-query(a[i]);
            h[i]=query(a[i]-1);
        }
        sum=0;
        for(i=0;i<n;i++)
          sum+=d[i]*h[i]+f[i]*t[i];
        printf("%I64d\n",sum);
    }
}

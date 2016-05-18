#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long LL;
LL myPow(LL a,int b)
{
    LL sum=1LL;
    while(b)
    {
        if(b%2==1)
        {
            sum*=a;
        }
        a*=a;
        b/=2;
    }
    return sum;
}

int vis[30],adj[30];

void dfs(int i)
{
    if(vis[i]==0)
    {
        vis[i]=1;
        dfs(adj[i]);
    }
}

int find(int s,int n)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        int e=(s+i-1)%n;
        if(e==0)
            e=n;
        adj[i]=e;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            sum++;
        }
    }
    return sum;
}

int main()
{
    int n;
    LL a,b;
    while(scanf("%d",&n))
    {
        if(n==-1)
            break;
        if(n<=0)
        {
            printf("0\n");
            continue;
        }
        if(n%2==0)
        {
            a=myPow(3LL,n);
           for(int i=2;i<=n;i++)
           {
               int tn=find(i,n);
               a+=myPow(3LL,tn);
           }
            b=(LL)n;
            a=a+(LL)(n/2)*(myPow(3LL,(n+2)/2));
            a=a+(LL)(n/2)*(myPow(3LL,n/2));
            b+=(LL)n;
        }
        else
        {
            a=myPow(3LL,n);
            for(int i=2;i<=n;i++)
            {
                int tn=find(i,n);
                a+=myPow(3LL,tn);
            }
            b=(LL)n;
            a=a+(LL)n*(myPow(3LL,1+(n-1)/2));
            b+=(LL)n;
        }
        printf("%lld\n",a/b);
    }
    return 0;
}
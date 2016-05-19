#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include<cmath>
#include<climits>
#include<vector>
#include<cfloat>
#include<queue>
#include<cctype>
#include<cstdlib>
#define LL long long
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int n,m;
int lowbit(int x)
{
    return x&(-x);
}
void update(int *b,int i,int val)
{
    while(i<=n)
    {
        b[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int *b,int i)
{
    int ret=0;
    while(i>0)
    {
        ret+=b[i];
        i-=lowbit(i);
    }
    return ret;
}
int read()
{
    int c,x;
    while(c=getchar(),!isdigit(c));
    x=c-'0';
    while(c=getchar(),isdigit(c)) x=x*10+c-'0';
    return x;
}
int main()
{
    int t;
    t=read();
    while(t--)
    {
        n=read();m=read();
        for(int i=1;i<=n;i++)
            a[i]=read();
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        LL tmp=0;
        for(int i=n;i>m;i--)
        {
            tmp+=sum(c,a[i]-1);
            update(c,a[i],1);
        }
        LL ans=tmp;
        for(int i=m+1;i<=n;i++)
        {
            tmp-=sum(c,a[i]-1);
            tmp-=sum(b,n)-sum(b,a[i]);
            update(c,a[i],-1);

            tmp+=sum(c,a[i-m]-1);
            tmp+=sum(b,n)-sum(b,a[i-m]);
            update(b,a[i-m],1);
            ans=min(ans,tmp);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

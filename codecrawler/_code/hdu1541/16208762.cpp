#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n;
const int N=16000;
const int M=33000;

int a[M],c[N];

int lowbit(int t)
{
    return t&(-t);
}

void insert(int t,int d)
{
    while (t<=M)
    {
        a[t]+=d;
        t+=lowbit(t);
    }
}

int getsum(int t)
{
    int zs=0;
    while (t>0)
    {
        zs+=a[t];
        t-=lowbit(t);
    }
    return zs;
}

int main()
{
    int i,x,y,p,n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for (i=1;i<=n;i++)

        {
            scanf("%d%d",&x,&y);
            insert(x+1,1);
            p=getsum(x+1)-1;
            c[p]++;
        }
        for (i=0;i<n;i++) printf("%d\n",c[i]);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
const int maxn=100;
const int base=10000;
void multi(int a[],int maxn,int b)
{
    int ans=0;
    for(int i=maxn-1;i>=0;i--)
    {
        ans+=a[i]*b;
        a[i]=ans%base;
        ans/=base;
    }
}
void divide(int a[],int maxn,int b)
{
    int ans=0;
    for(int i=0;i<maxn;i++)
    {
        ans=ans*base+a[i];
        a[i]=ans/b;
        ans%=b;
    }
}
int fac[210][maxn];
void make_fac()
{
    fac[0][maxn-1]=1;
    fac[1][maxn-1]=1;
    for(int i=2;i<=200;i++)
    {
        memcpy(fac[i],fac[i-1],maxn*sizeof(int));
        multi(fac[i],maxn,i);
    }
}
int miao[maxn];
int main()
{
    int n;
    make_fac();
    while(scanf("%d",&n)!=EOF,n)
    {
        memcpy(miao,fac[2*n],maxn*sizeof(int));
        for(int i=1;i<=n+1;i++)
            divide(miao,maxn,i);
        int i=0;
        while(i<maxn&&miao[i]==0)
        {
            i++;
        }
        printf("%d",miao[i++]);
        while(i<maxn)
        {
            printf("%04d",miao[i++]);
        }
        printf("\n");
    }
    return 0;
}

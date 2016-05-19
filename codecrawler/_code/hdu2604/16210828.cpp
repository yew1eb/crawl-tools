#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct sqare
{
    int s[4][4];
    sqare()
    {
        memset(s,0,sizeof(s));
    }
};
int n,mod,sq[4][4]={{0,0,0,1},{1,0,0,0},{1,1,0,0},{0,0,1,1}};
void scopy(int *a,int *b)
{
    for(int i=0;i<16;i++)
        a[i]=b[i];
}
sqare mul(int a[][4],int b[][4])
{
    sqare c;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
                c.s[i][j]=(c.s[i][j]+a[i][k]*b[k][j])%mod;
        }
        return c;
}
sqare deal(int m)
{
    sqare a;
    if(m==1)
    {
        scopy(&a.s[0][0],&sq[0][0]);
    }
    else
    {
        a=deal(m/2);
        a=mul(a.s,a.s);
        if(m&1)
            a=mul(a.s,sq);
    }
    return a;
}
int main()
{
    int ans=0;
    sqare mm;
    while(~scanf("%d%d",&n,&mod))
    {
        mm=deal(n-2);
        ans=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                ans=(ans+mm.s[i][j])%mod;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int fac[20];
void Init(int m)
{
    int i,n=0;
    for(i=2;i*i<=m;i++)
        if(m%i==0){
            fac[++n]=i;
            while(m%i==0)    m/=i;
        }
    if(m!=1)    fac[++n]=m;
    fac[0]=n;
}

__int64 Noprime(int m,__int64 n,int x)
{
    __int64 i,ret=0;
    for(i=x;i<=fac[0];i++)
        ret+=n/fac[i]-Noprime(m,n/fac[i],i+1);
    return ret;
}

int main()
{
    int t,T,N;
    __int64 A,B;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%I64d%I64d%d",&A,&B,&N);  Init(N);
        printf("Case #%d: %I64d\n",t,B-Noprime(N,B,1)-(A-1-Noprime(N,A-1,1)));
    }
    return 0;
}
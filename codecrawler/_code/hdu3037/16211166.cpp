#include<iostream>
#include<cstdio>
using namespace std;

__int64 jc[100010];

__int64 exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
    if(b==0)    return x=1,y=0,a;
    __int64 res=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}

__int64 Inv(__int64 a,__int64 mod){
    __int64 x,y;
    exgcd(a,mod,x,y);
    return (x%mod+mod)%mod;
}

__int64 C(__int64 n,__int64 m,__int64 mod){
    if(m>n) return 0;
    __int64 ret= jc[n];
    ret*= Inv((jc[m]*jc[n-m])%mod,mod);
    return ret%mod;
}
__int64 Lucas(__int64 n,__int64 m,__int64 mod){
    if(m==0)    return 1;
    return C(n%mod,m%mod,mod)*Lucas(n/mod,m/mod,mod)%mod;
}

int main()
{
    int i,j,k,N,M,n,mod,T;
    
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&mod);
        for(jc[0]=1,i=1;i<=mod;i++)    jc[i]=jc[i-1]*i%mod;
        printf("%I64d\n",Lucas(N+M,N,mod));
    }
    return 0;
}

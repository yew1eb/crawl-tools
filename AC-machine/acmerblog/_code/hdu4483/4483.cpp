#include <stdio.h>
#include <iostream>
using namespace std;
#define maxn 100001
#define LL long long
const LL mod=1000000007;//最好用常量，我用宏定义，*6的时候爆了，怎么也找不出来
LL x[maxn],y[maxn],z[maxn],phi[maxn],n;
void init()
{
    LL i,j,k;
    //欧拉函数，phi[i]表示不超过i的与i互质的整数个数
    for(i=2;i<maxn;i++)phi[i]=0;
    phi[1]=1;
    for(i=2;i<maxn;i++)
        if(!phi[i])
        for(j=i;j<=maxn;j+=i){
            if(!phi[j])phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
    x[1]=z[1]=1;
    y[1]=2;
    for(i=2;i<maxn;i++)
    {
        x[i]=(x[i-1]+phi[i]*2)%mod;
        y[i]=(y[i-1]+phi[i]*i*3)%mod;
        z[i]=(z[i-1]+phi[i]*i%mod*i)%mod;
    }
}
int main()
{
    LL T;
    init();
    cin>>T;
    while(T--)
    {
        LL k,t,ans,m;
        cin>>n;
        n++;
        t=(n*n)%mod;
        LL md=mod*6;
        ans=t*(t-1)%md*(t-2)%md/6;//除法取余;
        ans-=t*(n-1)%md*(n-2)*2%md/6;
        t=0;
        for(k=2;k<n;k++)
        {
            m=(n-1)/k;
            t=(t+(k-1)*(x[m]*n%mod*n%mod-n*k%mod*y[m]%mod+k*k%mod*z[m]%mod))%mod;
        }
        ans-=t*2;
        cout<<(ans%mod+mod)%mod<<endl;
    }
    return 0;
}
/*
题意：在n*n的网格内找到3个格点，使它能构成三角形，问能构成多少个三角形？

方法：
    总共有t=(n+1)*(n+1)个格点,所以令n++
    1.任取三个点ans=c(t,3)
    2.去掉在一条直线三的三个点ans=ans-c(n,3)*n*2
    3.还要去掉在一条斜线上的三个点：
        对于长宽为i，j的矩形，对角线上有gcd(i,j)-1个格点(不包括两端点),这样我们就能枚举矩形，去掉不能构成三角形的三个点
        则要去掉的方案数为∑∑(n-i)*(n-j)*(gcd(i,j)-1);
        本题n太大，还要优化成O(n)复杂度才可以
    优化：
        令i=a*k,j=b*k,其中k为(i,j)的最大公约数
        则条件3的方案数为sum=∑∑∑(n-a*k)*(n-b*k)*(k-1)=∑∑∑(n*n-(a+b)*n*k+a*b*k*k)*(k-1)
            =∑[k](k-1)*(n*n*∑∑1+n*k*∑∑(a*b)+k*k*∑∑(a*b))
        
        其中i,j<n,所以a,b<=(n-1)/k=m;
        phi[i]为欧拉函数,a,b<=m中，∑∑=a，b两两互质的个数=1+(phi[2]+phi[3]+...+phi[m])*2
        phi[i]的个数只是说a<b，b=i时有多少个，还有a>b，所以要乘以2，除了a=b=1以外
        
        定理：如果gcd(a,b)==1,则gcd(a,a-b)==1。所以phi[i]个与i互质的数种，成对出现，每对之和为i
        所以∑∑(a+b)=∑(phi[i]/2*i+phi[i])*2
        
        由上述定理可以知道：phi[i]个互质的数与i的乘积之和为i*(x1+x2+..xm)=i*ph[i]/2*i;
        所以∑∑(a*b)=∑(phi[i]*i*i/2)*2
*/

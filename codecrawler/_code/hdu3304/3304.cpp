#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
const int mod=10000;
int main()
{
    int p,n,tt=0;
    while(scanf("%d%d",&p,&n)!=EOF)
    {
        if(p==0&&n==0)
            break;
        int ans=1;
        while(n)
        {
            ans*=(n%p+1);
            n/=p;
            if(ans>=mod)
                ans%=mod;
        }
        printf("Case %d: %04d\n",++tt,ans);//∏(ai+1) (0=<i<=k)
    }
    return 0;
}
/*
    一开始就被坑到了，看了白书上的中文翻译，上面说的是能被p整除的有多少个，弄的我怎么也没理解Lucas定理的说明，555555
    
    Lucas定理：
    A、B是非负整数，p是质数。AB写成p进制：A=a[n]a[n-1]...a[0]，B=b[n]b[n-1]...b[0]。
    则组合数C(A,B)与C(a[n],b[n])*C(a[n-1],b[n-1])*...*C(a[0],b[0])  mod p同余
    即：Lucas(n,m,p)=c(n%p,m%p)*Lucas(n/p,m/p,p)，在存在i，b[i]>a[i]时，mod值为0，所以必定整除；当对于所有i，b[i]<=a[i]时，a[i]!%p!=0,所以必定不能整除 
    
    看到一大神的证明，我觉得很不错：
//重点：
        问题问C[n,i](0=<i<=n)中有多少个不能被p整除的。
    分析2：
          我们知道对于素数p，n！中p的幂次为
          f[n!,p]=[n/p]+[n/p^2]+[n/p^3]……
          
          那么C[n,m]中p的幂次为
          f[c[n,m],p]=f[n,p]-f[n-m,p]-f[m,p]
          
          c[n,m]不能被p整除，意味着f[n,p]=f[n-m,p]+f[m,p]
          于是 [n/p^i]=[(n-m)/p^i]+[m/p^i]对任意i成立
          
    设n的p进制表示为(ak……,a0)
          设n-m的p进制表示为(bk……,b0)
          设m的p进制表示为(ck……,c0)
          
    [n/p^k]=ak=[(n-m)/p^k]+[m/p^k]=bk+ck                                                        =>ak=bk+ck
          [n/p^(k-1)]=(aka(k-1))=[(n-m)/p^(k-1)]+[m/p^(k-1)]=(bkb(k-1))+(ck(ck-1))   =>a(k-1)=b(k-1)+c(k-1)
         ……
         我们可以得到ai=bi+ci(0<=i<=k)这是充分条件。这里说明下，可以枚举c，对于ci，要保证等式成立，0<=ci<=ai,共ai+1个，所以结果是
         ∏(ai+1)，符合这样条件的m必定小于n(看一下就知道了);当ci>ai时，就不能存在bi>=0使等式成立
        
         即当0=<bi<=ai时对任意i成立时 f[n,p]=f[n-m,p]+f[m,p]，即p不整除c[n,m]
        
         所以c[n,m]不被p整除的数有 ∏(ai+1) (0=<i<=k)个。
    
    分析2:
         书上例题
         设p为质数，a，b为两正整数，且a,b在p进制下表示为 a=(ak……,a0),b=(bk……,b0) 0=<ai,bi<p
    证明 c[a,b]=c[ak,bk]*……*c[a0,b0](mod p)
          证：
               p为质数时易证 (1+x)^p=1+x^p(mod p)
               (1+x)^a=(1+x)^(ak*p^k)……(1+x)^(a0) （mod p）
                          =(1+x^(p^k))^ak……(1+x)^a0（mod p） （1）
               x^b在（1）右边式子的系数为c[ak,bk]*……*c[a0,b0]。
              从而的证 c[a,b]=c[ak,bk]*……*c[a0,b0](mod p)
          
         根据这个结论 我们可知c[a,b]=0(mod p) 当且仅当 存在bi>ai
         
         所以c[n,m]不被p整除的数有 TT(ai+1) (0=<i<=k)个。
*/
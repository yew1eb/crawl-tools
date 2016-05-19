#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long LL;
const int N=1000005;
int phi[N];
LL a,b,p,n;
void get_phi()
{
    for(int i=1;i<N;i++) phi[i]=i;
    for(int i=2;i<N;i++) if(phi[i]==i)
        for(int j=i;j<N;j+=i)
            phi[j]=phi[j]/i*(i-1);
}
LL exp_mod(LL a,LL b,LL mod)
{
    LL ret=1,base=a%mod;
    while(b)
    {
        if(b&1) ret=ret*base%mod;
        b>>=1;
        base=base*base%mod;
    }
    return ret;
}
struct mat
{
    LL a[5][5];
    int n,m;
    mat(int _n=0,int _m=0,LL val=0)
    {
        n=_n; m=_m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]=(i==j?val:0);
    }
    void print()
    {
        for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<' ';
        puts("");
    }
    mat operator *(mat tmp)
    {
        mat ret(n,tmp.m);
        for(int i=0;i<n;i++)
            for(int j=0;j<tmp.m;j++)
                for(int k=0;k<m;k++){
                    ret.a[i][j]+=a[i][k]*tmp.a[k][j];
                    if(ret.a[i][j]>phi[p]) ret.a[i][j]=ret.a[i][j]%phi[p]+phi[p];
                }
        return ret;
    }
    mat operator ^(LL b)
    {
        mat ret(n,m,1),base=(*this);
        while(b)
        {
            if(b&1) ret=ret*base;
            b>>=1;
            base=base*base;
        }
        return ret;
    }
};
LL calc(LL a,mat m1,mat m2)
{
    m2=m1*m2;
    return exp_mod(a,m2.a[1][0],p);
}
int main()
{
    int t;
    get_phi();
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&p,&n);
//        cout<<a<<' '<<b<<' '<<p<<' '<<n<<endl;
        mat m1(2,2),m2(2,1);
        m1.a[0][0]=1; m1.a[0][1]=1; m1.a[1][0]=1;
        m1=m1^(n-1);
//        puts("yes");
        m2.a[0][0]=0; m2.a[1][0]=1;
        LL ans=calc(a,m1,m2);
        m2.a[0][0]=1; m2.a[1][0]=0;
        ans=ans*calc(b,m1,m2);
        ans%=p;
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}

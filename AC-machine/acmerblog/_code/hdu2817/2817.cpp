//对于这种数据正好几乎要超过int的范围却远小于long long的范围的题目，直接全部用long long
#include<cstdio>
using namespace std;
const long long mod = 200907;

long long pow_mod(long long x,long long a,long long n)//a^b mod mod
{
    if(a==0) return 1;
    long long ans = pow_mod(x,a/2,n);
    long long temp = (ans*ans)%n;
    if(a%2) temp = (temp*x)%n;
    return temp;
}

/*
long long pow_mod(long long a,long long b,long long n)  //a^b mod n
{
    long long ret=1;
    for (; b; b>>=1,a=(long long)(((long long)a)*a%n))
        if (b&1)
            ret=(long long)(((long long)ret)*a%n);
    //printf("%d\n",ret);
    return ret;
}
*/
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long  a1,a2,a3;
        long long k;
        scanf("%I64d%I64d%I64d%I64d",&a1,&a2,&a3,&k);
        //if(a1==a2)
        // printf("%.0lf\n",a1%mod);

        if(a2-a1==a3-a2)//等差数列
        {
            /*
            long long d = (long long)(a2-a1);
            long long a = (long long)a1;
            int temp = (a%mod+((d%mod)*((k-1)%mod)))%mod;
            printf("%d\n",temp);
            */
            long long d = (a2-a1)%mod;
            long long temp = ((a1%mod)+((d%mod)*((k-1)%mod)))%mod;
            printf("%I64d\n",temp);

        }
        else//等比数列
        {
            /*
            long long p1 = (a2/a1);
            long long p = (long long)p1;
            long long a = (long long)a1;
            int temp = ((a%mod)*(pow_mod(p,k-1,mod)))%mod;
            printf("%d\n",temp);
            */
            long long p=a2/a1;//p的值可能超过int的范围，如果此处用int则必定WA
            long long  temp = ((a1%mod)*(pow_mod(p,k-1,mod)))%mod;
            printf("%I64d\n",temp);

        }

    }
    return 0;
}
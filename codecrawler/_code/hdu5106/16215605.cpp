#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define ll long long int

using namespace std;

int n;
const int MOD=1000000007;
char r[1010];
int b[1010];
ll c[1010][1010];
ll m[1010];
int len;

void init()
{
    memset(c,0,sizeof(c));
    ll p=1;
    for (int i=0;i<=1000;i++)
    {
        m[i]=p;
        p*=2;
        p%=MOD;
    }
    c[0][0]=c[1][0]=c[1][1]=1;
    for (int i=2;i<=1000;i++)
    {
        c[i][0]=1;
        for (int t=1;t<=i;t++)
        {
            c[i][t]=c[i-1][t-1]+c[i-1][t];
            c[i][t]%=MOD;
        }
    }
}

int main()
{
    init();
    while (~scanf("%d",&n))
    {
        scanf("%s",r);
        len=strlen(r);
        for (int i=0;i<len;i++)
            b[i+1]=r[i]-'0';
        int p=0;
        ll ans=0;
        ll v=0;
        for (int i=1;i<=len;i++)
        {
            v=v*2;
            v%=MOD;
            if (b[i]==1&&n-p>=0)
            {
                ll s1=0;
                ll s2=0;
                s1=((m[len-i]*v)%MOD)*c[len-i][n-p]%MOD;
                if (i<len&&p<n)
                    s2=((m[len-i]-1)*c[len-i-1][n-p-1])%MOD;
                ans=ans+s1+s2;
            }
            ans%=MOD;
            p=p+b[i];
            v+=b[i];
        }
        ans%=MOD;
        printf("%I64d\n",ans);
    }
}









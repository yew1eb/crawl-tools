#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;

const int N=1000005;
const LL MOD=1000000007;

int p[N];
int a[N],b[N];
bool prime[N];
LL C[1005][1005];
int k;

void isprime()
{
    int i,j;
    k=0;
    memset(prime,true,sizeof(prime));
    for(i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i; j<N; j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

void Init()
{
    int i,j;
    for(i=0; i<1005; i++)
    {
        C[i][0]=C[i][i]=1;
        for(j=1; j<i; j++)
        {
            C[i][j]=(C[i-1][j]%MOD+C[i-1][j-1]%MOD)%MOD;
        }
    }
}

void Solve(int b[],int n)
{
    memset(a,0,sizeof(a));
    for(int i=0; i<n; i++)
    {
        for(int j=0; p[j]<=b[i]; j++)
        {
            if(b[i]%p[j]==0)
            {
                while(b[i]%p[j]==0)
                {
                    a[j]++;
                    b[i]/=p[j];
                }
            }
        }
    }
}

int main()
{
    isprime();
    Init();
    LL ans,n;
    while(~scanf("%I64d",&n))
    {
        ans=0;
        for(int i=0; i<n; i++)
            scanf("%d",&b[i]);
        Solve(b,n);
        
        for(int i=0; i<n; i++)
        {
            LL tmp =C[n][i];
            for(int j=0; j<k; j++)
                tmp=(tmp*C[a[j]+n-i-1][a[j]])%MOD;
            ans+=(i&1)?-tmp:tmp;
            ans%=MOD;
        }
        printf("%d\n",(ans%MOD+MOD)%MOD);
    }
    return 0;
}

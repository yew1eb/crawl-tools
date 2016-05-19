#include <stdio.h>
#include <string.h>
#include <math.h>

#define LL long long
const LL N = 1000005;

LL p[N];
bool prime[N];
LL n,k=0;

void isprime()
{
    LL i,j;
    memset(prime,true,sizeof(prime));
    for(i=2;i<N;i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i;j<N;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}

bool Test()
{
    int i;
    for(i=0;i<k;i++)
    {
        if(n%p[i]==0)
        {
            n/=p[i];
            if(n%p[i]==0) return false;
        }
    }
    return true;
}

int main()
{
    LL t=1,T;
    isprime();
    bool flag;
    scanf("%I64d",&T);
    while(T--)
    {
        flag=false;
        scanf("%I64d",&n);
        printf("Case %d: ",t++);
        if(!Test())
            flag=true;
        if(n>1000000)
        {
            LL temp=(LL)sqrt((double)n);
            if(temp*temp==n) flag=true;
        }
        if(flag)  puts("No");
        else      puts("Yes");
    }
    return 0;
}

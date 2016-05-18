#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[10];
long long getf(long long x,int n)
{
    long long sum=0;
    for(int i=0; i<n; i++)
        sum+=a[i],sum*=x;
    return sum+a[n];
}
void solve(int n,long long pri)
{
    long long i,j,mod=pri*pri;
    for(i=0; i<pri; i++)
        if(getf(i,n)%pri==0)
            for(j=i; j<mod; j+=pri)
                if(getf(j,n)%mod==0)
                {
                    printf("%I64d\n",j);
                    return;
                }
    puts("No solution!");
}
int main()
{
    int t,n,ca=0;
    long long pri;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n+1; i++)
            scanf("%I64d",&a[i]);
        scanf("%I64d",&pri);
        printf("Case #%d: ",++ca);
        solve(n,pri);
    }
    return 0;
}

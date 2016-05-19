#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[100];
int T,n,i,j;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int f=0,z=0;
        long long ans=1,x;
        for (i=1;i<=n;i++)
        {
            scanf("%I64d",&x);
            if (x<0) a[++f]=x;
            else if (x==0) z++;
            else ans*=x;
        }
        if (f+z==n)
        {
            if (f==0) {puts("0");continue;}
            if (f==1)
            {
                if (z) {puts("0");continue;}
                else {printf("%I64d\n",a[1]);continue;}
            }
        }
        sort(a+1,a+1+f);
        for (i=1;i<=f/2*2;i++) ans*=a[i];
        printf("%I64d\n",ans);
    }
    return 0;
}
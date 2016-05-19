#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 500005
typedef long long ll;
ll a[N],b[N];
int len;
int main()
{
    int i,j,n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        len=0;
        int z,l;
        scanf("%d%d%d%d",&n,&m,&z,&l);
        a[1]=0;
        for(i=2; i<=n; i++)
            a[i]=(a[i-1]*m+z)%l;
        int sum=a[1];
        /*
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            b[len++]=a[i]+a[j];
        }
        for(i=1;i<len;i++)
        {
            b[i]=b[i-1]^b[i];
        }
        cout<<b[len-1]<<endl;
        */
        for(i=2; i<=n; i++)
        {
            a[i]=a[i-1]^a[i];
        }
        printf("%lld\n",a[n]*2);
    }
}

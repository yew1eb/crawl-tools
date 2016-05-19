#include <stdio.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn=500+10;

int a[maxn];
int b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        for(int k=0;k<n;k++)
            scanf("%d",b+k);
        sort(a,a+n);
        sort(b,b+n);
        int sum1,sum2;
        sum1=sum2=0;
        for(int i=0;i<m;i++)
            sum1+=a[i];
        for(int k=n-m;k<n;k++)
            sum2+=b[k];
        if(sum1>sum2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
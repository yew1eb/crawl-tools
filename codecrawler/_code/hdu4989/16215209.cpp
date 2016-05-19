#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,j;
    while(~scanf("%d",&n))
    {
        int a[105];
        int b[10005];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        __int64 sum=0;
        int l=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                b[l++]=a[i]+a[j];
            }
            sort(b,b+l);
            int n1=unique(b,b+l)-b;  //å»æç¸åçãæ­¤æ¶æ°æ°ç»ä¸ªæ°n1.
            for(i=0;i<n1;i++)
                sum+=b[i];
            printf("%I64d\n",sum);
    }
    return 0;
}
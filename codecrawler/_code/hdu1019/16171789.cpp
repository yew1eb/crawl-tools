#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int t,s,n,i,j,m,a[5000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(i=a[n-1];;i+=a[n-1])
        {
            for(j=0;j<n-1;j++)
                if(i%a[j]!=0)
                    break;
            if(j==n-1)
                break;
        }
        printf("%d\n",i);
    }
    return 0;
}

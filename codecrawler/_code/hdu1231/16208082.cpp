#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[10005],dp[10005];

int main()
{
    int n,i,j,MAX,cnt;
    while(~scanf("%d",&n),n)
    {
        for(i = 0; i<n; i++)
            scanf("%d",&a[i]);
        int left,right,flag;
        MAX = a[0];
        cnt = 0;
        left = right = a[0];
        for(i = 0; i<n; i++)
        {
            if(cnt<0)
            {
                cnt = a[i];
                flag = a[i];
            }
            else
                cnt+=a[i];
            if(cnt>MAX)
            {
                MAX = cnt;
                left = flag;
                right = a[i];
            }
        }
        if(MAX<0)
        {
            printf("0 %d %d\n",a[0],a[n-1]);
            continue;
        }
        printf("%d %d %d\n",MAX,left,right);
    }


    return 0;
}

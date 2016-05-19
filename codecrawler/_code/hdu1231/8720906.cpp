#include <stdio.h>
#include <string.h>
const int maxn = 10005;
#define INF 0xfffffff
int a[maxn];

int main()
{
    int n, i, sum, front_num, b, rear_num, flag, max;
    while(~scanf("%d",&n),n)
    {
        flag  = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>=0) flag = 1;
        }
        sum = 0; b = 0;
        max = -INF;
        if(flag)
        {
            for(i=0; i<n; i++)
            {
                sum += a[i];
                if(sum>max)
                {
                    max = sum;
                    front_num = a[b];
                    rear_num = a[i];
                }
                if(sum<0)
                {
                    sum = 0;
                    b = i+ 1;
                }
            }
            printf("%d %d %d\n",max, front_num,rear_num);
        }
        else
            printf("%d %d %d\n",0,a[0],a[n-1]);
    }
    return 0;
}












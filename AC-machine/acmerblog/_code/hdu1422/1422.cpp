#include <stdio.h>

int main()
{
    int i,n,a,b,sum,cnt,max,ar[100005];
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            ar[i]=a-b;
        }
        sum=cnt=0;
        max=-1;
        for (i=0;i<2*n-1;i++)
        {
            sum+=ar[i%n];
            if(sum>=0)
            {
                cnt++;
                if(max<cnt)max=cnt;
                if(cnt==n)break;
            }
            else sum=cnt=0;
        }
        printf("%d\n",max);
    }
    return 0;
}
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int s,n,i,j,sum,min,a[1001];
    scanf("%d",&s);
    while(s--)
    {
        min=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=1;i<n;i++)
        {
            min=min+abs(a[i]-a[0]);
        }
        for(j=1;j<n;j++)
        {
            sum=0;
            for(i=0;i<n;i++)
            {
                if(i!=j) sum=sum+abs(a[i]-a[j]);
            }
            if(sum<=min) min=sum;
    }
    printf("%d\n",min);
 }
 return 0;
}
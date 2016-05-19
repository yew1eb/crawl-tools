#include <stdio.h>
int main()
{
    int n, x, a[100], i, j;
    while(scanf("%d%d",&n,&x)&&(n||x))
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            if(x<a[i])
            break;
        }
        for(j=0;j<i;j++)
        printf("%d ",a[j]);
        printf("%d",x);
        for(j=i;j<n;j++)
        printf(" %d",a[j]);
        printf("\n");
    }
    return 0;

}

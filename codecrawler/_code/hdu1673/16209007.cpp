#include <stdio.h>

int main()
{
    int t,max,min,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        max = 0,min = 100;
        while(n--)
        {
            scanf("%d",&m);
            max = m>max?m:max;
            min = m<min?m:min;
        }
        printf("%d\n",2*(max-min));
    }

    return 0;
}

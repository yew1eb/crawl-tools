#include <stdio.h>

int main()
{
    int n, m, i;
    while(~scanf("%d%d",&m,&n))
    {
        if(m<n)
        {
            for(i=m; i<n; ++i)
                printf("%d ",i);
            printf("%d\n",i);
        }
        else if(m %(n+1) == 0) puts("none");
        else printf("%d\n",m %(n+1));
    }
    return 0;
}

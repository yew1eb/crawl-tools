#include <stdio.h>

int main()
{
    int t, n, m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n", (1+n)*n/2*(1+m)*m/2 );
    }
    return 0;
}

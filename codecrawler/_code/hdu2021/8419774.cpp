#include <stdio.h>
int main()
{
    int n, x, tot;
    while(scanf("%d",&n),n)
    {
        tot = 0;
        while(n--)
        {
            scanf("%d",&x);
            tot +=x/100;
            x %=100;
            tot +=x/50;
            x %=50;
            tot +=x/10;
            x %=10;
            tot +=x/5;
            x %=5;
            tot +=x/2;
            x %=2;
            tot +=x;

        }
        printf("%d\n",tot);
    }
    return 0;
}

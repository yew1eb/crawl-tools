#include<stdio.h>

int main()
{
    int n;
    int x;
    int d;
    int tot;
    while(scanf("%d",&n),n)
    {
        tot=0;
        d=0;
        while(n--)
        {
             scanf("%d",&x);
             tot=tot+5+( x-d>0?(x-d)*6:(d-x)*4 );
             d=x;
        }
        printf("%d\n",tot);
    }
    return 0;
}

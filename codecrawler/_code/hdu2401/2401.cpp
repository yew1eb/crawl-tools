# include <stdio.h>


int main ()
{
    int n, w, d, rst, ans ;
    while (~scanf ("%d%d%d%d", &n, &w, &d, &rst))
    {
        ans = (n*(n-1)*w/2-rst) / d ;
        printf ("%d\n", (ans == 0) ? n : ans ) ;
    }
    return 0 ;
}
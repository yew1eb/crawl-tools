# include <stdio.h>


int main ()
{
    int n, a, max ;
    while (~scanf ("%d", &n))
    {
        if (n == 0) break ;
        scanf ("%d", &max) ;
        while (n-- -1)
        {
            scanf ("%d", &a) ;
            if (a > max) max = a ;
        }
        printf ("%d\n", max) ;
    }
    return 0 ;
}
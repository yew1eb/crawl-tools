# include <stdio.h>


int main ()
{
    int n ;
    while (~scanf ("%d", &n))
        if (n < 168) break ;

    if (n < 168) printf ("CRASH %d\n", n) ;
    else printf ("NO CRASH\n") ;
    return 0 ;
}
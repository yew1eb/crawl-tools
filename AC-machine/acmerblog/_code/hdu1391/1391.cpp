# include <stdio.h>


int gao(int x, int y)
{
    int ans ;
    if (x == y) return 2*x - (x&1) ;
    return gao(x, y+2) - 2  ;
}


int main ()
{
    int T, x, y ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d%d", &x, &y) ;
        if (x != y && x != y+2) printf ("No Number\n") ;
        else printf ("%d\n", gao(x,y)) ;
    }
    return 0 ;
}

# include <stdio.h>


int main()
{
    int T, n ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &n) ;
        printf ("%d\n", 3*n*n-3*n+2) ;
    }
    return 0 ;
}
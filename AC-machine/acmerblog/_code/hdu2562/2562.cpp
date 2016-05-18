# include <stdio.h>


char str[100] ;


int main ()
{
    int T, i ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%s%*c", str) ;
        for (i = 0 ; str[i] ; i+=2)
            printf ("%c%c", str[i+1], str[i]) ;
        printf ("\n") ;
    }
    return 0 ;
}
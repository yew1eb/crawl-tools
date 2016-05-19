# include <stdio.h>
# include <string.h>


int main ()
{
    int T ;
    int a, n, len ;
    char str[10] ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d.%s %d", &a, str, &n) ;
        len = strlen(str) ;
        if (n <= len) putchar (str[n-1]) ;
        else putchar ('0') ;
        putchar ('\n') ;
    }
    
    return 0 ;
}
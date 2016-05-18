# include <stdio.h>
# include <math.h>


void reverse(int n)
{
    if (n == 0) return ;
    printf ("%d", n%10) ;
    reverse(n/10) ;
}


void output(int n)
{
    int zero = 0 ;
    if (n == 0){
        puts ("0") ;
        return ;
    }
    if (n < 0){
        printf ("-") ;
        n = -n ;
    }
    while (n%10 == 0)
    {
        n /= 10 ;
        zero++ ;
    }
    reverse(n) ;
    while (zero--) putchar ('0') ;
    putchar ('\n') ;
}


int main ()
{
    int n ;
    scanf ("%d", &n) ;
    while (~scanf ("%d", &n))
        output(n) ;
    return 0 ;
}
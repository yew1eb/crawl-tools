# include <stdio.h>
# include <string.h>


int fib[35] = {1,1} ;
int tab[35] ;


void init()
{
    int i ;
    for (i = 2 ; i <= 30 ; i++)
        fib[i] = fib[i-1]+fib[i-2] ;
}


void set (int x)
{
    int i ;
    for (i = 25 ; i>= 1 ; i--)
        if (fib[i] <= x) tab[i] = 1, x -= fib[i] ;
}


int main ()
{
    int n, x, sum, i ;
    init() ;
    scanf ("%d", &n) ;
    while (n--)
    {
        scanf ("%d", &x) ;
        memset (tab, 0, sizeof(tab)) ;
        set(x) ;
        for (i = 2, sum = 0 ; i <= 30 ; i++)
            if (tab[i]) sum += fib[i-1] ;
        printf ("%d\n", sum) ;
    }
    
    return 0 ;
}
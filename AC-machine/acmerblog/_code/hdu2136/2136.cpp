# include <stdio.h>
# include <math.h>


int IsPrime[1000010] ;
int Primes[1000010] ;
int cnt = 0 ;


void init()
{
    int i, j ;
    for(i = 1 ; i <= 1000000 ; i++) IsPrime[i] = 1 ;
    for(i = 2 ; i <= 1000 ; i++)if (IsPrime[i])
    {
        for (j = i*i ; j <= 1000000 ; j+=i)
            IsPrime[j] = 0 ;
    }
    for(i = 1 ; i <= 1000000 ; i++) if (IsPrime[i])
    {
        IsPrime[i] = cnt ;
        Primes[cnt++] = i ;
    }
}


int calc(int n)
{
    int i, lim = sqrt(n)+1, rtn = 0 ;
    for(i = 1 ; Primes[i] <= lim && n != 1; i++)
    {
        while (n%Primes[i] == 0)
        {
            n/=Primes[i] ;
            rtn = i ;
        }
    }
    if (n == 1) return rtn ;
    return IsPrime[n] ;
}


int main ()
{
    int n ;
    init() ;
    while (~scanf ("%d", &n))
        printf ("%d\n", calc(n)) ;
    return 0 ;
}
# include <stdio.h>


void gao(long long n, long long time, int s, int e)
{
    int m = 6-s-e ;
    long long mid = (1LL<<(n-1)) ;
    if (time == mid)
    {
        printf ("%I64d %d %d\n", n, s, e) ;
        return ;
    }
    if (time < mid)
        gao(n-1, time, s, m) ;
    else
        gao(n-1, time-mid, m, e) ;
}


int main ()
{
    int T ;
    long long n, time ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%I64d%I64d", &n, &time) ;
        gao(n, time, 1, 3) ;
    }
    return 0 ;
}
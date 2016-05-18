# include <stdio.h>
# include <math.h>

int dp[300010] ;

void init()
{
    int i ;
    double sum = 0 ;
    for (i = 2 ; i <= 300000 ; i++)
    {
        sum += log2(i*1.0) ;
        dp[i] = ((int)sum) + 1 ;
    }
}

int main ()
{
    int n, l, r, mid ;
    init() ;
    while (~scanf ("%d", &n), n)
    {
        n = 1 << ((n-1940) / 10) ;
        l = 1, r = 300000 ; 
        while (l<r-1)
        {
            mid = (l+r)/2 ;
            if (dp[mid] < n) l = mid ;
            else r = mid ;
        }
        if (dp[r] == n) l = r ;
        printf ("%d\n", l) ;
    }
    return 0 ;
}
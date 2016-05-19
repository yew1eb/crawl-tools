# include <stdio.h>


long long dp[100010] ;


int main ()
{
    long long n, i ;
    for (i = 1 ; i<= 100000 ; i++)
    {
        if (i%3==0) dp[i] = dp[i-1] + i*i*i ;
        else dp[i] = dp[i-1]+i ;
    }
    while (~scanf ("%I64d", &n) && n>=0)
        printf ("%I64d\n", dp[n]) ;
    return 0 ;
}
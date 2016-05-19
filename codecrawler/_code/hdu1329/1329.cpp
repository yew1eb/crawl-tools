# include <stdio.h>
# include <string.h>
# include <math.h>


int n ;
int dp[55] ;


int issquare(int a)
{
    int b = sqrt(1.0*a) ;
    return b*b == a ;
}


int gao()
{
    int i, j, flag ;
    for (i = 1 ; ; i++)
    {
        flag = 0 ;
        for (j = 0 ; j < n ; j++)
        {
            
            if (dp[j] == 0 || issquare (dp[j]+i))
            {
                dp[j] = i ;
                flag = 1 ;
                break ;
            }
        }
        if (flag == 0)
            return i-1 ;
    }
    return -1 ;
}


int main ()
{
    int T ;
    scanf ("%d", &T) ;
    while (T--)
    {
        scanf ("%d", &n) ;
        memset (dp, 0, sizeof(dp)) ;
        printf ("%d\n", gao()) ;
    }
    return 0 ;
}
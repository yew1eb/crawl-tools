# include <stdio.h>


long long div(long long x, int b)
{
    int rtn = 0 ;
    while (x%b==0)
    {
        x /= b ;
        rtn ++ ;
    }
    return rtn ;
}


int main ()
{
    long long n, mul ; 
    while (~scanf ("%I64d", &n),n)
    {
        mul = 1 ;
        mul *= (div(n,2)+1) ;
        mul *= (div(n,3)+1) ;
        mul *= (div(n,5)+1) ;
        mul *= (div(n,7)+1) ;
        printf ("%I64d\n", mul) ;
    }
    return 0 ;
}
# include <stdio.h>


int calc(int n)
{
    int sum = 0 ;
    while(n)
    {
        if ((n&1) == 0) 
            sum += (n%10) ;
        n/=10 ;
    }
    return sum ;
}


int main ()
{
    int n , flag = 0 ;
    while (~scanf ("%d", &n))
    {
        if (flag == 0) flag = 1 ;
        else puts("") ;
        printf ("%d\n", calc(n)) ;
    }
    return 0 ;
}
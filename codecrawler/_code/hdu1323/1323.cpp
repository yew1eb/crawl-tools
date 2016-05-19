# include <stdio.h>


int main ()
{
    int n, ans, i ;
    puts ("PERFECTION OUTPUT") ;
    while (~scanf ("%d", &n),n)
    {
        for(i = 1,ans=0 ; i < n && ans <= n; i++)
            if (n%i==0)ans+=i;
        printf("%5d  ",n) ;
        if(ans>n)puts("ABUNDANT");
        else if(ans==n)puts("PERFECT");
        else puts("DEFICIENT") ;
    }
    puts("END OF OUTPUT") ;
    return 0 ;
}
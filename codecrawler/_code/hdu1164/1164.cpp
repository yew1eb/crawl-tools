# include <stdio.h>


int main ()
{
    int i, n, flag ;
    while (~scanf ("%d", &n))
    {
        flag = 0 ;
        for (i = 2 ; i< n ; i++)
        {
            if (n == 1) break ;
            while (n % i == 0)
            {
                if (flag == 0) flag = 1 ;
                else printf ("*") ;
                printf ("%d", i) ;
                n/=i ;
            }
        }
        if (n != 1) printf (flag?"*%d":"%d", n) ;
        puts ("") ;
    }
    return 0 ;
}
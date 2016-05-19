# include <stdio.h>


int main ()
{
    int sum, n, num ;
    int flag = 0 ;
    scanf ("%d", &n) ;
    while (~scanf ("%d", &n))
    {
        sum = 0 ;
        while (n--){
            scanf ("%d", &num) ;
            sum += num ;
        }
        if (flag == 0) flag = 1 ;
        else puts ("") ;
        printf ("%d\n", sum) ;
    }
    return 0 ;
}
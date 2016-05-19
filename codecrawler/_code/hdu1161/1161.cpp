# include <stdio.h>


int main ()
{
    int ch ; 
    while ((ch = getchar ()) != EOF)
    {
        if (ch >= 'A' && ch <= 'Z')
            putchar (ch -'A' + 'a') ;
        else putchar (ch) ;
    }
    return 0 ;
}
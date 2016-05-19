# include <stdio.h>


char str[40] ;


int chartonum(char ch)
{
    if (ch >= '0' && ch <= '9') return ch-'0' ;
    return ch-'A'+10 ;
}


int gao(char str[], int b)
{
    int i, rtn = 0 ;
    for (i = 0 ; str[i] ; i++)
    {
        if (chartonum(str[i])>=b) return -1 ;
        rtn = rtn*b + chartonum(str[i]) ;
    }
    return rtn ;
}


void gao2(int num, int b)
{
    int i, cnt = 0 ;
    char s[40], tab[] = "0123456789ABCDEF" ;
    while (num)
    {
        s[cnt++] = tab[num%b] ;
        num /= b ;
    }
    if (cnt > 7){
        printf ("%7s\n", "ERROR") ;
        return ;
    }
    for (i = 0 ; i < cnt ; i++)
        str[cnt-i-1] = s[i] ;
    str[cnt] = '\0' ;
    printf ("%7s\n", str) ;
}


int main ()
{
    int num, b1, b2 ;
    while (~scanf ("%s  %d %d", &str, &b1, &b2))
    {
        num = gao(str, b1) ;
        if (num == -1) printf ("%7s\n", "ERROR") ;
        gao2(num, b2) ;
    }
    return 0 ;
}
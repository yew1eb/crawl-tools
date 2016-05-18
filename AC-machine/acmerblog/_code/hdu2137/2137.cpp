# include <stdio.h>
# include <string.h>


void out0(char str[], int len){puts (str) ;}
void out1(char str[], int len)
{
    int i, j ;
    for (i = len-1 ; i >=0 ; i--)
    {
        for (j = 0 ; j < i ; j++) putchar (' ') ;
        printf ("%c\n", str[i]) ;
    }
}
void out2(char str[], int len)
{
    int i, j ;
    for(i=len-1;i>=0;i--)
    {
        for (j = 0 ; j < len/2 ; j++) putchar (' ') ;
        printf ("%c\n", str[i]) ;
    }
}
void out3(char str[], int len)
{
    int i, j ;
    for(i = len-1 ; i >= 0 ; i--)
    {
        for (j = 0 ; j < len-1-i ; j++) putchar (' ') ;
        printf ("%c\n", str[i]) ;
    }
}
void out4(char str[], int len)
{
    int i ;
    for (i = len-1 ; i >= 0 ; i--) putchar (str[i]) ;
    putchar ('\n') ;
}
void out5(char str[], int len)
{
    int i, j ;
    for (i = 0 ; i < len ; i++)
    {
        for (j = 0 ; j < len-i-1 ; j++) putchar (' ') ;
        printf ("%c\n", str[i]) ;
    }
}
void out6(char str[], int len)
{
    int i, j ;
    for(i=0;i<len ;i++)
    {
        for (j = 0 ; j < len/2 ; j++) putchar (' ') ;
        printf ("%c\n", str[i]) ;
    }
}
void out7(char str[], int len)
{
    int i, j ;
    for(i = 0 ; i < len ; i++)
    {
        for(j = 0 ; j < i ; j++) putchar (' ') ;
        printf("%c\n", str[i]) ;
    }
}


int main ()
{
    int k ;
    char str[100] ;
    while (~scanf ("%s %d%*c", str, &k))
    {
        if (k < 0) k = (-k)%8, k = 8-k ;
        switch (k%8){
        case 0: out0(str, strlen(str)) ; break ;
        case 1: out1(str, strlen(str)) ; break ;
        case 2: out2(str, strlen(str)) ; break ;
        case 3: out3(str, strlen(str)) ; break ;
        case 4: out4(str, strlen(str)) ; break ;
        case 5: out5(str, strlen(str)) ; break ;
        case 6: out6(str, strlen(str)) ; break ;
        case 7: out7(str, strlen(str)) ; break ;
        }
    }
    return 0 ;
}
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct NODE{
    char str[10] ;
    int len, val ;
}NODE ;

NODE dp[110] ;

int scmp(const void *a, const void *b)
{
    return *(char*)a - *(char*)b ;
}

int calc(char *str, int len)
{
    int rtn = 0 ;
    qsort(str, len, 1, scmp) ;
    while (len--)
    {
        rtn = rtn * 27 + str[0] ;
        str++ ;
    }
    return rtn ;
}

int cmp( const void *a, const void *b)
{
    NODE *p = (NODE*)a, *q = (NODE*) b ;
    return strcmp(p->str, q->str) ;
}

int main ()
{
    int n, i = 0, flag ;
    char str[10] ;

    while (gets(str) && strcmp(str, "XXXXXX"))
    {
        strcpy (dp[i].str, str) ;
        dp[i].len = strlen(str) ;
        dp[i].val = calc(str, dp[i].len) ;
        i++ ;
    }
    n = i ;
    qsort(dp, n, sizeof(NODE), cmp) ;
    while (gets(str) && strcmp(str, "XXXXXX"))
    {
        flag = 0 ;
        for (i = 0 ; i < n ; i++)
        {
            if (strlen(str) == dp[i].len &&
                calc(str, dp[i].len) == dp[i].val)
            {
                puts (dp[i].str) ;
                flag = 1 ;
            }
        }
        if (flag == 0) puts ("NOT A VALID WORD") ;
        puts ("******") ;
    }
    return 0 ;
}
# include <stdio.h>

int main ()
{
    int ch, cnt = 0, cc = 0 ;
    int flag = 0, end = 1 ;
    int i ;
    char buff[100] ;
//    freopen ("in.txt", "r", stdin) ;
//    freopen ("out.txt", "w", stdout) ;
    while (end)
    {
        ch = getchar () ;
        if (ch == EOF)
        {
            ch = ' ' ;
            end = 0 ;
        }
        if (flag == 0)
        {
            if (ch == ' ' || ch == '\n'||ch == '\t') continue ;
            else if (ch == '<') flag = 2 ;
            else{
                buff[cnt++] = ch ;
                flag = 1 ;
            }
        }
        else if (flag == 1)
        {
            if (ch == '<' || ch == ' '||ch == '\n'||ch == '\t')
            {
                if (ch == '<') flag = 2 ;
                else flag = 0 ;
                buff[cnt] = '\0' ;
                if (cnt + cc + 1 > 80){
                    putchar ('\n') ;
                    cc = cnt ;
                }
                else
                {
                    if (cc != 0)
                    {
                         putchar (' ') ;
                         cc++ ;
                    }
                    cc += cnt ;
                }
                printf ("%s",buff) ;
                cnt = 0 ;
            }
            else buff[cnt++] = ch ;
        }
        else if (flag == 2)
        {
        //    ch = getchar () ;
            if (ch == 'b')
            {
                putchar ('\n') ;
            }
            else //ch == 'h'
            {
                if (cc != 0)
                    putchar ('\n') ;
                for (i = 0 ; i < 80 ; i++)
                    putchar ('-') ;
                putchar ('\n') ;
            }
            flag = 0 ;
            cc = 0 ;
            cnt = 0 ;
            getchar () ;
            getchar () ;
        }
    }
    if (cc != 0) putchar ('\n') ;
    return 0 ;
}
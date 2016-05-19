/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
Copyright (c) 2011 panyanyany All rights reserved.

URL   : http://acm.hdu.edu.cn/showproblem.php?pid=1528
Name  : 1528 Card Game Cheater

Date  : Saturday, August 27, 2011
Time Stage : two hours

Result:
4502995    2011-08-27 16:50:52    Accepted    1528
0MS    236K    2156 B
C++    pyy


Test Data:


Review:
ä¸å¼å§åå¾å¾å¤æï¼å¶å®åªè¦å¨è¾å¥çæ¶åæççé¢å¼åè±è²è½¬ä¸ºæ´æ°å­å¨ä¸ä¸ªæ´åå¼
éå°±è¡äºï¼è¿æ ·æ¯è¾èµ·æ¥æ¹ä¾¿äºã
æè§è¿ä¸ªè²ä¼¼æ¯æå¤§å¹éï¼è²ä¼¼è¿æ¯ååçï¼ä» eve çè¾¹éåºåï¼å adam çè¾¹éåè¿ï¼
å¦æ eve æ¯ adam å¤§åè¡¨ç¤ºæ­¤è·¯å¯éï¼å¦åä¸å¯éãæ±è¿ç§éè·¯çæå¤§æ°éã
è¿æ ·æè§èµ·æ¥ï¼åºè¯¥æ¯ä¸ªååçæå¤§å¹éäºå§ï¼å°å¼ä¸æï¼å¯¹äºåå¾çè§£çå°ï¼åªè½è¿æ ·
çæµäºâ¦â¦
//----------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define FALSE    0
#define TRUE    1

#define infinity    0x0f0f0f0f
#define minus_inf    0x80808080

#define MAXSIZE    27

int tcase, k ;
int cover[MAXSIZE], link[MAXSIZE], adam[MAXSIZE], eve[MAXSIZE] ;

int makeInt (char c)
{
    int sign = 10, d ;
    if ('0' < c && c <= '9')
        d = c - '0' ;
    else if (c == 'T') d = 10 ;
    else if (c == 'J') d = 11 ;
    else if (c == 'Q') d = 12 ;
    else if (c == 'K') d = 13 ;
    else if (c == 'A') d = 14 ;
    else {
        sign = 1 ;
        if (c == 'C') d = 1 ;
        else if (c == 'D') d = 2 ;
        else if (c == 'S') d = 3 ;
        else if (c == 'H') d = 4 ;
    }
    return d * sign ;
}

int find (int cur)
{
    int i, j ;
    for (i = 0 ; i < k ; ++i)
    {
        if (cover[i] == FALSE && eve[cur] > adam[i])
        {
            cover[i] = TRUE ;
            if (link[i] == -1 || find (link[i]))
            {
                link[i] = cur ;
                return 1 ;
            }
        }
    }
    return 0 ;
}

int main ()
{
    char a, b, c ;
    int i, j, sum ;
    while (scanf ("%d", &tcase) != EOF)
    {
        while (tcase--)
        {
            scanf ("%d", &k) ;
            getchar () ;
            for (i = 0 ; i < k ; ++i)
            {
                scanf ("%c%c", &a, &b) ;
                getchar () ;
                adam[i] = makeInt (a) + makeInt (b) ;
            }
            for (i = 0 ; i < k ; ++i)
            {
                scanf ("%c%c", &a, &b) ;
                getchar () ;
                eve[i] = makeInt (a) + makeInt (b) ;
            }
            
            sum = 0 ;
            memset (link, -1, sizeof (link)) ;
            for (i = 0 ; i < k ; ++i)
            {
                memset (cover, 0, sizeof (cover)) ;
                sum += find (i) ;
            }
            printf ("%d\n", sum) ;
        }
    }
    return 0 ;
}

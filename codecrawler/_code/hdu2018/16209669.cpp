/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
    Copyright (c) 2012 panyanyany All rights reserved.

    URL   : http://acm.hdu.edu.cn/showproblem.php?pid=2018
    Name  : 2018 æ¯ççæäº

    Date  : Thursday, February 16, 2012
    Time Stage : half an hour

    Result:
5361461    2012-02-16 16:47:38    Accepted    2018
0MS    216K    982 B
C++    pyy


Test Data :

Review :
//----------------------------------------------------------------------------*/

#include <stdio.h>

#define MAXN    (56)

#define DB    /##/

int can[MAXN] = {0, 1, 1, 1, 1}, cow[MAXN] ;

int main ()
{
    int i, j, n ;
    // è®¡ç®ç¬¬iå¹´æå¤å°å¤´å¯çè²çæ¯ç
    for (i = 5 ; i <= 55 ; ++i)
        can[i] = can[i-1] + can[i-3] ;

    // æ ¹æ®ä»å¹´å¯çè²çæ¯çæ°ï¼åä¸ä¸å¹´çæ»çæ°ï¼å¯ä»¥ç®åºä»å¹´çæ»çæ°ã
    cow[0] = 0 ;
    for (i = 1 ; i <= 55 ; ++i)
        cow[i] = cow[i-1] + can[i] ;
    while (scanf("%d", &n), n)
    {
        printf ("%d\n", cow[n]) ;
    }
    return 0 ;
}

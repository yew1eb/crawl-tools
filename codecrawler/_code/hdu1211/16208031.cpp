/** 
  * url: http://acm.hdu.edu.cn/showproblem.php?pid=1211 RSA
  * Author: Johnsondu
  * Time: 2012-7-28 18:00 around
  * Stratege: éå(æ©å±æ¬§å éå¾·) , å¿«éæ¨¡åå¹
  * Status: 6364213    2012-07-28 18:12:54    Accepted    1211    0MS    256K    951 B    C++    johnsondu
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std ;

typedef __int64 lld ;
lld p, q, e, l ;
lld n, f, pd ;
lld c, M ;

void exGcd (lld a, lld b, lld &d, lld &x, lld &y)
{
    if (b == 0)
    {
        x = 1 ;
        y = 0 ;
        d = a ;
        return ;
    }
    exGcd (b, a%b, d, x, y) ;
    lld tmp = x ;
    x = y ;
    y = tmp - a/b*y ;
}

lld ModPow (lld a, lld pn, lld Mod)
{
    int tmp = 1 ;
    while (pn)
    {
        if (pn&1)
            tmp = tmp*a % Mod ;
        a = (a*a) % Mod ;
        pn >>= 1 ;
    }
    return tmp ;
}

int main () 
{
    lld x, y, d, a, b ;
    while (scanf ("%I64d%I64d%I64d%I64d", &p, &q, &e, &l) != EOF)
    {
        n = p * q ;
        f = (p-1) * (q-1) ;
        exGcd (e, f, d, x, y) ;
        pd = (x % f + f) % f ;
        
        for (int i = 0; i < l; i ++)
        {
            scanf ("%I64d", &c) ;
            M = ModPow (c, pd, n) ;
            printf ("%c", char(M)) ;
        }
        
        printf ("\n") ;
    }
    return 0 ;
}
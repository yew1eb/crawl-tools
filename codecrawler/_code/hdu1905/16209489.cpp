/*
---------------------------------------------------
    status : a312745658    3641    Accepted    328K
            16MS    C++    1732B    2012-05-18 21:36:37

    stratege : å¿«éæ¨¡åå¹ï¼ç´ æ°ç­éï¼ å¤æ­ä¸ä¸ªå¤§æ°æ¯å¦ä¸ºç´ æ°
    URLï¼  http://poj.org/problem?id=3641
           http://acm.hdu.edu.cn/showproblem.php?pid=1905
---------------------------------------------------
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std ;

typedef long long LL ;

LL p, c ;
LL res ;

const int MAXN = 40000 ;
int isPrime [MAXN] ;
bool flag ;
LL prime[MAXN] ;
int priLen;

void getPrime ()  // ç­é40000åçç´ æ°
{
    int i, j ;

    memset (isPrime, 0, sizeof(isPrime)) ;
    isPrime[1] = 1 ;
    priLen = 1 ;
    for (i = 4; i < MAXN; i += 2)
        isPrime[i] = 1 ;
    prime[0] = 2 ;
    for (i = 3; i < MAXN; i ++)
    {
        if (!isPrime[i])
        {
            int tmp = 2 * i ;
            prime[priLen ++] = i ;
            while (tmp < MAXN)
            {
                isPrime[tmp] = 1 ;
                tmp += i ;
            }
        }
    }
}

void ModPow(LL a, LL b, LL n) //å¨ææ°pä¸æ¯ç´ æ°çæåµä¸ï¼è¿è¡å¿«éæ¨¡åå¹
{
    LL rec=1;
    while(b)
    {
        if (b & 1)
            rec = ((rec % n) * a) % n;
        a = ((a % n) * a) % n;
        b >>= 1;
    }
    res = rec % n;
}

bool judge (int x)  //å¤æ­ææ°æ¯å¦ä¸ºç´ æ°
{
    if (x < 40000)  //å°äº40000ç´æ¥å¤æ­
    {
        if (!isPrime[x])
            return false ;
        return true ;
    }
    else
    {
        for (int i = 0; i <= priLen && prime[i]*prime[i] <= x; i ++)
        {
            if (x % prime[i] == 0) //å¤§äº40000ï¼ç¨æ¥é¤ä»¥40000ä»¥åç´ æ°
                return true ;
        }
        return false ;  //40000åçç´ æ°é½é¤ä¸äºï¼è¯å®æ¯ç´ æ°
    }
}


int main ()
{
    getPrime () ;
    while (scanf ("%d%d", &p, &c), p | c)
    {
        flag = true ;
        flag = judge (p) ;
        if (!flag)
        {
            printf ("no\n") ;
            continue ;
        }

        ModPow (c, p, p) ;// å¿«éæ¨¡åå¹
        if (res == c)   // res == (a^p) % p
            printf ("yes\n") ;
        else
            printf ("no\n") ;
    }
    return 0 ;
}

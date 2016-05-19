/*
---------------------------------------------------
    status : a312745658	3641	Accepted	328K
            16MS	C++	1732B	2012-05-18 21:36:37

    stratege : 快速模取幂，素数筛选， 判断一个大数是否为素数
    URL：  http://poj.org/problem?id=3641

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

void getPrime ()  // 筛选40000内的素数
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

void ModPow(LL a, LL b, LL n) //在指数p不是素数的情况下，进行快速模取幂
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

bool judge (int x)  //判断指数是否为素数
{
    if (x < 40000)  //小于40000直接判断
    {
        if (!isPrime[x])
            return false ;
        return true ;
    }
    else
    {
        for (int i = 0; i <= priLen && prime[i]*prime[i] <= x; i ++)
        {
            if (x % prime[i] == 0) //大于40000，用来除以40000以内素数
                return true ;
        }
        return false ;  //40000内的素数都除不了，肯定是素数
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

        ModPow (c, p, p) ;// 快速模取幂
        if (res == c)   // res == (a^p) % p
            printf ("yes\n") ;
        else
            printf ("no\n") ;
    }
    return 0 ;
}
# include <stdio.h>
# include <math.h>



int IsPrime[5010] ;


void init()
{
    int i, j ;
    for(i = 0 ; i <= 5000 ; i++) IsPrime[i] = 1 ;
    for (i = 2 ; i<= 71 ; i++) if (IsPrime[i])
        for (j = i*i ; j <= 5000 ; j+=i) IsPrime[j] = 0 ;
}


int EulerPhi(int num)
{
    int phi = num, sq = sqrt(num) + 1, p ;
    for (p = 2 ; p <= sq ; p++) if (num%p==0)
    {
        phi = phi/p * (p-1) ;
        while (num%p==0) num /= p ;
    }
    if (num > 1) phi = phi / num * (num-1) ;
    return phi ;
}


int qpow(int a, int b, int mod)
{
    int rtn = 1, buff = a ;
    while (b)
    {
        if (b&1) rtn = (rtn*buff) % mod ;
        buff = (buff*buff)%mod ;
        b >>= 1 ;
    }
    return rtn ;
}


int main ()
{
    int ans, phi, n, i ;
    init() ;
    while (~scanf ("%d", &n))
    {
        if (n == 1 || ((n&1) == 0))
            printf ("2^? mod %d = 1\n", n) ;
        else{
            phi = EulerPhi(n) ;
            if (IsPrime[phi]) ans = phi ;
            else{
                for (i = 1 ; i <= phi ; i++) if (phi%i == 0)
                {
                    if (qpow(2,i,n) == 1){
                        ans = i ;
                        break ;
                    }
                }
            }
            printf ("2^%d mod %d = 1\n", ans, n) ;
        }
    }
    return 0 ;
}
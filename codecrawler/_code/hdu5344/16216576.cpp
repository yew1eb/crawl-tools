//ç»ä¸ä¸ªæ°ç»Aï¼é®è¿ä¸ªæ°ç»çææ(Ai+Aj)çå¼æå¼
//ç±äºå¯¹äºæ¯ä¸ä¸ªï¼Ai+Aj)^(Aj+Ai) == 0
//æä»¥ç­æ¡æ¯2*(a1^a2^a3...)
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
typedef __int64 ll ;
int main()
{
    ll n , m , l , z ;
    int t ;
    scanf("%d" , &t) ;
    while(t--)
    {
        scanf("%I64d%I64d%I64d%I64d" , &n , &m , &z, &l) ;
        ll ans = 0 ;
        ll pre = 0 ;
        ll now ;
        for(int i = 2;i <= n;i++)
        {
           now = (pre*m + z)%l ;
           ans = ans^(2*now) ;
           pre = now ;
        }
       printf("%I64d\n" , ans) ;
    }
}







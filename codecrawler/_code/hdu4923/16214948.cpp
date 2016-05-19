#include<iostream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<sstream>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<cstdio>
#include<algorithm>
#define INT __int64
using namespace std ;
const double esp = 0.00000001 ;
const int mod = 1e9 + 7 ;
const int MY = 1000 + 10 ;
const int MX = 100000 + 10 ;
double num[MX] ,len[MX] ;
int main()
{
    int Tx ,n ;
    scanf("%d" ,&Tx) ;
    while(Tx--)
    {
        scanf("%d" ,&n) ;
        int cnt = 0 ;
        double x ;
        for(int i = 0 ;i < n ;i++)
        {
             scanf("%lf" ,&x) ;
             num[cnt] = x ;
             len[cnt++] = 1 ;
             while(cnt >= 2)
             {
                 if(num[cnt-1]/len[cnt-1] > num[cnt-2]/len[cnt-2])
                            break ;
                 num[cnt-2] += num[cnt-1] ;
                 len[cnt-2] += len[cnt-1] ;
                 cnt-- ;
             }
        }
        double ans = 0 ;
        for(int i = 0 ;i < cnt ;i++)
        {
            double y = num[i]/len[i] ;
            ans += num[i]*(1.0-y)*(1.0-y) + (len[i]-num[i])*y*y ;
        }
        cout<<fixed<<setprecision(6)<<ans<<endl ;
    }
    return 0 ;
}

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
#define MOD 3780

long long Pow(long long n ,long long m, int mod)
{
    long long res = 1;
    while(m >= 1)
    {
        if(m & 1)
        {
            res = (res * n ) % mod;
        }
        n = n * n % mod ;
        m >>= 1;
    }
    return res;
}

int main()
{
    int N , K;
    while(cin >> N >> K && ( N || K))
    {
        long long  temp1 , temp2;
        temp1 = Pow(2 , 3 * N + 1 , K * 250)  - 1;
        temp2 = Pow(251 , N + 1 , K * 250) - 1;
        long long res = (temp1 * temp2) % (250 * K);
        res /= 250 ;
        res = Pow(2008 , res , K);
        cout << res <<endl;
    }
}


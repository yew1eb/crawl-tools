/* **********************************************
Auther: yew1eb
Created Time: 2015/8/2 11:58:14
File Name   : hdoj2837.cpp
*********************************************** */
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;

int powmod(int a, int d, const int & mod) 
{
    ll res = 1, tmp;
    bool b = false;
    while(d>0){
        if(d&1) {
            res = (ll)(a)*res;
            if(res >= mod) {
                b = true; res %= mod;
            }
        }
        tmp = (ll)(a)*a;
        if(tmp >= mod) { b = true; tmp %= mod; }
        a = tmp;
        d >>= 1;
    }
    if(b) res += mod;
    return int(res);
}

int euler(int n)
{
    int ans = 1;
    for(int i=2; i*i<=n; ++i) {
        if(n%i==0) {
            ans *= i-1; n /= i;
            while(n%i==0){
                ans *= i; n /= i;
            }
        }            
    }
    if(n > 1) ans *= n-1;
    return ans;
}

int f(int n, int m) 
{
    if(n==0) return 1;
    return powmod(n % 10, f(n / 10, euler(m)), m);
}
int main()
{
    int T, n, m;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        printf("%d\n", f(n, m) % m);
    }
    return 0;
}

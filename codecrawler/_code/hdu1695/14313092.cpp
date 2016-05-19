/* **********************************************
Auther: yew1eb
Created Time: 2015/8/2  9:05:23
File Name   : hdu1695_Mobius.cpp
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

const int maxn = 1000000;
bool check[maxn+10];
int prime[maxn+10];
int mu[maxn+10];
void Moblius(){
    memset(check, false, sizeof check );
    mu[1] = 1;
    int tot = 0;
    for(int i=2; i<=maxn; ++i) {
        if( !check[i] ){
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j=0; j< tot; ++j) {
            if(i * prime[j] > maxn) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

int  a, b, c, d, k;

int main()
{
    Moblius();
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf("Case %d: ", cas);
        if(k==0) {
            puts("0");
            continue;
        }
        b /= k;
        d /= k;
        if(b > d) swap(b, d);
        ll s1 = 0;
        ll s2 = 0;
        for(int i=1; i<=b; ++i) {
            s1 += (ll)mu[i]*(b/i)*(d/i);
            s2 += (ll)mu[i]*(b/i)*(b/i);
        }
        s1 -= s2/2;
        printf("%I64d\n", s1);
    }
    return 0;
}

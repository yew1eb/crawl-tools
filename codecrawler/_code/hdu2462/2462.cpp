#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define LL long long
#define nmax 134165
#define nnum 13000
#define num8 8
#define num9 9
#define num10 10
int flag[nmax], prime[nnum], cpfactor[nnum];
LL pfactor[nnum], factor[nnum];
int plen, len_pfactor, len_factor;
void mkprime(){
    int i,j;
    memset(flag,-1,sizeof(flag));
    for(i = 2, plen = 0; i < nmax; i ++){
        if(flag[i])
            prime[plen ++] = i;
        for(j = 0; (j < plen) && (i * prime[j] < nmax); j ++){
            flag[ i * prime[j] ] = 0;
            if(i % prime[j] == 0)
                break;
        }
    }
}
int cmp(const void *a, const void *b) {
    LL temp = *(LL *) a - *(LL *) b;
    if (temp > 0) {
        return 1;
    } else if (temp < 0) {
        return -1;
    }
    return 0;
}
LL getPhi(LL n) {//求欧拉函数的值
    int i, te;
    LL phi;
    te = (int) sqrt(n * 1.0);
    for (i = 0, phi = n; (i < plen) && (prime[i] <= te); i++) {
        if (n % prime[i] == 0) {
            phi = phi / prime[i] * (prime[i] - 1);
            while (n % prime[i] == 0) {
                n /= prime[i];
            }
        }
    }
    if (n > 1) {
        phi = phi / n * (n - 1);
    }
    return phi;
}
LL modular_multi(LL a, LL b, LL c) {// a * b % c
    LL res, temp;
    res = 0, temp = a % c;
    while (b) {
        if (b & 1) {
            res += temp;
            if (res >= c) {
                res -= c;
            }
        }
        temp <<= 1;
        if (temp >= c) {
            temp -= c;
        }
        b >>= 1;
    }
    return res;
}
LL modular_exp(LL a, LL b, LL c) { //a ^ b % c 改成mod_pow就不行，中间发生了溢出，还是这个模板靠谱
    LL res, temp;
    res = 1 % c, temp = a % c;
    while (b) {
        if (b & 1) {
            res = modular_multi(res, temp, c);
        }
        temp = modular_multi(temp, temp, c);
        b >>= 1;
    }
    return res;
}
LL gcd(
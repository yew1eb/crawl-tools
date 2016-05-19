//数论，n!末尾0的个数
/*
摘自：KIDxの博客
N! = 1 * 2 * 3 * (2*2) * 5 * (2*3) * 7... 
产生10的原因是有2,5的因子，显然在N!中2的个数大于5的个数，所以只需求出5的个数即可 
求 N! (1*2*3*4*5*...*N)里有多少个5其实可以转化成： 
N!中：是5的倍数的数+是5^2的倍数的数+5^3..... 
如50!： 
含有10个5的倍数的数：5,15,20,25,30,35,40,45,50 【50/5=10】 
含有2个5^2的倍数的数：25,50【50/(5^2)=2】 
可见N!中一共有12个5相乘，那么尾0也必有12个 
*/

#include <cstdio>
#include <iostream>

using namespace std;

int solve(int n) {
    int sum = 0;
    while (n) {
        sum += n / 5;
        n /= 5;
    }
    return sum;
}

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) {
        int n;
        scanf ("%d", &n);
        int ans = solve(n);
        printf ("%d\n", ans);
    }
    return 0;
}
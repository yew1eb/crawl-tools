/*
 * hdu2207/win.cpp
 * Created on: 2012-11-5
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
#include <bitset>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    int n;
    while(scanf("%d", &n) == 1) {
        n += 2;
        string temp("11111111111111111111111111111111");
        for(int i = 31; i > 0; i--) {
            if(n > 0) {
                temp[i] = '0';
            }
            n >>= 1;
        }
        bitset<32> b(temp);
        unsigned char *p = (unsigned char *)(&b);
        for(int i = 3; i > 0; i--) {
            printf("%u.", (unsigned int)p[i]);
        }
        printf("%u\n", (unsigned int)p[0]);
    }
    return 0;
}
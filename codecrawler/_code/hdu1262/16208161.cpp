#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define mst(a,b) memset(a,b,sizeof(a))
#define eps 10e-8

const int MAX_ = 10010;
const int N = 10010;
const int INF = 0x7fffffff;

int prime[MAX_];

int isprime(int n) {
    if(n < 2)return 0;
    for(int i =2; i <= n/2; ++i) {
        if(n % i == 0)return 0;
    }
    return 1;
}

int PrimeTable(int prime[]) { //æå°ç´ æ°è¡¨
    int pNum=0;
    prime[pNum++]=2;

    for(int i=3; i<=N; i+=2) { //å¥å¶æ³
        bool flag=true;
        for(int j=0; prime[j]*prime[j]<=i; j++) //æ ¹å·æ³+éå½æ³
            if(!(i%prime[j])) {
                flag=false;
                break;
            }
        if(flag)
            prime[pNum++]=i;
    }
    return pNum;
}


int main() {
    int n, T, cnt, p1,p2, mini ;
    cnt = PrimeTable(prime);
    //cout<<cnt<<endl;
    while(cin>>n) {
        mini = INF;
        for(int i = n/2; i > 1; ++i) {
            if(isprime(i)) {
                int tmp = n - i;
                if(isprime(tmp)) {
                    if(abs(tmp - i) < mini) {
                        mini = tmp - prime[i];
                        p1 = tmp;
                        p2 = i;
                    }
                    break;
                }
            }

        }
        if(p1 > p2)swap(p1,p2);
        printf("%d %d\n",p1, p2);
    }
    return 0;
}

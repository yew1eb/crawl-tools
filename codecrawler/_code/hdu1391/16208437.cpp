#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int a, b;
        int k;
        scanf("%d%d", &a, &b);
        if(0 == a && 0 == b) {
            printf("0\n");
            continue;
        }
        if(a == b+2) {
            if(0 == a%2) {
                k = a-1;
            }
            else {
                k = a-2;
            }
        }
        else if(a == b) {
            if(0 == a%2) {
                k = a-1;
            }
            else {
                k = a;
            }
        }
        int t = (k+1)/2;
        int c = 4*t-3;
        int ans = -1;
        if(a == b) {
            if(0 == a%2) {
                ans = c+3;
            }
            else {
                ans = c;
            }
        }
        else if(a == b+2) {
            if(0 == a%2) {
                ans = c+1;
            }
            else {
                ans = c+2;
            }
        }
        if(-1 != ans) {
            printf("%d\n", ans);
        }
        else {
            printf("No Number\n");
        }
    }
    return 0;
}

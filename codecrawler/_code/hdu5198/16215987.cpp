#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define INF 0x7fffffff
using namespace std;

char str[350];

int main() {
    while(scanf("%s", str) != EOF) {
        int len = strlen(str);
        if(len <= 2 || len % 3 != 0 || str[0] == str[len - 1]) {
            printf("NO\n");
            continue;
        }
        
        int a[5] = {0, 0, 0};
        int sum = 0;
        char cur = str[0];
        for(int i = 0; i < len; i++) {
            if(str[i] == cur) a[sum]++;
            else {
                sum++;
                a[sum] ++;
                cur = str[i];
            }
        }
        
        //printf("%d %d %d %d\n", a[0], a[1], a[2], sum);
        int tmp = len / 3;
        if((len % 3 == 0) && sum == 2 && a[0] == tmp && a[1] == tmp && a[2] == tmp) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
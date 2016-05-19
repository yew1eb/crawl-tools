#include <stdio.h>

#define maxn 100005
typedef __int64 LL;

LL arr[maxn];

int main() {
    int n, i;
    for(i = 1; i <= 100000; ++i)
        if(i % 3) arr[i] = arr[i-1] + i;
        else arr[i] = arr[i-1] + (LL)i * i * i;
    while(scanf("%d", &n), n >= 0)
        printf("%I64d\n", arr[n]);
}
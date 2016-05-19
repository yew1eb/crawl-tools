#include <stdio.h>
__int64 a[21] = {0, 0, 1, 2};

int main(){
    int i;
    for(i = 4; i != 21; ++i)
        a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
    while(scanf("%d", &i) == 1)
        printf("%I64d\n", a[i]);
    return 0;
}
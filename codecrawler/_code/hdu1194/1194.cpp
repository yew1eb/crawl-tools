#include <stdio.h>

int main()
{
    int t,m,n;
    scanf("%d", &t);
    while(t-- && scanf("%d%d", &m, &n))
        if(m < n || (m+n) & 1) puts("impossible");
        else printf("%d %d\n", (m+n)/2, (m-n)/2);
    return 0;
}
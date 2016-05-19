#include <stdio.h>

int main()
{
    int T, n, m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n<=m)
        {
            puts("Grass");
            continue;
        }
        if(n %(m+1) == 0) puts("Rabbit");
        else  puts("Grass");
    }
    return 0;
}

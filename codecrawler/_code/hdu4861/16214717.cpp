#include <stdio.h>
#include <math.h>
int main()
{
    int k, p;
    while(scanf("%d%d", &k, &p) != EOF){
        if(k / (p-1) % 2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
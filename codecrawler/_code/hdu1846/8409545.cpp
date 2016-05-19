#include <stdio.h>

int main()
{
    int C, n, m;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d%d", &n, &m);
        if(n%(m+1)==0) printf("second\n");
        else printf("first\n");
    }
    return 0;
}

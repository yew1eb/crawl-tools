
#include <stdio.h>

int a[1005];
int main()
{
    int n, i, x;
    int total;
    while(scanf("%d",&n),n)
    {
        total = 0;
        for(i=0; i<n; i++) scanf("%d",&a[i]);
        scanf("%d",&x);
        for(i=0; i<n; i++)
        if(a[i]==x) total++;
        printf("%d\n",total);
    }
    return 0;
}

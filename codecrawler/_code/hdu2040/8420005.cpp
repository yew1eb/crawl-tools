#include <stdio.h>
#include <string.h>
#include <math.h>
int ch(int x)
{
    int j, k, s;
    if(x==0) return 0;
    k = (int)sqrt(x);
    s = 1;
    for(j=2; j<=k; j++)
    if(x%j==0)
    {
        if(j*j==x) s +=j;
        else s +=j +x/j;
    }
    return s;
}
int main()
{
    int n, a, b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        if(a ==ch(b) && b ==ch(a) ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

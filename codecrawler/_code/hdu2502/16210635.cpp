#include<iostream>
#include<algorithm>
int main()
{
    int n, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", (1<<(n-1)) + (n-1)*(1<<(n-2)));
    }
    return 0;
}
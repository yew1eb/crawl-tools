#include <stdio.h>

int main()
{
    int t;
    int n;
    int i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        i = 0;
        int first = 1;
        while(n)
        {
            if(n%2==1)
            {
                if(!first) printf(" ");
                else first = 0;
                printf("%d",i);
            }
            n /= 2;
            i++;
        }
        printf("\n");
    }
    return 0;
}

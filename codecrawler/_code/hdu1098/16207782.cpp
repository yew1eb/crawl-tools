#include <stdio.h>

int main()
{
    int k,a;
    while(~scanf("%d",&k))
    {
        for(a = 1;a<=65;a++)
        {
            if((18+a*k)%65 == 0)
            {
                printf("%d\n",a);
                break;
            }
        }
        if(a>65)
        printf("no\n");
    }

    return 0;
}

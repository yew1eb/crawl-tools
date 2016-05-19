#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,e,c;
        scanf("%d%d%d",&r,&e,&c);
        if(e-c > r)
        printf("advertise\n");
        else if(e-c == r)
        printf("does not matter\n");
        else if(e-c < r)
        printf("do not advertise\n");
    }

    return 0;
}

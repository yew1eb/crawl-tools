#include <stdio.h>

int main()
{
    int s,d;
    while(~scanf("%d%d",&s,&d) && (s||d))
    {
        if(!s)
        {
            printf("1\n");
            continue;
        }
        int k = 0,cnt = 0;
        while(s%60)
        {
            if(cnt > 1000)
            {
                k = 1;
                break;
            }
            s = s+s*d;
            s%=60;
            cnt++;
        }
        if(k)
            printf("Impossible\n");
        else
            printf("%d\n",cnt);
    }

    return 0;
}

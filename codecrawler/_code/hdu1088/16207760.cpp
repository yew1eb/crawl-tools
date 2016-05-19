#include <stdio.h>
#include <string.h>

int main()
{
    char s[10000];
    int len;
    int cnt = 0;
    while(~scanf("%s",s))
    {
        if(!strcmp(s,"<br>"))
        {
            cnt = 0;
            printf("\n");
        }
        else if(!strcmp(s,"<hr>"))
        {
            if(cnt)
            printf("\n--------------------------------------------------------------------------------\n");
            else
            printf("--------------------------------------------------------------------------------\n");
            cnt = 0;
        }
        else
        {
            int len = strlen(s);
            if(!cnt)
            {
                cnt = len;
                printf("%s",s);
            }
            else if(cnt+len+1>80)
            {
                cnt=len;
                printf("\n%s",s);
            }
            else
            {
                cnt+=len+1;
                printf(" %s",s);
            }
        }
    }
    printf("\n");

    return 0;
}

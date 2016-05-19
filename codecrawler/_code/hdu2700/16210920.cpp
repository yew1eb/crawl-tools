#include <stdio.h>
#include <string.h>

int main()
{
    char str[10000];
    int len,i,cnt;

    while(gets(str))
    {
        cnt = 0;
        if(!strcmp(str,"#"))
        break;
        len = strlen(str);
        for(i = 0;i<len;i++)
        {
            if(str[i] == '1')
            cnt++;
        }
        if(str[len-1] == 'e')
        {
            if(cnt%2 == 0)
            str[len-1] = '0';
            else
            str[len-1] = '1';
        }
        else if(str[len-1] == 'o')
        {
            if(cnt%2 == 0)
            str[len-1] = '1';
            else
            str[len-1] = '0';
        }
        str[len] = '\0';
        printf("%s\n",str);
    }

    return 0;
}

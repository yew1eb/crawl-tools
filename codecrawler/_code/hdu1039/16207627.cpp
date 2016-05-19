#include <stdio.h>
#include <string.h>

int yuan(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

int main()
{
    int len,i;
    char s[100000];
    while(~scanf("%s",s) && strcmp(s,"end"))
    {
        int flag = 1;
        len = strlen(s);
        for(i = 0; i<len; i++)
        {
            if(yuan(s[i]))
                break;
        }
        if(i>=len)
            flag = 0;
        for(i = 1; i<len; i++)
        {
            if(!flag)
                break;
            if(s[i] == s[i-1])
            {
                if(s[i]=='e' || s[i] == 'o')
                continue;
                flag = 0;
                break;
            }
        }
        for(i = 2; i<len; i++)
        {
            if(!flag)
                break;
            if(yuan(s[i]) && yuan(s[i-1]) && yuan(s[i-2]))
                flag = 0;
            else if(!yuan(s[i]) && !yuan(s[i-1]) && !yuan(s[i-2]))
                flag = 0;
        }
        if(flag)
            printf("<%s> is acceptable.\n",s);
        else
            printf("<%s> is not acceptable.\n",s);
    }

    return 0;
}

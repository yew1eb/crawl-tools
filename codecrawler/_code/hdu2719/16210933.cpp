#include <stdio.h>
#include <string.h>

int main()
{
    char str[10000];
    int i,len;
    while(gets(str))
    {
        if(!strcmp(str,"#"))
        break;
        len = strlen(str);
        for(i = 0;i<len;i++)
        {
            if(str[i] == ' ')
            printf("%%20");
            else if(str[i] == '!')
            printf("%%21");
            else if(str[i] == '$')
            printf("%%24");
            else if(str[i] == '%')
            printf("%%25");
            else if(str[i] == '(')
            printf("%%28");
            else if(str[i] == ')')
            printf("%%29");
            else if(str[i] == '*')
            printf("%%2a");
            else
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}

#include <string.h>
#include <stdio.h>

int main()
{
    char str[10000];
    int len,i,a[26],sum;
    for(i = 0;i<26;i++)
    {
        a[i] = i+1;
    }
    while(gets(str))
    {
        if(strcmp(str,"#") == 0)
        break;
        len = strlen(str);
        sum = 0;
        for(i = 0;i<len;i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            sum+=(i+1)*a[str[i]-'A'];
        }
        printf("%d\n",sum);
    }

    return 0;
}

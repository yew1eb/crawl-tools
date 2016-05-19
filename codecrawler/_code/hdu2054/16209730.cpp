#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
    char a[100000],b[100000];
void change(char s[])
{
    int i,len;
    len  = strlen(s);
    if(strstr(s,"."))
    {
        for(i = len-1; s[i] == '0'; i--)
        {
            s[i] = '\0';
            len--;
        }
    }
    if(s[len-1] == '.')
        s[len-1] = '\0';
}

int main()
{

    while(scanf("%s%s",a,b)!=EOF)
    {
        change(a);
        change(b);
        if(strcmp(a,b))
        printf("NO\n");
        else
        printf("YES\n");
    }

    return 0;
}

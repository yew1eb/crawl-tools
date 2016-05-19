#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, t,flag;
    char s[1000];
    scanf("%d",&n);
    scanf("%*c");
    while(n--)
    {
        gets(s);
        flag = 1;t=strlen(s);
        for(i=0;i<t/2; i++)
            if(s[i] != s[t-i-1]) {flag = 0; break;}
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

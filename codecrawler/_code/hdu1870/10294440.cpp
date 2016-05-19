#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    while(gets(s))
    {
        int ans=0;
        for(int i=0; i<strlen(s); i++)
            if(s[i]=='(')ans++;
            else if(s[i]==')')ans--;
            else break;
        printf("%d\n",ans);
    }
    return 0;
}

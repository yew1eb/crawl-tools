#include<string.h>
#include<stdio.h>
#define MAXN 100002
char s[MAXN],temp[MAXN];
int main()
{
    int i,len;
    while(~scanf("%s",s))
    {
        len=strlen(s);
        for(i = 0; i < len; ++i)
        {
            if(s[i]=='['||s[i]==']')
                temp[i] = '\0';
            else
                temp[i] = s[i];
        }
        temp[len]='\0';
        for(i = len - 1; i > -1; --i)
        {
            if(s[i]=='[')
                printf("%s",temp+i+1);
        }
        if(!(s[0]=='['||s[0]==']'))
            printf("%s",temp);
        for(i = 1; i < len; ++i){
            if(s[i]==']')
                printf("%s",temp+i+1);
        }
        printf("\n");
    }
    return 0;
}
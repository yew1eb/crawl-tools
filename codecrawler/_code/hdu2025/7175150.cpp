#include<stdio.h>
#include<string.h>
int main()
{
    int i, len;
    int x;
    char s[120];
    while(scanf("%s",s)!=EOF)
    {
         len=strlen(s);
         x=0;
         for(i=0;i<len;i++) if(s[i]>x) x=s[i];
         for(i=0;i<len;i++)
            {
                printf("%c",s[i]);          
                if(s[i]==x) printf("(max)");
            }
         printf("\n");
    }
    return 0;
}
                   
             

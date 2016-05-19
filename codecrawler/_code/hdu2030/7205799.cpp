#include<stdio.h>
#include<string.h>
#define MAXN 1000
int main()
{
    int n, i, len;
    char s[MAXN];
    scanf("%d\n",&n);
    while(n--)
    {
         gets(s);
         len = strlen(s)-1;
         i= 0;
         int t = 0;
         while(i<=len)
         {
             if(s[i]<0){t++; i+=2;}
             else i++;
         }
         printf("%d\n",t);
    }
    return 0;
}

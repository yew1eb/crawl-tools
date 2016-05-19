#include <stdio.h>
#include <string.h>
char a[100001],b[100001],c[100001];
int main()
{
    while(~scanf("%s",a))
    {
        scanf("%s",b);
        strcpy(c,a);
        strcat(a,c);
        if(strstr(a,b))
            printf("yes\n");
        else 
            printf("no\n");
    }
    return 0;
}
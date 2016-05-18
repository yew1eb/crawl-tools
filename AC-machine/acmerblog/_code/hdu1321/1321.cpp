#include<stdio.h>
#include<string.h>
int main()
{
    char str[70];
    int n;
    scanf("%d",&n);
    getchar();//吸收回车
    while(n--)
    {
        int i;
        gets(str);
        for(i=strlen(str)-1;i>=0;i--)
            printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
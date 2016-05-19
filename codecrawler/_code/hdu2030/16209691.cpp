#include<stdio.h>
char str[1111111];
int main()
{
    int cas,i,j,cnt;
    scanf("%d",&cas);
    getchar();
    while(cas--)
    {
        cnt=0;
         gets(str);
        // printf("ddd");
         for(i=0;str[i]!='\0';i++)
             if(str[i]<0||str[i]>127) cnt++;
         printf("%d\n",cnt/2);
    }
    return 0;
}
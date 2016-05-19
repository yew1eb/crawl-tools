#include<stdio.h>
#include<string.h>
char num[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int judge(char s[])   //å°åä¸ªè±æåè¯è½¬æ¢ææ°å­
{
    int i;
    for(i=0;i<=9;i++)
    {
        if(strcmp(s,num[i])==0)
        {
            return i;
        }
    }
}
int main()
{
    int a,b;
    char s[6];
    while(scanf("%s",s)!=EOF)
    {
        a=b=0;
        while(strcmp(s,"+")!=0)   //æ±açå¼
        {
            a=a*10+judge(s);
            scanf("%s",s);
        }
        scanf("%s",s);
        while(strcmp(s,"=")!=0)   //æ±bçå¼
        {
            b=b*10+judge(s);
            scanf("%s",s);
        }
        if(a+b==0)   //a+b=0æ¶ç»æ
        {
            break;
        }
        printf("%d\n",a+b);
    }
    return 0;
}
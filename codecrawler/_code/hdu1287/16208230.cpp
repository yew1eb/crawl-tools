#include<stdio.h>
int main()
{
    int c;
    int t;
    char x;
    int a[100000];
    int i,j;
    char b[100000];
    while(scanf("%d",&t)!=EOF)
    {
       for(i=0;i<t;i++)
            scanf("%d",&a[i]);
        for(i=0;i<26;i++)       //éä¸ªå­æ¯å¥ç¨ï¼ç´å°è§£å¯åææå­ç¬¦å¨é¨ä¸ºå¤§åå­æ¯ä¸ºæ­¢ï¼
        {
            c=i+'A';
            for(j=0;j<t;j++)
            {
                b[j]=a[j]^c;
                if(b[j]<'A'||b[j]>'Z')
                    break;
            }
            if(j==t)
                break;
        }
        for(i=0;i<t;i++)
            printf("%c",b[i]);
        printf("\n");
    }
    return 0;
}
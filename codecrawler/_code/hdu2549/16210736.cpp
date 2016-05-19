#include <stdio.h>
#include <string.h>

int main()
{
    int n,m,len,flag,i;
    char str[100];

    scanf("%d%*c",&n);
    while(n--)
    {
        scanf("%s%d",str,&m);
        len = strlen(str);
        if(!strstr(str,"."))//å¦æä¸å«å°æ°ï¼å³åé¢å°æ°å¨æ¯0
        {
            printf("0\n");
            continue;
        }
        for(i = 0;i<=len;i++)//æ¾å°å°æ°ç¹
        {
            if(str[i] == '.')
            break;
        }
        if(m>len-i-1)//å¤æ­è¦æ±çä½æ¯å¦æ¯ææå°æ°é¿
        printf("0\n");
        else//è¾åºå°æ°
        printf("%c\n",str[i+m]);
    }

    return 0;
}

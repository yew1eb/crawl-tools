/*
        Author:snowflake
        Time:2012/5/13
        Desc:Water
*/
/*
é¢ç®å¤§æï¼ç»è®¡ç¸ç­è¿ç»­å­æ¯ä¸ªæ°ï¼1ä¸ªç´æ¥è¾åºï¼>=2è¾åºä¸ªæ°å ä¸ä¸ä¸ªå­ç¬¦
15msçä»£ç ï¼å¾å®¹ææãã å°±æ¯éä½æ¯è¾ 
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    char str[10005];
    int num, i, j;
    cin >> n;
    while(n--)
    {
        scanf("%s",&str);
        int a = 1;//å¾ªç¯å¢éæé 
        for(i = 0; i < strlen(str); i += a)
        {
            //è¿ä¸¤ä¸ªæ³¨æåæº¯ 
            num = 1;
            a = 1;
            for(j = i + 1; j < strlen(str); j++)
            {
                //å¤æ­ 
                if(str[i] == str[j])
                {
                    num++;
                    a++;//ä¸ä¸æ¬¡å¾ªç¯ä»å açå°æ¹å¼å§    
                }    
                else
                    break;    
            }
            if(num == 1)
                printf("%c",str[i]);
            else
                printf("%d%c",num,str[i]);
        }
        printf("\n");
    }
    return 0;
}

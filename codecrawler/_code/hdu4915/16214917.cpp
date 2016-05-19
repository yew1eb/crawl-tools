#include<cstdio>
#include<cstring>
const int N = 1e6 + 50;
char str[N], s[N];
int len;
int judge() //å¤æ­å½åçå­ç¬¦ä¸²æ¯å¦å¹é
{
    int l = 0;  //è®°å½å·¦æ¬å·çæ°é
    int r = 0;  //è®°å½å³æ¬å·çæ°é
    int num = 0;  //è®°å½å·²ç»éåè¿çå­ç¬¦æ°é
    int i;
    for(i = 0; i < len; i++)  //ä»åå¾åå¤æ­
    {
        num++;
        if(num == 1)
        {
            if(s[i] == '?')
                s[i] = '(';
        }
        if(s[i] == '(') l++;
        else if(s[i] == ')') r++;
        if(r > num/2)  //å³æ¬å·æ°éå¤ªå¤ï¼æ æ³å®å¨å¹é
            return 0;
        if(r * 2 == num)  //ånumä¸ªå¯ä»¥å®å¨å¹é
        {
            l = r = num = 0;
        }
    }
    if(l > num/2) return 0;
    
    num = l = r = 0;
    for(i = len - 1; i >= 0; i--)  //ä»åå¾åå¤æ­
    {
        num++;
        if(num == 1)
        {
            if(s[i] == '?')
                s[i] = ')';
        }
        if(s[i] == '(') l++;
        else if(s[i] == ')') r++;
        if(l > num / 2) return 0;  //å·¦æ¬å·æ°éå¤ªå¤ï¼æ æ³å®å¨å¹é
        if(l * 2 == num)  //ånumä¸ªå¯ä»¥å®å¨å¹é
        {
            l = r = num = 0;
        }
    }
    if(r > num/2) return 0;
    
    return 1;
}
int main()
{
    int flag_l, flag_r, i;
    while(~scanf("%s",str))
    {
        len = strlen(str);
        if(len & 1)
        {
            printf("None\n");
            continue;
        }

        strcpy(s, str);
        flag_l = judge();  //åè®¾æ²¡æ '?'ï¼å¤æ­æ¯å¦å¹é

        if(!flag_l)
        {
            printf("None\n");
            continue;
        }
        for(i = 0; i < len; i++)
        {
            if(str[i] == '?')
            {
                strcpy(s, str);

                s[i] = ')';
                flag_l = judge();

                s[i] = '(';
                flag_r = judge();

                if(flag_l && flag_r)
                {
                    printf("Many\n");
                    break;
                }
                if(!flag_l && !flag_r)
                {
                    printf("None\n");
                    break;
                }
                if(flag_l && !flag_r)
                    s[i] = ')';
                else if(!flag_l && flag_r)
                    s[i] = '(';
            }
        }
        if(i == len)
            printf("Unique\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100005];
    int ans;
    while(gets(str))
    {
        int len = strlen(str);
        int i,j,k;
        ans = 0;
        for(i = 0;i<len;i++)
        {
            for(j = 0,k = i;j<len;j++,k++)//è¿éæ¯ç»è®¡æ¯æ¬¡å¹éçé¿åº¦ï¼å³é®ç¹éè¦èªå·±å¨èç¨¿çº¸ä¸æ¼ç¤ºå°±æäº
            {
                if(str[j]!=str[k])
                break;
            }
            ans+=j;
        }
        printf("%d\n",ans%256);
    }

    return 0;
}

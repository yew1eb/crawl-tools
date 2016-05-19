#include <cstdio>
#include <cstring>
char s[1100047];
int hash[247];
int main()
{
    __int64 n;
    while(~scanf("%I64d",&n) && n)
    {
        getchar();
        gets(s);
        __int64 len = strlen(s);
        memset(hash,0,sizeof(hash));
        __int64 i, star = 0, ans = 0, diff = 0;
        for(i = 0; i < len; i++)
        {
            ++hash[s[i]];//æ å°å¼+1
            if(hash[s[i]] == 1)//å¦ææ¯ç¬¬ä¸æ¬¡åºç°
            {
                diff++;//ä¸åå­æ¯æ°+1
                if(diff > n)//å¦æè¶è¿nä¸ªä¸åå­æ¯
                {
                    while(--hash[s[star++]] > 0);//èµ·ç¹åå³æªå¨ ç´å°æ¶å»ä¸ä¸ªå­æ¯                  
                    diff--;//ä¸åå­æ¯æ°è¿åæ­£å¸¸åå¼
                }
            }
            int LEN = i-star+1;//å¾å°æ­¤æ¶çä¸²é¿åº¦
            ans = ans > LEN?ans:LEN;//ä¿å­æå¤§å¼
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

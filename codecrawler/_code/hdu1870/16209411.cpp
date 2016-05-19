#include<stdio.h>
int main()
{
    int ans,i;
    char s[1001];
    while(scanf("%s",s)!=EOF)
    {
        for(ans=i=0;;i++)
        {
            if(s[i]=='B')
            {
                break;
            }
            else if(s[i]=='(')   //æ°âï¼âçä¸ªæ°ï¼å³å¯ç¥éçå­æ°
            {
                ans++;
            }
            else   //å½âBâæ²¡åºç°æ¶åºç°âï¼âè¡¨ç¤ºè¯¥çå­éä¸ç¤¼ç©æ å³ï¼æä»¥ä¸æå¼å®ï¼å³æ­¤æ¶ans=ans-1
            {
                ans--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
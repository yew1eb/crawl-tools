#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[111];
int dpa[111],dpb[111];

int main()
{
    int t,i,len,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str+1);
        dpa[0] = 0;
        dpb[0] = 1;
        for(i = 1; str[i]; i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                dpa[i] = min(dpa[i-1]+1,dpb[i-1]+2);//è¥ç¯äº®ï¼åç´æ¥æå­æ¯ï¼è¥ç¯ç­ï¼åæå­æ¯åå¼ç¯
                dpb[i] = min(dpa[i-1]+2,dpb[i-1]+2);//è¥ç¯äº®ï¼åè¦åæå­æ¯åå³ç¯ï¼è¥ç¯ç­ï¼åæshift+å­æ¯
            }
            else if(str[i]>='A' && str[i]<='Z')
            {
                dpa[i] = min(dpa[i-1]+2,dpb[i-1]+2);
                dpb[i] = min(dpa[i-1]+2,dpb[i-1]+1);
            }
        }
        printf("%d\n",min(dpb[i-1]+1,dpa[i-1]));//æåè¦å³ç¯ï¼dpbè¦+1
    }

    return 0;
}

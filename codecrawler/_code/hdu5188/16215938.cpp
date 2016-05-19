/**
hdu5188 æéå¶æ¡ä»¶ç01èåé®é¢
é¢ç®å¤§æï¼ænéé¢ié¢ç¨æ¶tiç§ï¼å¾åviï¼å¨liæ¶é´ç¹ä¹åä¸è½ååºæ¥ï¼èä¸ä¸éé¢ä¸è½åå¼å æ¬¡åï¼ä¸æ¦å¼å§åï¼å¿é¡»å¨tiæ¶é´åæå®åå®ï¼
          é®å¾å°wåçæå°ç¨æ¶æ¯å¤å°
è§£é¢æè·¯ï¼å¾å01èåçåºæ¬é¢ï¼ä½æ¯æä¸ä¸ªliåéåä¸è½ACçéå¶ï¼å æ­¤ç¬¬iéé¢å¿é¡»å¨ææ©ç¬¬ï¼li-tiï¼æ¶å»åï¼æä»¬æç§l-téå¢æåºï¼ç¶åæç§ç»å¸è§£æ³æ¥å
          å°±è¡äº
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct note
{
    int t,v,l;
    bool operator <(const note &other)const
    {
        return l-t<other.l-other.t;
    }

}node[35];

int n,m;
int dp[3000005];

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int sum=0,ans=0,up=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&node[i].t,&node[i].v,&node[i].l);
            sum+=node[i].v;
            ans+=node[i].t;
            up=max(up,node[i].l);
        }
        if(m>sum)
        {
            printf("zhx is naive!\n");
            continue;
        }
        sort(node,node+n);
        up=max(up,ans);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=up;j>=node[i].l;j--)
            {
                if(j>=node[i].t)
                {
                    dp[j]=max(dp[j],dp[j-node[i].t]+node[i].v);
                }
            }
        }
        int flag=0;
        for(int i=0;i<=up;i++)
        {
            if(dp[i]>=m)
            {
                printf("%d\n",i);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("zhx is naive!\n");
        }
    }
    return 0;
}

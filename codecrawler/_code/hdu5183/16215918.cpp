/**
hdu 5183  hash
é¢ç®å¤§æï¼ NP?sum(i,j)=ai?ai+1+ai+2+?+(?1)j?iajï¼æ±ç»å®åºåä¸­æ¯å¦æä¸ä¸ªå­åºåå¾æ°ä¸ºk
è§£é¢æè·¯ï¼é¢ç®æ°æ®å¾å¤§ï¼åªè½ç¨O(n)çå¤æåº¦ãçäºæ­çµçè§£é¢æ¥ååï¼å¾ä¹æçè§£ãææ±å°åºåçåç¼åè¡¨ç¤ºåºæ¥(sum[0]-sum[1]+sum[2]-â¦â¦)
          ç¶åä»åå¾åæä¸¾ææ±åºé´çç¬¬ä¸ä¸ªä½ç½®iï¼è¥ä¸ºå¥æ°é£ä¹å¨h1çåå¸è¡¨ä¸­å¯»æ¾æ¯ä¸æ¯å­å¨sum[i]-k,å¦ææ²¡æå°sum[i]æå¥åå¸è¡¨ã
          å¦æiä¸ºå¶æ°é£ä¹å¨h2ä¸­å¯»æ¾-sum[i]-kï¼å°-sum[i]æå¥åå¸è¡¨ä¸­ã
          ç±äºåå¸è¡¨çæå¥åæ¥å¯»å¤æåº¦æ¥è¿O(1)ï¼å æ­¤æä»¬çç®æ³å¤æåº¦æ»ä½ä¸ºO(n)
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define LL long long
const int MAXN=1000010;
const int HASH=1000007;

struct HASHMAP
{
    int head[HASH],next[MAXN],ip;
    LL state[MAXN];
    void init()
    {
        memset(head,-1,sizeof(head));
        ip=0;
    }
    bool check(LL val)
    {
        int h=(val%HASH+HASH)%HASH;
        for(int i=head[h]; i!=-1; i=next[i])
            if(state[i]==val)return true;
        return false;
    }
    int insert(LL val)
    {
        int h=(val%HASH+HASH)%HASH;
        for(int i=head[h]; i!=-1; i=next[i])
        {
            if(val==state[i])
                return 1;
        }
        state[ip]=val,next[ip]=head[h],head[h]=ip++;
        return 0;
    }
} h1,h2;

LL a[MAXN];
int n,k;
int main()
{
    int T,tt=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%I64d",&a[i]);
        bool flag=false;
        LL sum=0;
        h1.init(),h2.init();
        h1.insert(0),h2.insert(0);
        for(int i=n-1; i>=0; i--)
        {
            if(flag==true)break;
            if(i&1)
                sum-=a[i];
            else
                sum+=a[i];
            if(i%2==0)
            {
                if(h1.check(sum-k))
                    flag=true;
            }
            else
            {
                if(h2.check(-sum-k))
                    flag=true;
            }
            h1.insert(sum);
            h2.insert(-sum);
        }
        printf("Case #%d: ",++tt);
        if(flag)printf("Yes.\n");
        else printf("No.\n");
    }
    return 0;
}

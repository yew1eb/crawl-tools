#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int num[20],vis[5005];
int n,c,m;

struct node
{
    int s[505];//å°æ¯ä¸ä½çå­ç¬¦åå¥æ­¤æ°ç»
    int len;
};

int print(node a)//è¾åºå½æ°
{
    int i;
    for(i = 0; i<a.len; i++)
    {
        if(a.s[i]<=9)
            printf("%d",a.s[i]);
        else
            printf("%c",a.s[i]+'A'-10);
    }
    printf("\n");
}

int mod(node a)//ç±äºæ°å­å¤§ï¼éç¨è¿ç§å¤§æ°åæ¨¡æ¹å¼
{
    int i,tem = 0;
    for(i = 0; i<a.len; i++)
    {
        tem = (tem*c+a.s[i])%n;//ç±äºæ¯nè¿å¶ï¼temå¨åé¢çåºç¡ä¸ä¹ä»¥è¿å¶æ°cå¨å ä¸ä¸ä¸ä½ï¼å¦æè½æ´é¤nï¼é£å¿å®æ¯nçåæ°ï¼åæç«
    }
    return tem;
}

int BFS()
{
    memset(vis,0,sizeof(vis));
    node a;
    queue<node> Q;
    a.len = 0;
    int i,r;
    for(i = 1; i<16; i++)//ç±äºç¬¬ä¸ä½ä¸è½ä¸º0ï¼æä»¥ä»1å¼å§
    {
        if(num[i])//è¿ä¸ªæ°æ¯ç»åºçæ ·ä¾
        {
            a.s[0] = i;//åå¥æ°ç»
            a.len = 1;//é¿åº¦åå
            r = mod(a);
            if(!r)//æ¨¡ä¸º0ï¼åè¯å®æ¯nçåæ°ï¼è¾åº
            {
                print(a);
                return 1;
            }
            else
            {
                if(!vis[r])//ä½æ°ä¸è½ä¸ä¹ååºç°è¿çä½æ°ç¸åï¼å ä¸ºåé¢åºç°è¿çåºåï¼è¯å®åå«åæ ·ä½æ°å´å¨åé¢åºç°çåºå
                {
                    vis[r] = 1;//æ è®°è¯¥ä½æ°å·²è¢«è®¿é®
                    Q.push(a);
                }
            }
        }
    }
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(i = 0; i<16; i++)
        {
            if(num[i])
            {
                a.s[a.len] = i;
                a.len++;
                r = mod(a);
                if(!r)//ä¸ç´æ¾å°è½æ´é¤nçæ¹æ¡
                {
                    print(a);
                    return 1;
                }
                else
                {
                    if(!vis[r] && a.len<499)
                    {
                        vis[r] = 1;
                        Q.push(a);
                    }
                }
                a.len--;//æ¯ä¸æ¯è§å¾è¿éä¸a.len++è¿å¥è¯ä¼æ ééå¤ï¼å¯¼è´a.lenä¸ç´ä¸º1ï¼éäºï¼è¦æ³¨æï¼å¨rä¸ä¹ååºç°è¿çä½æ°ç¸åæ¯ï¼è¿æ¬¡çaæ¯æ²¡æåå¥éåçï¼ä¹å°±æ¯è¿æ¬¡ça.lenåå°äºï¼ä½æ¯å¨éåä¸­ça.lenå´æ²¡æåå°ï¼
            }
        }
    }
    return 0;
}

int main()
{
    int t,i;
    char str[2];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&c,&m);
        memset(num,0,sizeof(num));
        for(i = 0; i<m; i++)
        {
            scanf("%s",str);
            if(str[0]>='0' && str[0]<='9')
                num[str[0]-'0'] = 1;
            else
                num[str[0]-'A'+10] = 1;
        }
        if(n)
        {
            int flag;
            flag = BFS();
            if(!flag)
                printf("give me the bomb please\n");
        }
        else
        {
            if(num[0])
                printf("0\n");
            else
                printf("give me the bomb please\n");
        }
    }
    return 0;
}

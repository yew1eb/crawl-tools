#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define N 111

int n,ans;
int aim,ok;
int len[N],flag[N];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void dfs(int now,int finish,int pre)
{
    if(finish==aim)    {ans=1;return ;}
    if(ans)    return ;
    int i,j;
    for(i=pre+1;i<n;i++)
    {
        if(flag[i])            continue;
        if(now+len[i]>ok)    continue;
        flag[i]=1;
        if(now+len[i]==ok)    dfs(0,finish+1,-1);
        else                dfs(now+len[i],finish,i);
        flag[i]=0;
        if(ans)        return ;
        /*
            è¿ä¸ä¸ªå¾éè¦ï¼å¦æä»¥å½åè¿æ ¹ä½ä¸ºç¬¬ä¸æ ¹ï¼ç¶åä»è¿ææ
        ç¨è¿çæ¨å¤´ä¸­æ¥æ¾åºåéçï¼æ¥åå®ç»æä¸ä¸ªå®æ´çï¼å¤±è´¥äºï¼
        é£ä¹å°±è¿ç§ç»åæ¹æ³åå®ä¼å¤±è´¥ï¼å ä¸ºå©ä¸çè¿æ²¡æç¨è¿çæ¨å¤´
        ä¸­ï¼å·²ç»ç¡®å®è¿ä¸æ ¹æ æ³åå¶å®çç»æææç»åï¼ï¼ç´æ¥returnæ
        */
        if(!now)    return ;
        /*
            é¿åº¦ç¸åçæ²¡æå¿è¦è¿è¡éå¤dfsã
        */
        for(j=i+1;j<n;j++)    if(len[j]!=len[j-1])    break;
        i=j-1;
    }
}
int main()
{
    int i;
    int max,sum;
    while(scanf("%d",&n),n)
    {
        max=sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&len[i]);
            sum+=len[i];
            if(len[i]>max)    max=len[i];
        }
        qsort(len,n,sizeof(int),cmp);

        for(i=n;i>=2;i--)
        {
            ans=0;
            if(sum%i)        continue;
            if(sum/i<max)    continue;
            aim=i;ok=sum/i;
            memset(flag,0,sizeof(flag));
            dfs(0,0,-1);
            if(ans)    break;
        }
        printf("%d\n",sum/i);
    }
    return 0;
}
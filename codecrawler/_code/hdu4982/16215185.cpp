#include<stdio.h>
int k,n;
bool judge(int sum,int lef)//sumåk-1é¡¹åï¼lefå©ä¸ãsum+lef=n
{
    if(lef==0 || 2*sum<(k-1)*k)
            return false;
    if(sum==1 && lef==1)
        return false;
    int x,ss;//ssä¸ºåk-2é¡¹å
    ss=0,x=0;
    for(int i=0;i<k-2;i++)//æé æå°
    {
        x++;
        if(x==lef)
            x++;
        ss+=x;
    }
    int temp=n-ss-lef;//ç¬¬k-1é¡¹
    if(temp<=x)//åºç°è¿
        return false;
    //temp>x
    x++;//æ¹åk-2é¡¹çå¼
    //åk-2é½æ¯ç´§å¯æåçï¼å¦æ(k-1),(k-2),lefç¸ç­ï¼è³å°è¦ç§»å¨2ä¸ªä½ç½®æè½æ»¡è¶³è¦æ±ã
    if(temp==x && temp==lef)//k-2é¡¹+1ç­äºk-1é¡¹ç­äºlef
        return false;
    if(temp==x+1 && temp==lef)//k-2é¡¹+2ç­äºk-1é¡¹ç­äºlef
        return false;
    return true;
}
int main()
{
    int i;
    int lef;

    while(scanf("%d %d",&n,&k)!=EOF)
    {
        int flag=0;
        for(i=1;i*i<=n;i++)
        {
            lef=n-i*i;
            if(judge(i*i,lef))
                break;
        }
        if(i*i<=n)
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}
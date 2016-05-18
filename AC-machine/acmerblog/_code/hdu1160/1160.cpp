#include"stdio.h"
#include"stdlib.h"
#include"string.h"
struct node
{
    int n,w,s;
}mice[1111];
int dp[1111];
int index[1111],a[1111];
int cmp(const void*a,const void*b)
{
    return (*(struct node*)a).w-(*(struct node*)b).w;
}
int main()
{
    int lv=1;
    int i,j,k,max;
    memset(index,-1,sizeof(index));
    while(scanf("%d%d",&mice[lv].w,&mice[lv].s)!=EOF)
    {
        mice[lv].n=lv;
        lv++;
    }
    qsort(mice,lv,sizeof(mice[0]),cmp);
    for(i=0;i<=lv;i++)
        dp[i]=1;
    for(i=2;i<lv;i++)
    {
        for(j=1;j<i;j++)
        {
            if(mice[i].s<mice[j].s)
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    index[mice[i].n]=mice[j].n;
                }
            }
        }
    }
	
    for(max=-1,i=1;i<=lv;i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
            k=mice[i].n;
        }
    }
    printf("%d\n",max);
    for(i=max;i>=1;i--)
    {
        a[i]=k;
        k=index[k];
    }
    for(i=1;i<=max;i++)
        printf("%d\n",a[i]);
    return 0;
}
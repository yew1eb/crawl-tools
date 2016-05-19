#include<stdio.h>
#include<string.h>
#define maxn 20001
int main()
{
    int s,n,i,j,a[maxn],max,p;
    memset(a,0,sizeof(a));//**æ°ç»å¨é¨æ¸é¶**//
    a[1]=1;//**å»æå°±éäºï¼é¢ç®å±ç¶æ1è®¤ä½ç´ æ°**//
    for(i=2;i<=maxn;i++)
    {
        if(a[i]==0)
        {
            for(j=i;j<=maxn;j=j+i)//**ç­éæ³æ±ç´ æ°**//
            {
                a[j]=i;//**æ­¤æ¶jä¿å­çå°±æ¯æå¤§çç´ æ°**//
            }
        }
    }
    while(~scanf("%d",&s))
    {
        max=0;
        for(i=1;i<=s;i++)
        {
            scanf("%d",&n);
            if(a[n]>max)
            {
                max=a[n];
                p=n;
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
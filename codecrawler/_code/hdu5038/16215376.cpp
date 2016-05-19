#include "stdio.h"
#include "string.h"
int main()
{
    int Case,ii,n,x,key,ans,ans2,first,i; // keyè®°å½ç­æ¡æ°æ¯å¦å¯ä¸ï¼ans2è®°å½æ¬¡å°å¼
    int hash[10010];
    scanf("%d",&Case);
    for (ii=1;ii<=Case;ii++)
    {
        scanf("%d",&n);
        memset(hash,0,sizeof(hash));
        while (n--)
        {
            scanf("%d",&x);
            hash[10000-(100-x)*(100-x)]++;
        }
        printf("Case #%d:\n",ii);
        key=0;
        ans=0;
        ans2=0;

        for (i=0;i<=10000;i++)
        if (hash[i]>ans)
        {
            key=1;
            ans2=ans;
            ans=hash[i];
        }
        else
        if (ans==hash[i] && hash[i]!=0)
            key++;
        else
        if (hash[i]<ans && hash[i]!=0)
            ans2=hash[i];


        if (key>1 && ans2==0)
        {
            printf("Bad Mushroom\n");
            continue;
        }

        first=1;
        for (i=0;i<=10000;i++)
            if(hash[i]==ans)
        {
            if (first==0) printf(" ");
            first=0;
            printf("%d",i);
        }
        printf("\n");



    }
    return 0;
}

#include"stdio.h"
#include"string.h"
int main()
{
    int hash[10011];
    int i,l;
    int n,m;
    int num[3033];
    while(scanf("%d%d",&n,&m)!=-1)
    {
        memset(hash,0,sizeof(hash));


        if(n==0)
            continue;


        scanf("%d",&num[0]);
        for(i=1;i<n;i++)
        {
            scanf("%d",&num[i]);
            for(l=0;l<i;l++)    hash[num[i]+num[l]]++;
        }


        if(m==0)
            continue;


        for(i=10000;i>0;i--)
        {
            if(m==1)
                break;
            while(hash[i]!=0)
            {
                printf("%d ",i);
                hash[i]--;
                m--;
                if(m==1)
                    break;
            }
        }
        i+=1;
        for(;i>0;i--)
        {
            if(hash[i]!=0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
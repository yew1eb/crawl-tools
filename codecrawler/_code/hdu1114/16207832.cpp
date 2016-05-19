#include"stdio.h"
#include"string.h"
struct A
{
    int p;
    int w;
}E[555];
int main()
{
    int T;
    int n;
    int total;
    int temp1,temp2;
    int flag[10011];
    int i,l,k;


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&temp1,&temp2);
        total=temp2-temp1;


        scanf("%d",&n);
        for(i=1;i<=n;i++)    scanf("%d%d",&E[i].p,&E[i].w);


        if(total==0)
        {
            printf("0\n");
            continue;
        }


        for(i=0;i<=total;i++)    flag[i]=0;
        for(i=1;i<=n;i++)
        {
            /*****/
            //éåææk*E[i].wç
            for(k=0;k*E[i].w<=total;k++)
            {
                if(flag[k*E[i].w]==0)                flag[k*E[i].w]=k*E[i].p;
                else if(k*E[i].p<flag[k*E[i].w])    flag[k*E[i].w]=k*E[i].p;
            }
            //ä»1å¼å§ï¼å¾åè¸¢ç®çï¼ä¹å°±æ¯é¢å¤ç
            for(l=1;l+E[i].w<=total;l++)
            {
                if(flag[l]==0)    continue;
                if(flag[l+E[i].w]==0)                    flag[l+E[i].w]=flag[l]+E[i].p;
                else if(flag[l]+E[i].p<flag[l+E[i].w])    flag[l+E[i].w]=flag[l]+E[i].p;;
            }
            /*****/
        }


        if(flag[total]==0)    printf("This is impossible.\n");
        else                printf("The minimum amount of money in the piggy-bank is %d.\n",flag[total]);
    }
    return 0;
}
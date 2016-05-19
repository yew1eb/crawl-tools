#include"stdio.h"
int num[500011];
int ans[500011];
int main()
{
    int n,k=1;
    int len,low,up,mid;
    int i;
    int temp1,temp2;
    while(scanf("%d",&n)!=-1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&temp1,&temp2);
            num[temp1]=temp2;
        }


        ans[1]=num[1];
        len=1;
        for(i=2;i<=n;i++)
        {
            /*****/                   //è¿ä¸ªäºåæ¯å«äººåçï¼è¡¨ç¤ºæ¯æåçå¥½å¤äº- -Iã
            low=1;
            up=len;
            while(low<=up)
            {
                mid=(low+up)/2;
                if(ans[mid]<num[i]) low=mid+1;
                else up=mid-1;
            }
            ans[low]=num[i];
            if(low>len) len++;
            /*****/
        }


        printf("Case %d:\n",k);
        if(len==1)    printf("My king, at most 1 road can be built.");
        else    printf("My king, at most %d roads can be built.",len);
        printf("\n");
        printf("\n");
        k++;
    }
    return 0;
}
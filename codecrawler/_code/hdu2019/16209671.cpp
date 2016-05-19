#include<stdio.h>
int main()
{
    int n,m,x,i,flag,a[101];
    while(~scanf("%d %d",&n,&m)&&(n,m))
    {
        for(flag=0,i=0;i<n+1;i++)//**(n+1)å¤å­ä¸ä¸ªm**//
        {
            scanf("%d",&x);
            if(x<m||flag==1)//flagè¿è¡æ è®°ï¼é²æ­¢è¿è¡å¤æ¬¡æå¥**//
            {
                a[i]=x;
            }
            else
            {
                a[i]=m;
                a[i+1]=x;
                i++;//**è·³å¥ä¸ä¸æ¬¡å¾ªç¯**//
                flag=1;//**å ä¸ºåªéè¦æå¥ä¸æ¬¡ï¼è¿è¡æ è®°**//
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
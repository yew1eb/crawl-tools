#include<stdio.h>
#include<string.h>
#define maxn 300
int main()
{
    int s,n,i,j,k,up,str[300],str1[300],str2[300];//**å®ä¹å¤§äºåç§TLEï¼è¿éä¿®æ¹äºå¥½å æ¬¡**//
    scanf("%d",&s);
    while(s--)
    {
        memset(str,0,sizeof(str));
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        scanf("%d",&n);
        if(n==1||n==2)
        {
            printf("1\n");
            continue;
        }
        str1[0]=1;str2[0]=1;
        for(i=0;i<n-2;i++)
        {
            for(j=0;j<maxn;j++)
            {
                str[j]=str1[j]+str2[j];
            }
            for(up=0,j=0;j<maxn;j++)
            {
                str[j]=str1[j]+str2[j]+up;
                up=str[j]/10;
                str[j]=str[j]%10;
            }
            for(j=0;j<maxn;j++)
            {
                str1[j]=str2[j];
                str2[j]=str[j];
            }
        }
        for(i=maxn-1;i>=0;i--)
        {
            if(str[i]) break;
        }
        for(k=i;k>=0;k--)
        {
            printf("%d",str[k]);
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,len,j,k,t;
    char s1[1005],s2[100];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(s1);
        len=strlen(s1);
        for(i=0,j=0,t=0;i<len;i++)
        {
            if(s1[i]!=' ')
                s2[j++]=s1[i]; /*ä¿å­åè¯*/
            else
            {
                if(t>0) printf(" "); /*æ§å¶æ ¼å¼*/
                for(k=j-1;k>=0;k--) 
                    printf("%c",s2[k]); /*åè½¬è¾åº*/
                j=0;
                t++;
            }
            if(i==len-1) /*åè½¬æåä¸ä¸ªåè¯ï¼è¿éè¦ç¹å«æ³¨æ*/
            {
                printf(" ");
                for(k=j-1;k>=0;k--)
                    printf("%c",s2[k]);
            }
        }
        printf("\n");
    }
    return 0;
}
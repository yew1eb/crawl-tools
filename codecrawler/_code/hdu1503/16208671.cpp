#include"stdio.h"
#include"string.h"


int dp[111][111];
int pre[111][111];
char str1[111],str2[111];


void P(int i,int l)
{
    if(i==0&&l==0)    return ;
    if(pre[i][l]==1)        {P(i,l-1);printf("%c",str2[l]);}
    else if(pre[i][l]==3)    {P(i-1,l);printf("%c",str1[i]);}
    else                     {P(i-1,l-1);printf("%c",str1[i]);}
}


int main()
{
    int i,l;
    int len1,len2;


    while(scanf("%s%s",&str1,&str2)!=-1)
    {
        len1=strlen(str1);
        len2=strlen(str2);


        for(l=len1;l>0;l--)    str1[l]=str1[l-1];
        for(l=len2;l>0;l--)    str2[l]=str2[l-1];
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(l=0;l<=len1;l++)    pre[l][0]=3;
        for(l=0;l<=len2;l++)    pre[0][l]=1;


        for(i=1;i<=len1;i++)
        {
            for(l=1;l<=len2;l++)
            {
                if(str1[i]==str2[l])            {dp[i][l]=dp[i-1][l-1]+1;pre[i][l]=2;}
                else if(dp[i][l-1]>dp[i-1][l])    {dp[i][l]=dp[i][l-1];pre[i][l]=1;}
                else                            {dp[i][l]=dp[i-1][l];pre[i][l]=3;}
            }
        }


        P(len1,len2);
        printf("\n");
    }
    return 0;
}
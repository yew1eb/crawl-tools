#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int i,j,t,dp[110][110],flag;
    char s[110],s1[110],s2[110];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%s",s,s1,s2);
        memset(dp,0,sizeof(dp));
        flag=0;
        for(i=0;i<strlen(s);i++)
        {
            for(j=0;j<strlen(s1);j++)
            {
                if(s[i]==s1[j]||s[i]==s2[j]||s1[j]=='*')
                {
                    dp[i+1][j+1]=dp[i][j]+1;
                    if(dp[i+1][j+1]==strlen(s)){flag=1;break;}
                }
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        if(flag)
        printf("win\n");
        else printf("lose\n");
    }
    return 0;
}

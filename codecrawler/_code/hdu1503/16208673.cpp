#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[1000],s2[1000];
int len1,len2,dp[1000][1000],mark[1000][1000];

void LCS()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i = 0;i<=len1;i++)
    mark[i][0] = 1;
    for(i = 0;i<=len2;i++)
    mark[0][i] = -1;
    for(i = 1; i<=len1; i++)
    {
        for(j = 1; j<=len2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                mark[i][j] = 0;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                mark[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                mark[i][j] = -1;
            }
        }
    }
}

void PrintLCS(int i,int j)
{
    if(!i && !j)
    return ;
    if(mark[i][j]==0)
    {
        PrintLCS(i-1,j-1);
        printf("%c",s1[i-1]);
    }
    else if(mark[i][j]==1)//æ ¹æ®åæº¯çä½ç½®è¿è¡è¾åº
    {
        PrintLCS(i-1,j);
        printf("%c",s1[i-1]);
    }
    else
    {
        PrintLCS(i,j-1);
        printf("%c",s2[j-1]);
    }
}

int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        len1 = strlen(s1);
        len2 = strlen(s2);
        LCS();
        PrintLCS(len1,len2);
        printf("\n");
    }

    return 0;
}

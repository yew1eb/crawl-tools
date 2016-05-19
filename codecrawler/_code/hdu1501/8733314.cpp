#include <stdio.h>  
#include <string.h>  
char s1[201],s2[201],s3[402];  
int dp[201][201];  
int len1, len2, len3;  
int main()  
{  
    int n, k=0, i, j;  
    scanf("%d",&n);  
    while(k++<n)  
    {  
        printf("Data set %d: ",k);  
        memset(dp,0,sizeof(dp));  
        dp[0][0] = 1;  
        scanf("%s %s %s",s1,s2,s3);  
        len1 = strlen(s1);  
        len2 = strlen(s2);  
        len3 = strlen(s3);  
        if(len3 != len1 + len2)  
        {  
            printf("no\n");  
            continue;  
        }  
        for(i=0; i<=len1; ++i)  
            for(j=0; j<=len2; ++j)  
            {  
                if(i>0 && s3[i+j-1]==s1[i-1] && dp[i-1][j])  
                    dp[i][j] = 1;  
                if(j>0 && s3[i+j-1]==s2[j-1] && dp[i][j-1])  
                    dp[i][j] = 1;  
            }  
        if(dp[len1][len2]) printf("yes\n");  
        else printf("no\n");  
    }  
    return 0;  
}  
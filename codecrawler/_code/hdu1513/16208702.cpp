#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n;
int dp[2][5011];
char str[5011],str2[5011];
int len;
int get_dp()
{
    int i,l;
    int now,pre;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=len;i++)
    for(l=1;l<=len;l++)
    {
        now=i%2;
        pre=1-now;
        if(str[i-1]==str2[l-1])    dp[now][l]=dp[pre][l-1]+1;
        else                    dp[now][l]=dp[now][l-1]>dp[pre][l]?dp[now][l-1]:dp[pre][l];
    }
    return len-dp[len%2][len];
}
int main()
{
    while(scanf("%d",&n)!=-1)
    {
        scanf("%s",str);
        strcpy(str2,str);
        strrev(str2);
        len=strlen(str);
        printf("%d\n",get_dp());
    }
    return 0;
}
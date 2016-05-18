#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int n;
int dp[2][2011];
char str1[2011],str2[2011];
int len1,len2;
int val[200];
void init()
{
	int i;
	char str[2011];
	memset(val,0,sizeof(val));
	scanf("%s",str);
	for(i=0;str[i];i++)	scanf("%d",&val[str[i]]);
	scanf("%s%s",str1,str2);
	len1=strlen(str1);
	len2=strlen(str2);
}
int get_dp()
{
	int i,l;
	int pre,now;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=len1;i++)
	{
		now=i%2;
		pre=1-now;
		for(l=1;l<=len2;l++)
		{
			if(str1[i-1]==str2[l-1])	dp[now][l]=dp[pre][l-1]+val[str1[i-1]];
			else	dp[now][l]=dp[now][l-1]>dp[pre][l]?dp[now][l-1]:dp[pre][l];
		}
	}
	return dp[len1%2][len2];
}
int main()
{
	while(scanf("%d",&n)!=-1)
	{
		init();
		printf("%d\n",get_dp());
	}
	return 0;
}
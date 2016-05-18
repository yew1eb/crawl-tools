#include<stdio.h>
#include<string.h>
#define N 1000005
typedef long long LL;
char s[N];
int a[N],ln;
LL dp[N];
LL dfs(int x)
{
    if(x>=ln) return 1;
    if(dp[x]>0) return dp[x];
    if(a[x+1]!=0) dp[x]+=dfs(x+1);
	if(a[x]*10+a[x+1]<=26&&a[x+2]!=0) dp[x]+=dfs(x+2);
    return dp[x];
}
int main()
{
    while(gets(s+1))
    {
        if(s[1]=='0') break;
        ln=strlen(s+1);
		int i;
        for(i=1; i<=ln; i++) a[i]=s[i]-'0';
		a[i]=1;
        memset(dp,0,sizeof(dp));
        dp[1]=dfs(1);
        printf("%I64d\n",dp[1]);
    }
    return 0;
}
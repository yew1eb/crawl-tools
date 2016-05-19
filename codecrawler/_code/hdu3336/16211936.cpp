#include <stdio.h>

#define MOD 10007

char b[200005];
int dp[200005];
int p[200005];
int n;

int Pre()
{
    int s,i,j;
    dp[0]=1;
    j=-1;
    p[0]=-1;
    s=1;
    for (i=1;i<n;i++)
    {
        while(j>=0 && b[j+1]!=b[i]) j=p[j];
        if (b[j+1]==b[i]) j++;
        if (j>=0) dp[i]=(dp[j]+1)%MOD;
        else dp[i]=1;
        p[i]=j;
        s=(s+dp[i])%MOD;
    }
    return s;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",b);
        printf("%d\n",Pre());
    }
    return 0;
}

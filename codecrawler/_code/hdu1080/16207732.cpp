#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char a[110];
char b[110];
int dp[110][110];
int maxx(int a,int b,int c)
{
    int aa=-9999999;
    if(a>aa)
    aa=a;
    if(b>aa)
    aa=b;
    if(c>aa)
    aa=c;
    return aa;
}
int ans[5][5]={
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,
    -1,-2,-2,5,-1,
    -3,-4,-2,-1,100000};
int find(char a)
{
    if(a=='A')
    return 0;
    if(a=='C')
    return 1;
    if(a=='G')
    return 2;
    if(a=='T')
    return 3;
    if(a=='-')
    return 4;
}
int main()
{
    int t,n1,n2,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d ",&n1);
        for(int i=1;i<=n1;i++)
        {
            scanf("%c",&a[i]);
        }
        scanf("%d ",&n2);
        for(int i=1;i<=n2;i++)
        {
            scanf("%c",&b[i]);
        }
        n=max(n1,n2);
        //memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        //printf("&&%d\n",ans[find('-')][find(a[2])]);
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=dp[0][i-1]+ans[find('-')][find(b[i])];
            dp[i][0]=dp[i-1][0]+ans[find(a[i])][find('-')];
        }
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
               dp[i][j]=maxx(dp[i-1][j-1]+ans[find(a[i])][find(b[j])],dp[i-1][j]+ans[find(a[i])][find('-')],dp[i][j-1]+ans[find('-')][find(b[j])]);
            }
        }
        printf("%d\n",dp[n1][n2]);
    }
    return 0;
}
/*
2
7 AGTGATG
5 GTTAG
7 AGCTATT
9 AGCTTTAAA
*/

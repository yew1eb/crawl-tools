#include"stdio.h"
#include"string.h"


struct A
{
    int price;
    int val;
}E[111];
int max(int a,int b)
{
    return a>b?a:b;
}


int main()
{
    int n,N,kind,V;
    int dp[111][111];
    int i,l,j,k;


    while(scanf("%d%d%d%d",&n,&N,&kind,&V)!=-1)
    {
        for(i=1;i<=kind;i++)    scanf("%d%d",&E[i].val,&E[i].price);


        memset(dp,0,sizeof(dp));
        for(i=1;i<=N;i++)
        {
            for(l=1;l<=kind;l++)
            {
                for(j=1;j<=V;j++)
                {
                    k=1;
                    while(k*E[l].price<=i&&j>=k)
                    {
                        dp[i][j]=max(dp[i][j],dp[i-k*E[l].price][j-k]+k*E[l].val);
                        k++;
                    }
                }
            }
            if(dp[i][V]>=n)    break;
        }


        if(i>N)    printf("-1\n");
        else    printf("%d\n",N-i);
    }
    return 0;
}
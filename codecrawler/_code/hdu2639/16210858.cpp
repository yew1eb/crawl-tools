#include"stdio.h"
#include"string.h"
struct A
{
    int val;
    int v;
}E[111];


int main()
{
    int T;
    int N,V,K;
    int i,l,j;
    int dp[1111][33];
    int temp;
    int A[33],B[33];
    int a,b,c;
    int f1,f2;


    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&V,&K);
        for(i=1;i<=N;i++)    scanf("%d",&E[i].val);
        for(i=1;i<=N;i++)    scanf("%d",&E[i].v);


        memset(dp,0,sizeof(dp));
        for(i=1;i<=N;i++)
        {
            for(l=V;l>=E[i].v;l--)
            {
                temp=l-E[i].v;
                for(j=1;j<=K;j++)
                {
                    A[j]=dp[temp][j]+E[i].val;
                    B[j]=dp[l][j];
                    if(A[j]==E[i].val)    break;
                }
                for(j++;j<=K;j++)
                {
                    A[j]=0;
                    B[j]=dp[l][j];
                }
                a=b=c=1;
                f1=f2=0;
                while(c<=K)
                {
                    if(A[a]>B[b])    {dp[l][c]=A[a];a++;}
                    else            {dp[l][c]=B[b];b++;}
                    if(dp[l][c]==0)    break;
                    if(dp[l][c]!=dp[l][c-1])    c++;
                }
                while(c<=K)    dp[l][c++]=0;
            }
        }


        printf("%d\n",dp[V][K]);
    }


    return 0;
}
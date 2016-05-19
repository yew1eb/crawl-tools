#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
using namespace std;
const int maxn=1010;
int m,n,x,y,T;
int dp[maxn];
int map[maxn][maxn];
int main()
{
    int ans,sum;
    scanf("%d",&T);
    while(T--)
    {
        ans=-1;
        scanf("%d%d%d%d",&m,&n,&x,&y);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&map[i][j]);
        for(int i=0; i<m-x+1; i++)
        {
            memset(dp,0,sizeof(dp));
            for(int j=0; j<n; j++)
                for(int k=i; k<i+x; k++)
                    dp[j]+=map[j][k];
            for(int j=0; j<n-y+1; j++)
            {
                sum=0;
                for(int k=j; k<j+y; k++)
                {
                    sum+=dp[k];
                }
                if(sum>ans)
                    ans=sum;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}




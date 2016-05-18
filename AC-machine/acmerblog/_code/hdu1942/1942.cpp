#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[16][16][16];
int g[51][16][16][16];
int c1[51],c2[51],c3[51];
int ans[51],len;
int main()
{
    int n,r1,r2,r3;
    while(scanf("%d %d %d",&r1,&r2,&r3)==3)
    {
        if(r1==0 && r2==0 && r3==0)
            break;
        len=0;
        memset(dp,0,sizeof(dp));
        memset(g,0,sizeof(g));
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d %d %d",&c1[i],&c2[i],&c3[i]);
        for(int i=1; i<=n; i++)
            for(int t1=r1; t1>=0; t1--)
                for(int t2=r2; t2>=0; t2--)
                    for(int t3=r3; t3>=0; t3--)
                        if(t1-c1[i]>=0 && t2-c2[i]>=0 && t3-c3[i]>=0)
                        {
                            dp[t1][t2][t3]=dp[t1][t2][t3];
                            if(dp[t1-c1[i]][t2-c2[i]][t3-c3[i]]+1>dp[t1][t2][t3])
                            {
                                dp[t1][t2][t3]=dp[t1-c1[i]][t2-c2[i]][t3-c3[i]]+1;
                                g[i][t1][t2][t3]=true;
                            }
                        }
        if(dp[r1][r2][r3])
        {
            printf("%d\n",dp[r1][r2][r3]);
            while(n!=0)
            {
                if(g[n][r1][r2][r3])
                {
                    ans[len++]=n;
                    r1-=c1[n];
                    r2-=c2[n];
                    r3-=c3[n];
                }
                n--;
            }
            sort(ans,ans+len);
            for(int i=0; i<len; i++)
            {
                if(i)
                    printf(" ");
                printf("%d",ans[i]);
            }
            printf("\n");
        }
        else
            printf("0\n");
    }
    return 0;
}
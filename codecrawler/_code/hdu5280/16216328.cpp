#include<stdio.h>
const int N = 1005;
const int inf = 1<<29;
int main(){
    __int64 dp[N],P,a[N],ans;
    int n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%I64d",&n,&P);
        for(int i=1; i<=n; i++)
            scanf("%I64d",&a[i]);

        ans=-inf;
        dp[0]=0;

        for(int i=1; i<=n; i++)
        {
            int tmp=a[i];
            a[i]=P;
            for(int j=1; j<=n; j++)
            {
                if(dp[j-1]>0)
                    dp[j]=dp[j-1]+a[j];
                else
                    dp[j]=a[j];
                if(dp[j]>ans)
                    ans=dp[j];
            }
            a[i]=tmp;
        }
        printf("%I64d\n",ans);
    }
}

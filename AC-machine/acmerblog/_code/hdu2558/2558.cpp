#include <stdio.h>
#include <cstring>
int a[101][101],sum[101][101];
int f[101];
int main()
{
    int n,t,ans,max;
    while(scanf("%d",&n)==1)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%d",&a[i][j]);
        memset(f,0,sizeof(f));
        memset(sum,0,sizeof(sum));
        ans=0,max=-1000000000;
        int temp;
        for(int i=1; i<=n; i++)
        {
            temp=0;
            for(int j=1; j<=n; j++)
                temp+=a[i][j],sum[i][j]=temp;
        }
        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j++)
            {
                ans=0;
                for(int k=1; k<=n; k++)
                {
                    t=sum[k][j]-sum[k][i-1];
                    if(ans>0) ans+=t;
                    else ans=t;
                    if(ans>max) max=ans;
                }
            }
        printf("%d\n",max);
    }
    return 0;
}
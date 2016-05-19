#include<cstdio>
#include<cstring>
#define MOD 1000000007
int a[2005];
int f[2005][2005];

int solve(int n,int sum)
{
    if(n==1) return 1;
    for(int i=0;i<=a[1];i++)
        f[1][i]=1;


    for(int i=2;i<=n;i++)
        for(int j=0;j<=sum;j++)
            for(int k=0;j+k<=sum && k<=a[i];k++)
                f[i][j+k]=(f[i][j+k]+f[i-1][j])%MOD;

    return f[n][sum];
}

int main()
{
    int sum,T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum=0;
        for(int i=1;i<=n;i++)
            {
                scanf("%d",&a[i]);
                sum+=a[i];
            }
        sum/=2;

        memset(f,0,sizeof(f));
        int ans=solve(n,sum);
        printf("%d\n",ans);
    }



    return 0;
}

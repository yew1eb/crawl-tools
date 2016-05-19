#define MOD 1000003
#define N 1123

int n,m;
int flag,res;
long long sum,ans,t;
long long a[N],b[N];
long long f[N][N],c[N][N];

void init()
{
    memset(f,0,sizeof(f));
    for(int i=0;i<N;i++)
        f[i][0]=f[i][i]=1;
    for(int i=1;i<N;i++)
        for(int j=1;j<i;j++)
            f[i][j] = (f[i-1][j]+f[i-1][j-1])%MOD;
}
int main()
{
    int i,j,k;
    init();
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(b,0,sizeof(b));
        res=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&t);
            j=0;
            while(t)
            {
                if(t&1)
                    b[j]++;
                j++;
                t>>=1;
            }
        }
        for(k=1;k<=n;k++)
        {
            sum = 0;
            t = 1;
            for(i=0;i<32;i++)
            {
                ans=0;
                for(j=1;j<=k;j+=2)
                    ans=(ans+(f[b[i]][j]*f[n-b[i]][k-j])%MOD)%MOD;
                sum=(sum+ans*t%MOD)%MOD;
                t*=2;
            }
            if(k!=1)printf(" ");
            printf("%lld",sum);
        }
        printf("\n");
    }
    return 0;
}
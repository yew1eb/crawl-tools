double f[N][N];
int a[N],b[N],n,m;

double up(double &x,double y)
{
    if(x<y) x=y;
}

void DP()
{
    int i,j,k;
    FOR1(i,n) FOR0(j,m+1) f[i][j]=-inf;
    double temp;
    for(i=0;i*a[1]<=m;i++) f[1][i*a[1]]=b[1]*i-4.9*i*i;
    for(i=2;i<n;i++) for(j=0;j<=m;j++) for(k=0;k*a[i]+j<=m;k++)
    {
        temp=f[i-1][j]+b[i]*k-4.9*k*k;
        up(f[i][k*a[i]+j],temp);
    }
}

double cal()
{

    if(n==1) return b[1]*(1.0*m/a[1])-4.9*sqr(1.0*m/a[1]);


    int i,j,k;
    double ans=-inf,temp,t;
    FOR1(i,n)
    {
        swap(a[i],a[n]); swap(b[i],b[n]);
        DP();
        for(j=0;j<=m;j++)
        {
            t=1.0*j/a[n];
            temp=f[n-1][m-j]+b[n]*t-4.9*t*t;
            up(ans,temp);
        }
        swap(a[i],a[n]); swap(b[i],b[n]);
    }
    return ans;
}

int main()
{
    int num=0;
    rush()
    {
        RD(n,m);
        int i;
        FOR1(i,n) RD(a[i],b[i]);
        printf("Case %d: ",++num);
        PR(cal());
    }
}

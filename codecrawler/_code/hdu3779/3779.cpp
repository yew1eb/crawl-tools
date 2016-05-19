#include<stdio.h>
int a[1005],b[1005],c[2005];
int p[1005][1005];
int n,m;
int ok;
int t;
void f(int t1,int t2,int tt)
{
    int i;
    if(ok) return;
    if (p[t1][t2]==1) return;
    if(tt==n+m)
    {
        ok=1; return;
    }
    if(t1<n && a[t1]==c[tt])
    {
        f(t1+1, t2, tt+1);
    }
    if(t2<m && b[t2]==c[tt])
    {
        f(t1,t2+1,tt+1);
    }
    p[t1][t2]=1;
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0) break;
        for(i=0; i<n; i++) scanf("%d",&a[i]);
        for(i=0; i<m; i++) scanf("%d",&b[i]);
        for(i=0; i<n+m; i++) scanf("%d",&c[i]);
        ok=0;
        for (i=0;i<=n;i++)
        {
            for (j=0;j<=m;j++)
            {
                p[i][j]=0;
            }
        }
        f(0,0,0);
        if(ok==1)
            printf("possible/n");
        else
            printf("not possible/n");
    }
    return 0;
}
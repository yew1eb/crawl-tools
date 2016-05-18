#include<stdio.h>
#include<string.h>
#define N 505
int main()
{
    int n,m;
    int a[N],b[N],f[N];
    int i,j,k;
    int ans;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d",&a[i]);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        memset(f,0,sizeof(f));
        for(i=1;i<=m;i++)
        {
            k=0;
            for(j=1;j<=n;j++)
            {
                if(b[j]<a[i]&&f[j]>f[k])
                    k=j;
                if(b[j]==a[i])
                    f[j]=f[k]+1;
            }
        }
        ans=0;
        for(i=0;i<=n;i++)
        {
            if(ans<f[i])
                ans=f[i];
        }
        printf("%d\n",ans);
        if(T!=0)
            printf("\n");
    }
    return 0;
}
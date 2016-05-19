#include<stdio.h>
#include<string.h>
#define M 1005
int a[M][M],l[M],r[M];
int main()
{
    int t,i,j,res,ans,n,m;
    char str[10];
    scanf("%d",&t);
    while(t--&&scanf("%d %d",&n,&m))
    {
        memset(a[0],0,sizeof(a[0]));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%s",str);
                if(str[0]=='F')
                    a[i][j]=a[i-1][j]+1;
                else a[i][j]=0;
            }
        ans=-1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                l[j]=r[j]=j;
            a[i][0]=a[i][m+1]=-1;
            for(j=2;j<=m;j++)
            {
                while(a[i][j]<=a[i][l[j]-1])
                    l[j]=l[l[j]-1];
            }
            for(j=m-1;j>=1;j--)
            {
                while(a[i][j]<=a[i][r[j]+1])
                    r[j]=r[r[j]+1];
            }
            for(j=1;j<=m;j++)
            {
                res=a[i][j]*(r[j]-l[j]+1);
                if(res>ans)
                    ans=res;
            }
        }
        printf("%d\n",ans*3);
    }
    return 0;
}
